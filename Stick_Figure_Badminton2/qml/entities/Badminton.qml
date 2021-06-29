import QtQuick 2.0
import Felgo 3.0

EntityBase {
   id: badmintion
   entityType: "badmintion"
   entityId: "badmintion"

   Image {
       id: badmintionImage
       width: 50
       height: 200
       source: "../../assets/res/ball.png"
   }

   CircleCollider {
     id: collider
     radius: badmintionImage.width/2
     anchors.centerIn: netBoay
     bodyType: Body.Static
     collisionTestingOnlyMode: true
     fixture.onBeginContact: {
       player.gameOver()
     }
   }
}
