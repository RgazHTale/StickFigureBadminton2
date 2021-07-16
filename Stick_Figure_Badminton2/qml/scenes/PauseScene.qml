import QtQuick 2.0
import Felgo 3.0
import "../common"
import "../entities"

SceneBase {
    id:pauseScene


    Image {
        id: pause
        source: "../../assets/res/pause.jpg"
        anchors.fill: parent
    }

    Score {
        id:score
        anchors.top: parent.top
        anchors.topMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Column{
        anchors.top: parent.top
        anchors.topMargin: 220
        //anchors.horizontalCenter: parent.horizontalCenter
        anchors.left: parent.left
        anchors.leftMargin: 455

        spacing: 10

        MenuButton {
            id: gameContinue
            color: "transparent"
            width: 150
            height: 55
            onClicked: {
                window.state = "game"
                gameScene.gameRunning = true
            }
        }

        MenuButton {
            id:quit
            color: "transparent"
            width: 150
            height: 55
            onClicked: {
                window.state = "menu"
                gameScene.time = 20
                gameScene.gameRunning = false
                score.score1 = 0
                score.score2 = 0
            }
        }
    }
}
