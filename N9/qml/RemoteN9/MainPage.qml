import QtQuick 1.1
import com.nokia.meego 1.0
import com.nokia.extras 1.0
import RemoteN9 1.0

Page {
    orientationLock: PageOrientation.LockPortrait

    property int buttonMargins: 20
    property int buttonWidth: (width - 4*buttonMargins) / 3

    BroadcastSocket {
        id: sock
    }

    WlanConnectionIndicator {
        id: wlan
    }

    InfoBanner {
        id: banner
        text: "No WiFi connection"
        z: 10
    }

    Rectangle {
        anchors.fill: parent
        color: 'black'

        RemoteButton {
            id: onoff
            buttonCommand: "on/off"
            anchors {
                left: parent.left
                top: parent.top
            }
            Image {
                source: "on_off.png"
                fillMode: Image.PreserveAspectFit
                anchors {
                    fill: parent
                    margins: 4
                }
            }
        }

        RemoteButton {
            id: rew
            buttonCommand: "rew"
            anchors {
                left: parent.left
                top: onoff.bottom
            }
            Image {
                source: "rew.png"
                fillMode: Image.PreserveAspectFit
                anchors {
                    fill: parent
                    margins: 10
                }
            }
        }

        RemoteButton {
            id: pause
            buttonCommand: "pause"
            text: "| |"
            anchors.left: rew.right
            anchors.top: onoff.bottom
        }

        RemoteButton {
            id: fwd
            buttonCommand: "fwd"
            anchors {
                left: pause.right
                top: onoff.bottom
            }
            Image {
                source: "rew.png"
                fillMode: Image.PreserveAspectFit
                anchors {
                    fill: parent
                    margins: 10
                }
                rotation: 180
            }
        }

        RemoteButton {
            id: rec
            buttonCommand: "rec"
            anchors {
                left: parent.left
                top: rew.bottom
            }
            Image {
                source: "rec.png"
                fillMode: Image.PreserveAspectFit
                anchors {
                    fill: parent
                    margins: 10
                }
            }
        }
        RemoteButton {
            id: play
            buttonCommand: "play"
            anchors {
                left: rec.right
                top: rew.bottom
            }
            Image {
                source: "play.png"
                fillMode: Image.PreserveAspectFit
                anchors {
                    fill: parent
                    margins: 10
                }
            }
        }
        RemoteButton {
            id: stop
            buttonCommand: "stop"
            anchors {
                left: play.right
                top: rew.bottom
            }
            Image {
                source: "stop.png"
                fillMode: Image.PreserveAspectFit
                anchors {
                    fill: parent
                    margins: 14
                }
            }
        }

        RemoteButton {
            id: volup
            buttonCommand: 'volup'
            anchors {
                left: parent.left
                top: stop.bottom
            }
            Image {
                source: "volup.png"
                fillMode: Image.PreserveAspectFit
                anchors {
                    fill: parent
                    margins: 4
                }
            }
        }
        RemoteButton {
            id: voldn
            buttonCommand: 'voldn'
            anchors {
                top: volup.bottom
                left: parent.left
            }
            Image {
                source: "voldn.png"
                fillMode: Image.PreserveAspectFit
                anchors {
                    fill: parent
                    margins: 4
                }
            }
        }
        RemoteButton {
            id: mute
            buttonCommand: 'mute'
            anchors {
                top: stop.bottom
                left: volup.right
            }
            Image {
                source: "mute.png"
                fillMode: Image.PreserveAspectFit
                anchors {
                    fill: parent
                    margins: 4
                }
            }
        }
    }
}
