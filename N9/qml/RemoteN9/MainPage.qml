import QtQuick 1.1
import com.nokia.meego 1.0
import RemoteN9 1.0

Page {
    tools: commonTools
    orientationLock: PageOrientation.LockPortrait

    property int buttonMargins: 20
    property int buttonWidth: (width - 4*buttonMargins) / 3

    BroadcastSocket {
        id: sock
    }

    WlanConnectionIndicator {
        id: wlan
    }


    Rectangle {
        anchors.fill: parent
        color: wlan.hasConnection ? 'green' : 'red'

        RemoteButton {
            id: rew
            buttonCommand: "rew"
            text: "<<"
            anchors.left: parent.left
            anchors.top: parent.top
        }
        RemoteButton {
            id: pause
            buttonCommand: "pause"
            text: "| |"
            anchors.left: rew.right
            anchors.top: parent.top
        }
        RemoteButton {
            id: fwd
            buttonCommand: "fwd"
            text: ">>"
            anchors.left: pause.right
            anchors.top: parent.top
        }

        RemoteButton {
            id: rec
            buttonCommand: "rec"
            anchors.left: parent.left
            anchors.top: rew.bottom
            text: "●"
        }
        RemoteButton {
            id: play
            buttonCommand: "play"
            anchors.left: rec.right
            anchors.top: rew.bottom
            text: ">"
        }
        RemoteButton {
            id: stop
            buttonCommand: "stop"
            anchors.left: play.right
            anchors.top: rew.bottom
            text: "■"
        }

        RemoteButton {
            id: volup
            buttonCommand: 'volup'
            anchors.top: stop.bottom
            anchors.left: parent.left
            text: 'vol+'
        }
        RemoteButton {
            id: voldn
            buttonCommand: 'voldn'
            anchors.top: volup.bottom
            anchors.left: parent.left
            text: 'vol-'
        }
    }
}
