import Felgo 3.0
import QtQuick 2.0
import QtMultimedia 5.0
import "../common"
import ".."

// 这是主菜单
SceneBase {
    id: menuScene

    signal startPressed
    signal exitPressed

    property alias ambienceMusic: ambienceMusic

    //play background music
    BackgroundMusic{
        loops: SoundEffect.Infinite
        volume: 0.35//音量
        id: ambienceMusic
        source: "../../assets/res/game_music.mp3"
    }

    Timer{
        id:timerMusic
        interval: 100
        running: true//If set to true, starts the timer
        repeat: true
        onTriggered: {
            ambienceMusic.play()//开始播放媒体
            running = false
        }
    }

    //Background
    MultiResolutionImage{
        z: -2
        id: background
        source: "../../assets/res/start.png"
        anchors.fill: parent
    }

    //switch to role selection scene
    MenuButton{
        id: start
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.topMargin: 470
        anchors.leftMargin: 725
        text: "Start"
        onClicked: onClickedMusic.play()
        color: "transparent"
        buttonText.color: "white"
        buttonText.opacity: 1
        buttonText.font.pixelSize: 70
        buttonText.font.family: standardFont.name
    }


    //Quit the game
    MenuButton {
      anchors.top: parent.top
      anchors.left: parent.left
      anchors.topMargin: 540
      anchors.leftMargin: 725
      text: "Quit"
      onClicked: onClickedMusic.play()
      color: "transparent"
      buttonText.color: "white"
      buttonText.opacity: 1
      buttonText.font.pixelSize: 70
      buttonText.font.family: standardFont.name
    }
}
