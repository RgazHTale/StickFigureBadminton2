import QtQuick 2.0
import Felgo  3.0
import QtQuick.Controls 2.0
import "../common"

SceneBase {
    id: gameNetworkScene

    property alias gnView: myGameNetworkView

    GameNetworkView {
        id: myGameNetworkView
    }

    onVisibleChanged: {
        if(visible) {
            ga.logScreen("GameNetworkScene")
            flurry.logEvent("Screen.GameNetworkScene")
        }
    }
}
