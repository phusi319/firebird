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

        // Touchscreen mode: tap/drag the LCD to control Nspire touchpad cursor.
        // Coordinates are normalized (0..1) so behavior is DPI-independent.
        // Swipe-right to open drawer is preserved (detected at release).
        MouseArea {
            id: swipeArea
            anchors.fill: parent
            preventStealing: true

            property real startX: 0
            property real startY: 0
            // DPI-independent thresholds (% of screen width)
            property real swipeThreshold: mobileui.width * 0.08
            property real dragThreshold:  mobileui.width * 0.02

            function emitTouch(mx, my, down) {
                // Clamp normalized coords to [0,1]
                var nx = Math.max(0, Math.min(1, mx / width));
                var ny = Math.max(0, Math.min(1, my / height));
                Emu.setTouchpadState(nx, ny, down, down);
            }

            onPressed: {
                startX = mouse.x;
                startY = mouse.y;
                emitTouch(mouse.x, mouse.y, true);
            }
            onPositionChanged: {
                if (pressed)
                    emitTouch(mouse.x, mouse.y, true);
            }
            onReleased: {
                // Always release touchpad
                emitTouch(mouse.x, mouse.y, false);

                var dx = mouse.x - startX;
                var dy = mouse.y - startY;
                // horizontal swipe right, dominant over vertical, DPI-independent threshold
                if (dx > swipeThreshold && Math.abs(dx) > Math.abs(dy) * 1.5) {
                    listView.openDrawer();
                }
            }
            onCanceled: {
                // No mouse parameter on canceled; release at last known point
                emitTouch(startX, startY, false);
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
