import QtQuick 2.0
import Felgo 3.0
import "../common"

SceneBase {
    opacity: 0
    visible: opacity === 0 ? false : true
    enabled: visible

    signal clicked()

    Image {
        id: waitScreen
        source: "../../assets/res/wait2.png"
        anchors.fill: parent
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            parent.clicked()
            gameScene.gameRunning = true
        }
    }
}
