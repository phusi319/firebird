import Firebird.Emu 1.0
import Firebird.UIComponents 1.0

import QtQuick 2.0
import QtQuick.Layouts 1.0

GridLayout {
    id: mobileui

    // For previewing just this component
    width: 600
    height: 800

    columns: 2
    columnSpacing: 0
    rowSpacing: 0

    VerticalSwipeBar {
        id: swipeBar
        visible: false
        Layout.preferredHeight: 0
        Layout.preferredWidth: 0

        onClicked: listView.openDrawer()
    }

    EmuScreen {
        id: screen
        implicitHeight: mobileui.width / 320 * 240
        Layout.fillWidth: true
        Layout.columnSpan: 2

        focus: true

        Timer {
            interval: 35
            running: true
            repeat: true
            onTriggered: screen.update()
        }

        // Touch handler over the emulated screen.
        // Two responsibilities, mutually exclusive within a single press:
        //   1. Detect a horizontal swipe-right -> open drawer (suppresses touchpad).
        //   2. Otherwise, forward the touch as absolute touchpad input
        //      (tap/hold/drag), feeding Emu.setTouchpadState the same way
        //      qml/Touchpad.qml does for the virtual touchpad widget.
        MouseArea {
            id: swipeArea
            anchors.fill: parent
            acceptedButtons: Qt.LeftButton
            preventStealing: true

            property real startX: 0
            property real startY: 0
            property bool swiped: false
            property bool isDown: false

            function submitState() {
                // While a swipe is in progress, release the touchpad so the
                // OS doesn't see a stray drag/click.
                if (swiped)
                    Emu.setTouchpadState(0, 0, false, false);
                else
                    Emu.setTouchpadState(mouseX / width, mouseY / height,
                                        pressed || isDown, isDown);
            }

            // Press-and-hold (>= 200 ms) -> button-down (drag).
            Timer {
                id: clickOnHoldTimer
                interval: 200
                onTriggered: {
                    swipeArea.isDown = true;
                    swipeArea.submitState();
                }
            }
            // Quick-tap completion: emit a brief down pulse on release.
            Timer {
                id: clickOnReleaseTimer
                interval: 100
                onTriggered: {
                    swipeArea.isDown = false;
                    swipeArea.submitState();
                }
            }

            onPressed: {
                startX = mouse.x;
                startY = mouse.y;
                swiped = false;
                isDown = false;
                clickOnHoldTimer.restart();
                submitState();
            }

            onMouseXChanged: {
                if (!swiped) {
                    var dx = mouseX - startX;
                    var dy = mouseY - startY;
                    // horizontal swipe right, dominant over vertical,
                    // threshold = 8% of screen width (DPI-independent).
                    if (dx > mobileui.width * 0.08
                        && Math.abs(dx) > Math.abs(dy) * 1.5) {
                        swiped = true;
                        clickOnHoldTimer.stop();
                    }
                }
                submitState();
            }
            onMouseYChanged: submitState()

            onReleased: {
                if (swiped) {
                    Emu.setTouchpadState(0, 0, false, false);
                    listView.openDrawer();
                    return;
                }
                if (clickOnHoldTimer.running) {
                    // Quick tap: never reached hold threshold.
                    clickOnHoldTimer.stop();
                    isDown = true;
                    clickOnReleaseTimer.restart();
                } else {
                    // Long press: was already down; release now.
                    isDown = false;
                }
                submitState();
            }
        }
    }

    Flickable {
        id: controls

        Layout.fillHeight: true
        Layout.fillWidth: true
        Layout.preferredHeight: contentHeight
        Layout.maximumHeight: contentHeight
        Layout.columnSpan: 2

        boundsBehavior: Flickable.StopAtBounds
        flickableDirection: Flickable.VerticalFlick

        contentWidth: parent.width
        contentHeight: keypad.height*controls.width/keypad.width + iosmargin.height
        clip: true
        pixelAligned: true

        Keypad {
            id: keypad
            transform: Scale { origin.x: 0; origin.y: 0; xScale: controls.width/keypad.width; yScale: controls.width/keypad.width }
        }

        Rectangle {
            id: iosmargin
            color: keypad.color

            anchors {
                left: parent.left
                right: parent.right
                bottom: parent.bottom
            }

            // This is needed to avoid opening the control center
            height: Qt.platform.os === "ios" ? 20 : 0
        }
    }

    Rectangle {
        Layout.fillHeight: true
        Layout.fillWidth: true
        Layout.columnSpan: 2
        color: keypad.color
    }

    states: [ State {
        name: "tabletMode"
        when: mobileui.width > mobileui.height

        PropertyChanges {
            target: mobileui
            columns: 3
            layoutDirection: Emu.leftHanded ? Qt.RightToLeft : Qt.LeftToRight
        }

        PropertyChanges {
            target: swipeBar
            visible: false
        }

        /* Keypad fills right side, as wide as needed */
        PropertyChanges {
            target: controls
            Layout.minimumWidth: Math.floor(keypad.width/keypad.height * (mobileui.height - iosmargin.height))
            Layout.maximumWidth: Layout.minimumWidth
            Layout.fillHeight: true
            Layout.columnSpan: 1
        }

        /* Screen centered on the remaining space on the left */
        PropertyChanges {
            target: screen
            Layout.fillHeight: true
            Layout.fillWidth: true
        }
    }]
}
