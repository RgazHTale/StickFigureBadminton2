import QtQuick 2.0
import Felgo 3.0
import "../common"
import "../entities"
import "../game"

SceneBase {
    id:gameScene

    property bool downIsPressed: false

    property alias badminton: badminton

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
                }
            }

      //button to tggle the sound effects
        MenuButton {
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
        }


    Net{
        id:net
        width: 30
        height: 200
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Badminton{
        id:badminton
        //x: player1.entityx + 100
        //y: player1.entityy - 5
        x:400
        y:600
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
            console.debug("key pressed actionName " + actionName)
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
            console.debug("key released actionName " + actionName)
          }
        }

    }

    Player2{
        id:player2

        TwoAxisController{
          id: controller2
          onInputActionPressed: {
              player2.player2Contorl(actionName);
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
          }
        }
    }
}
