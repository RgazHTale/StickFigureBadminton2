import Felgo 3.0
import QtQuick 2.0

// button with text
Rectangle {
  id: button

  // this will be the default size, it is same size as the contained text + some padding
  width: buttonText.width + paddingHorizontal * 2
  height: buttonText.height + paddingVertical * 2
  color: "transparent"
  radius: 10

  // the horizontal padding from the Text element to the Rectangle at both the left and the right side.
  property int paddingHorizontal: 20
  // the vertical padding from the Text element to the Rectangle at both the top and the bottom side.
  property int paddingVertical: 10

  // access the text of the Text component
  property alias buttonText: buttonText
  property alias text: buttonText.text
  property alias label: label
  property bool active: false
  property alias onClickedMusic: onClickedMusic

  // this handler is called when the button is clicked.
  signal clicked

  Image {
    id: label
    anchors.centerIn: parent
    width: parent.width
    height: parent.height
  }

  Text {
    id: buttonText
    anchors.centerIn: parent
    font.pixelSize: 36
    color: "black"
  }

  MouseArea {
    id: mouseArea
    anchors.fill: parent
    hoverEnabled: true
    onClicked: button.clicked()
    onPressed: button.opacity = 0.5
    onReleased: button.opacity = 1
  }

  //onClicked sound
  SoundEffect{
      id: onClickedMusic
      volume: 0.35//音量
      source: "../../assets/audio/sfx_hit.wav"
  }
}
