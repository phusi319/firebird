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
        //   1. Detect a horizontal swipe-right -> open drawer.
        //   2. Otherwise, treat as ABSOLUTE touchscreen tap: cursor
        //      teleports to the touched point and clicks (the firebird
        //      core state machine drives rel_x/y deltas to converge).
        MouseArea {
            id: swipeArea
            anchors.fill: parent
            acceptedButtons: Qt.LeftButton
            preventStealing: true

            property real startX: 0
            property real startY: 0
            property bool swiped: false
            property bool committed: false  // tap has been sent to core

            function submitTap() {
                if (swiped || !committed)
                    return;
                Emu.setTouchscreenTap(mouseX / width, mouseY / height,
                                      true, true);
            }

            // Defer the actual tap a few ms so a fast swipe-right can
            // cancel before any cursor motion is generated.
            Timer {
                id: commitTimer
                interval: 40
                onTriggered: {
                    if (swipeArea.swiped)
                        return;
                    swipeArea.committed = true;
                    swipeArea.submitTap();
                }
            }

            onPressed: {
                startX = mouse.x;
                startY = mouse.y;
                swiped = false;
                committed = false;
                commitTimer.restart();
            }

            onMouseXChanged: {
                if (!swiped && !committed) {
                    var dx = mouseX - startX;
                    var dy = mouseY - startY;
                    if (dx > mobileui.width * 0.08
                        && Math.abs(dx) > Math.abs(dy) * 1.5) {
                        swiped = true;
                        commitTimer.stop();
                        return;
                    }
                }
                submitTap();
            }
            onMouseYChanged: submitTap()

            onReleased: {
                commitTimer.stop();
                if (swiped) {
                    Emu.setTouchscreenTap(0, 0, false, false);
                    listView.openDrawer();
                    return;
                }
                if (!committed) {
                    // Very fast tap that ended before commit timer fired:
                    // commit and release immediately.
                    Emu.setTouchscreenTap(mouseX / width, mouseY / height,
                                          true, true);
                }
                Emu.setTouchscreenTap(0, 0, false, false);
                committed = false;
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
