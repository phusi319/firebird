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
        // PRIMARY PATH (when fb_touchscreen.tns is installed inside the
        // emulated Nspire OS): tap -> Emu.absoluteTap(nx, ny, action) writes
        // a request into the touchscreen mailbox in emulated SDRAM. The
        // in-OS plugin polls the mailbox and calls send_click_event(x, y),
        // the same OS function TI's PC Teacher Software invokes via JNI.
        // Click registers exactly at the tap coordinate, instantly.
        //
        // FALLBACK PATH (no plugin): we drive the emulated touchpad in
        // 3 phases (press -> +120ms click -> +60ms release). Cursor still
        // walks toward the tap location like a relative trackpad. This is
        // how every other Nspire emulator behaves.
        //
        // Drag tracks the finger. Swipe-right opens the drawer.
        // All coords normalized 0..1 (DPI-independent).
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
            property bool absoluteMode: false   // resolved on press
            // DPI-independent thresholds (% of screen width)
            property real swipeThreshold: mobileui.width * 0.08
            property real tapThreshold:   mobileui.width * 0.02

            // ---- fallback (relative touchpad) timers ----
            Timer {
                id: clickDownTimer
                interval: 120
                repeat: false
                onTriggered: Emu.setTouchpadState(swipeArea.lastNX, swipeArea.lastNY, true, true)
            }
            Timer {
                id: clickUpTimer
                interval: 180
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
                // Pick path based on whether plugin is loaded inside the OS.
                absoluteMode = Emu.touchscreenPluginReady();
                if (absoluteMode) {
                    lastNX = Math.max(0, Math.min(1, mouse.x / width));
                    lastNY = Math.max(0, Math.min(1, mouse.y / height));
                    Emu.absoluteTap(lastNX, lastNY, 1); // press
                } else {
                    // Fallback: feed touchpad as before
                    sendContact(mouse.x / width, mouse.y / height);
                }
            }
            onPositionChanged: {
                var dx = mouse.x - startX;
                var dy = mouse.y - startY;
                var adx = Math.abs(dx);
                var ady = Math.abs(dy);

                if (!drawerOpened && dx > swipeThreshold && adx > ady * 1.5) {
                    drawerOpened = true;
                    clickDownTimer.stop();
                    clickUpTimer.stop();
                    if (absoluteMode)
                        Emu.absoluteTap(lastNX, lastNY, 2); // release
                    else
                        Emu.setTouchpadState(lastNX, lastNY, false, false);
                    listView.openDrawer();
                    return;
                }
                if (drawerOpened) return;

                if (adx > tapThreshold || ady > tapThreshold)
                    dragging = true;

                lastNX = Math.max(0, Math.min(1, mouse.x / width));
                lastNY = Math.max(0, Math.min(1, mouse.y / height));
                if (absoluteMode) {
                    // Drag: treat each move as press at new coord (drag-select).
                    Emu.absoluteTap(lastNX, lastNY, 1);
                } else {
                    sendContact(mouse.x / width, mouse.y / height);
                }
            }
            onReleased: {
                if (drawerOpened) return;

                if (absoluteMode) {
                    // Tap: send a single click action at the release coord.
                    // (Drag finishes with a release at the last position.)
                    lastNX = Math.max(0, Math.min(1, mouse.x / width));
                    lastNY = Math.max(0, Math.min(1, mouse.y / height));
                    Emu.absoluteTap(lastNX, lastNY, dragging ? 2 : 3);
                    return;
                }

                // Fallback path
                if (dragging) {
                    Emu.setTouchpadState(lastNX, lastNY, false, false);
                    return;
                }
                lastNX = Math.max(0, Math.min(1, mouse.x / width));
                lastNY = Math.max(0, Math.min(1, mouse.y / height));
                clickDownTimer.restart();
                clickUpTimer.restart();
            }
            onCanceled: {
                clickDownTimer.stop();
                clickUpTimer.stop();
                if (absoluteMode)
                    Emu.absoluteTap(lastNX, lastNY, 2);
                else
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
