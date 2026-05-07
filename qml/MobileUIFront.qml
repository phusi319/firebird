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

        // Touchscreen mode: TAP on the LCD to click at that position.
        // - Tap (small movement) -> emit one touchpad down+up at tap coords
        // - Drag/swipe-right     -> open drawer (no cursor movement)
        // Coordinates are normalized (0..1) so behavior is DPI-independent.
        MouseArea {
            id: swipeArea
            anchors.fill: parent
            preventStealing: true

            property real startX: 0
            property real startY: 0
            // DPI-independent thresholds (% of screen width)
            property real swipeThreshold: mobileui.width * 0.08
            property real tapThreshold:   mobileui.width * 0.02

            // Quick release timer to make the tap a clean click (down then up)
            Timer {
                id: tapReleaseTimer
                interval: 80
                repeat: false
                property real px: 0
                property real py: 0
                onTriggered: Emu.setTouchpadState(px, py, false, false)
            }

            onPressed: {
                startX = mouse.x;
                startY = mouse.y;
            }
            onReleased: {
                var dx = mouse.x - startX;
                var dy = mouse.y - startY;
                var adx = Math.abs(dx);
                var ady = Math.abs(dy);

                // Swipe-right -> open drawer
                if (dx > swipeThreshold && adx > ady * 1.5) {
                    listView.openDrawer();
                    return;
                }

                // Tap (small movement) -> click at tap coords
                if (adx <= tapThreshold && ady <= tapThreshold) {
                    var nx = Math.max(0, Math.min(1, mouse.x / width));
                    var ny = Math.max(0, Math.min(1, mouse.y / height));
                    Emu.setTouchpadState(nx, ny, true, true);
                    tapReleaseTimer.px = nx;
                    tapReleaseTimer.py = ny;
                    tapReleaseTimer.restart();
                }
                // else: drag without swipe-right -> ignore (no cursor movement)
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
