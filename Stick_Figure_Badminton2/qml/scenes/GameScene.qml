import QtQuick 2.0
import Felgo 3.0
import "../common"
import "../entities"
import "../game"

SceneBase {
    id:gameScene

    property int time : 120
    // indicates if game is running
    property bool gameRunning: false
    property bool player1DownIsPressed: false
    property bool player2DownIsPressed: false

    property alias badminton: badminton
    property alias score: score
    property alias player1: player1
    property alias player2: player2

    Background{
        id:background
        anchors.fill: parent
    }

    GameLogic{
        id:gamelogic
    }

    Row{
        id:tools
        spacing: 10

        MenuButton {
            id: backButton
            color: "transparent"
            width: 40
            height: 40
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.topMargin: 15
            anchors.leftMargin: 10
            label.source: "../../assets/res/ArrowLeft.png"

            onClicked: {
                window.state = "menu"
                gameScene.time = 20
                gameScene.gameRunning = false
                }
            }

      //button to tggle the sound effects
        MenuButton {
            id: soundButton
            property bool gameRunning: false
            color: "transparent"
            width: 50
            height: 50
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.topMargin: 10
            anchors.leftMargin: 60
            label.source: "../../assets/res/Sound.png"
            active: ! settings.musicEnabled
            opacity: 1
            onClicked:  {
                settings.musicEnabled ^= true
                }
            }
        MenuButton {
            id:pauseButton
            color: "transparent"
            width: 40
            height: 40
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.topMargin: 15
            anchors.leftMargin: 125
            label.source: "../../assets/res/playAgain.png"
            onClicked: {
                  window.state = "pause";
                  gameScene.gameRunning = false;
            }
        }

    }

    Net{
        id:net
        width: 30
        height: 200
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
    }

    // display remaining time
    Text {
        id:timeText
        height:40
        text:"Time: "+gameScene.time
        color: "white"
        opacity: 1
        font.pixelSize: 20
        font.family: standardFont.name
        anchors.top: parent.top
        anchors.topMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Score {
        id:score
        anchors.top: parent.top
        anchors.topMargin: 35
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Timer {
        id:gameTimer
        running: gameRunning
        repeat: true
        onTriggered: {
                time--
            if(time == 0 ){
                window.state = "gameover"
                gameRunning = false
            }
        }
    }

    Badminton{
        id:badminton
        z: 1
    }

    Timer {
        running: true
        interval: 30
        repeat: true
        onTriggered: {
            if(player1DownIsPressed == true ){
                player1DownIsPressed == false;
            }
            if(player2DownIsPressed == true ){
                player2DownIsPressed == false;
            }
        }
    }

    Keys.forwardTo: [controller1,controller2]

    Player1{
        id:player1

        TwoAxisController{
          id: controller1
          inputActionsToKeyCode: {
             "up": Qt.Key_W,
             "down": Qt.Key_S,
             "left": Qt.Key_A,
             "right": Qt.Key_D,
          }
          onInputActionPressed: {
            player1.player1Contorl(actionName);
            if(actionName == "down") player1DownIsPressed = true;
          }
          onInputActionReleased: {
            if (actionName == "left"){
                if(!isPressed("right")){
                player1.keyRelessed();
                }
          }
            if (actionName == "right"){
                if(!isPressed("left")){
                player1.keyRelessed();
                }
          }
            if (actionName == "down"){
                if(!isPressed("left") && !isPressed("right")){
                player1.keyRelessed();
                }
            }
          }
    }

    Player2{
        id:player2

        TwoAxisController{
          id: controller2
          onInputActionPressed: {
              player2.player2Contorl(actionName);
              if(actionName == "down") player2DownIsPressed = true;
            }
          onInputActionReleased: {
              if (actionName == "left"){
                  if(!isPressed("right")){
                  player2.keyRelessed();
                  }
            }
              if (actionName == "right"){
                  if(!isPressed("left")){
                  player2.keyRelessed();
                  }
            }
              if (actionName == "down"){
                  if(!isPressed("left") && !isPressed("right")){
                  player2.keyRelessed();
                  }
              }
          }
        }
    }
  }
}
