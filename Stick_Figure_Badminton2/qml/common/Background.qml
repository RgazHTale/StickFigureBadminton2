import QtQuick 2.0
import Felgo 3.0

Image {
    id: background
    source: "../../assets/res/background.jpg"

    PolygonCollider {
      id: rightWallCollider

      vertices: [
         Qt.point(0,0),//top left
         Qt.point(0,642),//bottom left
         Qt.point(100,560),//bottom right
         Qt.point(100,0)//top right
      ]
      bodyType: Body.Static
    }

    PolygonCollider {
      id: leftWallCollider

      vertices: [
         Qt.point(860,0),
         Qt.point(860,560),
         Qt.point(960,642),
         Qt.point(960,0)
      ]
      bodyType: Body.Static
    }

    PolygonCollider {
      id: groundCollider

      vertices: [
         Qt.point(100,560),
         Qt.point(0,642),
         Qt.point(960,642),
         Qt.point(860,560)
      ]
      bodyType: Body.Static
    }
}
