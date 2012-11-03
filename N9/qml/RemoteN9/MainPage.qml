import QtQuick 1.1
import com.nokia.meego 1.0
import RemoteN9 1.0

Page {
    tools: commonTools

    property int buttonMargins: 20
    property int buttonWidth: width / 3 - 2 * buttonMargins

    BroadcastSocket {
        id: sock
    }

    WlanConnectionIndicator {
        id: wlan
    }

    Rectangle {
        width: 400
        height: 300
        color: wlan.hasConnection ? 'green' : 'red'
    }

    Button {
        id: rew
        text: "<<"
        width: buttonWidth
        anchors.margins: buttonMargins
        onClicked: sock.broadcast("00000000e0e0a25d 00 rew samsung\n")
    }
    Button {
        id: pause
        anchors.left: rew.right
        text: "| |"
        width: buttonWidth
        anchors.margins: buttonMargins
        onClicked: sock.broadcast("00000000e0e052ad 00 pause samsung\n")
    }
    Button {
        anchors.left: pause.right
        text: ">>"
        width: buttonWidth
        anchors.margins: buttonMargins
        onClicked: sock.broadcast("00000000e0e012ed 00 fwd samsung\n")
    }
    Button {
        id: rec
        anchors.left: rew.left
        anchors.top: rew.bottom
        text: "●"
        width: buttonWidth
        anchors.margins: buttonMargins
        onClicked: sock.broadcast("00000000e0e0926d 00 rec samsung\n")
    }
    Button {
        id: play
        anchors.left: rec.right
        anchors.top: rew.bottom
        text: ">"
        width: buttonWidth
        anchors.margins: buttonMargins
        onClicked: sock.broadcast("00000000e0e0e21d 00 play samsung\n")
    }
    Button {
        id: stop
        anchors.left: play.right
        anchors.top: rew.bottom
        text: "■"
        width: buttonWidth
        anchors.margins: buttonMargins
        onClicked: sock.broadcast("00000000e0e0629d 00 stop samsung\n")
    }
}
