import Felgo 3.0
import QtQuick 2.0
import "scenes"
import "common"

GameWindow {
  screenHeight: 640
  screenWidth: 960

  id: window

  // create and remove entities at runtime
  EntityManager {
    id: entityManager
    //entityContainer: gameScene
  }

  FontLoader {
    id: standardFont
    source: "fonts/bubblegum.ttf"
  }

  // menu scene
  MenuScene {
    id: menuScene
    onSettingsPressed: window.state = "settings"

    onBackButtonPressed: {
         nativeUtils.displayMessageBox(qsTr("Really quit the game?"), "", 2);
    }

    Connections {
      target: nativeUtils
      onMessageBoxFinished: {
        if (accepted) {
          Qt.quit()
        }
      }
    }
  }

  WaitScreen{
      id:waitToPlay
      onClicked: {
          window.state = "game"
      }
  }

  //game scene
  //实例化之后才能用
  GameScene {
      id:gameScene
  }

  //credits scene
  SettingScene {
      id: settingScene
      onBackButtonPressed: window.state = "menu"
  }

  PauseScene {
      id:pauseScene
  }

  GameOver {
      id:gameoverScene
  }

  state: "menu"
  activeScene: menuScene

  //state machine, takes care reversing the PropertyChanges when changing the state, like changing the opacity back to 0
  states: [
    State {
      name: "menu"
      PropertyChanges {target: menuScene; opacity: 1}
      PropertyChanges {target: window; activeScene: menuScene}
    },
      State {
        name: "pause"
        PropertyChanges {target: pauseScene; opacity: 1}
        PropertyChanges {target: window; activeScene: pauseScene}
      },
      State {
        name: "gameover"
        PropertyChanges {target: gameoverScene; opacity: 1}
        PropertyChanges {target: window; activeScene: gameoverScene}
      },
    State {
      name: "settings"
      PropertyChanges {target: settingScene; opacity: 1}
      PropertyChanges {target: window; activeScene: settingScene}
    },
    State {
      name: "game"
      PropertyChanges {target: gameScene; opacity: 1}
      PropertyChanges {target: window; activeScene: gameScene}
      },
      State {
        name: "wait"
        PropertyChanges {target: waitToPlay; opacity: 1}
        PropertyChanges {target: window; activeScene: waitToPlay}
      }
  ]
}
