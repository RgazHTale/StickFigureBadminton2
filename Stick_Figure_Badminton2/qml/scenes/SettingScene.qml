import QtQuick 2.0
import Felgo 3.0
import "../common"
import ".."

SceneBase {
    id:settingScene
    //anchors.fill: parent

    Image {
        id: background
        source: "../../assets/res/GameBG.png"
        anchors.fill: parent
    }

    MenuButton{
        label.height: 45
        label.width: 45
        label.source: ""
        color: "transparent"
        z: 10
        anchors.right: gameWindowAnchorItem.right
        onClicked: settingScene.backButtonPressed()
    }

    //在列中定位子节点
    Column {
        anchors.top: parent.top
        anchors.topMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter
        width: parent.width-40
        spacing: 20

        Text {
            font.family: standardFont.name
            font.pixelSize: 36
            color: "black"
            text: "Settings"
        }

        Text {
            font.family: standardFont.name
            font.pixelSize: 24
            color: "black"
            text: "Background Music"
        }
    }


    Column {
      anchors.right: parent.right
      anchors.rightMargin: 20
      anchors.top: parent.top
      anchors.topMargin: 77
      spacing: 8

      // button to turn the music on and off
      MenuButton {
        id:backgroundMusicSwitch
        width: 90
        height: 40
        label.source: active ? "../../assets/res/Switch_Off.png" : "../../assets/res/Switch_On.png"
        active: ! settings.musicEnabled
        opacity: 1
        onClicked:  {
          settings.musicEnabled ^= true
        }
      }

    }

    MenuButton {
        id:back
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.topMargin: 550
        anchors.leftMargin: 30
        label.width: 65
        label.height: 65
        label.source: "../../assets/res/Home.png"
        anchors.bottom: parent.bottom
        onClicked: {
            window.state = "menu"
        }
    }
}
