import QtQuick 2.3
import QtQuick.Window 2.2

Window {
    id: win
    visible: true
    title: "QWERTY Keypad Preview"
    width: 600
    height: 780

    Rectangle {
        anchors.fill: parent
        color: "#222"
    }

    Keypad {
        id: kp
        x: 20
        y: 20
    }
}
