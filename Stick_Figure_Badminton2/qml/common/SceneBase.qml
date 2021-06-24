import Felgo 3.0
import QtQuick 2.0

Scene {
  id: sceneBase
  width: 960
  height: 640

  opacity: 0
  visible: opacity > 0
  enabled: visible

  Behavior on opacity {
    NumberAnimation {property: "opacity"; easing.type: Easing.InOutQuad}
  }
}
