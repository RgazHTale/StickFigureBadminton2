import QtQuick 2.0
import Felgo 3.0

Image {
    id: background
    source: "../../assets/res/background.jpg"

    EntityBase{
    entityType: "wall"
    PolygonCollider {
      id: rightWallCollider

      vertices: [
         Qt.point(0,0),//top left
         Qt.point(0,642),//bottom left
         Qt.point(50,600),//bottom right
         Qt.point(50,0)//top right
      ]
      bodyType: Body.Static
    }


    PolygonCollider {
      id: leftWallCollider

      vertices: [
         Qt.point(910,0),
         Qt.point(910,600),
         Qt.point(960,642),
         Qt.point(960,0)
      ]
      bodyType: Body.Static
    }
    }

    EntityBase{
    entityType: "ground"
    PolygonCollider {
      id: groundCollider

      vertices: [
         Qt.point(50,600),
         Qt.point(0,642),
         Qt.point(960,642),
         Qt.point(910,600)
      ]
      bodyType: Body.Static
    }
    }
}
