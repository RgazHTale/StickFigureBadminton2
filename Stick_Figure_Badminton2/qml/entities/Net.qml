import QtQuick 2.0
import Felgo 3.0

EntityBase {
   id: net
   entityType: "net"
   entityId: "net"

   property alias netBoay: netBody

   Image {
     id: netBody
     width: 50
     height: 200
     source: "../../assets/res/net.png"
   }

   PolygonCollider {
     id: collider

     vertices: [
        Qt.point(0,0),
        Qt.point(0,120),
        Qt.point(50,200),
        Qt.point(48,48)
     ]

     bodyType: Body.Static
   }
}
