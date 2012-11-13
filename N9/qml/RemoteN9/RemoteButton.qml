import QtQuick 1.1
import com.nokia.meego 1.0

Button {

    property string buttonCommand

    width: buttonWidth
    anchors.margins: buttonMargins
    onClicked: if (!wlan.hasConnection)
                   banner.show()
               else
                   sock.broadcast("00000000e0e0a25d 00 " + buttonCommand + " samsung\n")
}
