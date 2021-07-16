/*
  *游戏的结束界面
  */
import QtQuick 2.0
import Felgo 3.0
import "../common"
import "../entities"

SceneBase {
    id:gameoverScene

    property string player
    property string champion

    champion : score.compare()

    Image {
        id: gameOver
        source: "../../assets/res/end.png"
        anchors.fill: parent
    }

    Score {
        id:score
        anchors.top: parent.top
        anchors.topMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter
        score1: gameScene.score.score1
        score2: gameScene.score.score2
    }

    Column{
        anchors.top: parent.top
        anchors.topMargin: 100
        anchors.horizontalCenter: parent.horizontalCenter
        Text{
            text: "Game Over !"
            font.family: standardFont.name
            font.pixelSize: 70
            opacity: 1
        }

        Text{
            text: champion
            font.family: standardFont.name
            font.pixelSize: 70
            opacity: 1
        }

        MenuButton{
            id:quit
            label.source: ""
            text: "Quit"
            width: 100
            height: 50
            onClicked: {
                window.state = "menu";
                gameScene.time = 20
                gameScene.gameRunning = false
                gameScene.score.score1 = 0;
                gameScene.score.score2 = 0;
            }
            color: "transparent"
            buttonText.color: "white"
            buttonText.opacity: 1
            buttonText.font.pixelSize: 40
            buttonText.font.family: standardFont.name

            anchors.horizontalCenter: parent.horizontalCenter
        }

        MenuButton{
            id:again
            label.source: ""
            text: "Again"
            width: 100
            height: 50
            onClicked: {
                gameScene.score.score1 = 0;
                gameScene.score.score2 = 0;
                gameScene.time = 120;
                window.state = "wait";
                menuScene.reStart();
                gameScene.player1.flag = 1;
            }
            color: "transparent"
            buttonText.color: "white"
            buttonText.opacity: 1
            buttonText.font.pixelSize: 40
            buttonText.font.family: standardFont.name
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
}
