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

    /* In-app debug log overlay. Tap the small 'LOG' badge bottom-right
     * to toggle. Useful for diagnosing the touchscreen plugin without
     * needing ADB/logcat.
     *
     * The overlay is reparented to mobileui.parent at component load so it
     * floats ABOVE the entire window and never participates in the
     * GridLayout (otherwise it stole a cell and pushed the keypad away,
     * leaving a white gap behind it). */
    Item {
        id: debugOverlay
        z: 100

        /* Don't reserve any cell in the parent GridLayout. */
        Layout.preferredWidth: 0
        Layout.preferredHeight: 0
        Layout.maximumWidth: 0
        Layout.maximumHeight: 0

        /* Pop out of the GridLayout once we know the window root. */
        Component.onCompleted: {
            if (mobileui.parent) {
                debugOverlay.parent = mobileui.parent;
                debugOverlay.anchors.fill = mobileui.parent;
            } else {
                debugOverlay.anchors.fill = mobileui;
            }
        }

        property bool open: false

        Rectangle {
            id: logBadge
            width: 88; height: 44
            color: "#cc222222"
            border.color: "#aaffffff"
            border.width: 1
            radius: 6
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            anchors.margins: 16

            Text {
                anchors.centerIn: parent
                text: debugOverlay.open ? "HIDE" : "LOG"
                color: "white"
                font.pixelSize: 16
                font.bold: true
            }

            MouseArea {
                anchors.fill: parent
                onClicked: debugOverlay.open = !debugOverlay.open
            }
        }

        Rectangle {
            id: logPanel
            visible: debugOverlay.open
            enabled: debugOverlay.open
            color: "#ee000000"
            border.color: "#aaffffff"
            border.width: 1
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: logBadge.top
            anchors.margins: 12
            height: parent.height * 0.45

            Flickable {
                id: logFlick
                anchors.fill: parent
                anchors.margins: 8
                anchors.bottomMargin: 52
                contentWidth: width
                contentHeight: logText.implicitHeight
                clip: true

                TextEdit {
                    id: logText
                    width: logFlick.width
                    text: Emu.debugLog
                    color: "#dddddd"
                    font.family: "Monospace"
                    font.pixelSize: 11
                    wrapMode: TextEdit.Wrap
                    textFormat: TextEdit.PlainText
                    readOnly: true
                    selectByMouse: true
                    persistentSelection: true
                    onTextChanged: {
                        // Auto-scroll to bottom on new lines
                        logFlick.contentY = Math.max(0, logText.implicitHeight - logFlick.height);
                    }
                }
            }

            Row {
                anchors.right: parent.right
                anchors.bottom: parent.bottom
                anchors.margins: 8
                spacing: 8

                Rectangle {
                    width: 84; height: 36
                    color: "#444"; radius: 5
                    Text { anchors.centerIn: parent; text: "Clear"; color: "white"; font.pixelSize: 14 }
                    MouseArea { anchors.fill: parent; onClicked: Emu.clearDebugLog() }
                }
                Rectangle {
                    width: 84; height: 36
                    color: "#444"; radius: 5
                    Text { anchors.centerIn: parent; text: "Copy"; color: "white"; font.pixelSize: 14 }
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            logText.selectAll();
                            logText.copy();
                            logText.deselect();
                        }
                    }
                }
            }
        }
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
