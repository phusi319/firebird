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

        // Touchscreen mode: ABSOLUTE tap-to-click on the LCD.
        //
        // The TI-Nspire CX touchpad supports absolute mode: when a finger
        // contacts the pad at (px,py), the OS moves the on-screen cursor
        // toward the corresponding screen coordinate over a few I2C polls,
        // then registers a click only when the pad's click switch is pressed.
        //
        // To get "click exactly at tap location" (same effect as TI's PC
        // Teacher Software), we drive that protocol in 3 phases:
        //   1) press   -> contact=true,  down=false  (finger lands, cursor moves)
        //   2) +120ms  -> contact=true,  down=true   (click registers at new cursor pos)
        //   3) +60ms   -> contact=false, down=false  (lift)
        //
        // Drag tracks the finger (cursor follows). Swipe-right opens drawer.
        // All coordinates normalized to 0..1 (DPI-independent).
        MouseArea {
            id: swipeArea
            anchors.fill: parent
            preventStealing: true

            property real startX: 0
            property real startY: 0
            property real lastNX: 0
            property real lastNY: 0
            property bool dragging: false
            property bool drawerOpened: false
            // DPI-independent thresholds (% of screen width)
            property real swipeThreshold: mobileui.width * 0.08
            property real tapThreshold:   mobileui.width * 0.02

            // Phase-2: register the click after cursor has settled at absolute coord
            Timer {
                id: clickDownTimer
                interval: 120
                repeat: false
                onTriggered: Emu.setTouchpadState(swipeArea.lastNX, swipeArea.lastNY, true, true)
            }
            // Phase-3: lift finger
            Timer {
                id: clickUpTimer
                interval: 180   // = 120 + 60
                repeat: false
                onTriggered: Emu.setTouchpadState(swipeArea.lastNX, swipeArea.lastNY, false, false)
            }

            function sendContact(nx, ny) {
                lastNX = Math.max(0, Math.min(1, nx));
                lastNY = Math.max(0, Math.min(1, ny));
                Emu.setTouchpadState(lastNX, lastNY, true, false);
            }

            onPressed: {
                startX = mouse.x;
                startY = mouse.y;
                dragging = false;
                drawerOpened = false;
                clickDownTimer.stop();
                clickUpTimer.stop();
                // Phase 1: finger lands at absolute pad coord
                sendContact(mouse.x / width, mouse.y / height);
            }
            onPositionChanged: {
                var dx = mouse.x - startX;
                var dy = mouse.y - startY;
                var adx = Math.abs(dx);
                var ady = Math.abs(dy);

                // Detect swipe-right -> open drawer once
                if (!drawerOpened && dx > swipeThreshold && adx > ady * 1.5) {
                    drawerOpened = true;
                    // cancel any pending click and lift finger
                    clickDownTimer.stop();
                    clickUpTimer.stop();
                    Emu.setTouchpadState(lastNX, lastNY, false, false);
                    listView.openDrawer();
                    return;
                }
                if (drawerOpened) return;

                // If the finger moves beyond tap threshold, treat as drag:
                // keep cursor following finger, but do NOT auto-click on release.
                if (adx > tapThreshold || ady > tapThreshold)
                    dragging = true;

                sendContact(mouse.x / width, mouse.y / height);
            }
            onReleased: {
                if (drawerOpened) return;

                if (dragging) {
                    // Drag without swipe -> just lift (cursor stays where dragged)
                    Emu.setTouchpadState(lastNX, lastNY, false, false);
                    return;
                }

                // Tap: schedule click+release at the tap coords
                lastNX = Math.max(0, Math.min(1, mouse.x / width));
                lastNY = Math.max(0, Math.min(1, mouse.y / height));
                clickDownTimer.restart();
                clickUpTimer.restart();
            }
            onCanceled: {
                clickDownTimer.stop();
                clickUpTimer.stop();
                Emu.setTouchpadState(lastNX, lastNY, false, false);
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
