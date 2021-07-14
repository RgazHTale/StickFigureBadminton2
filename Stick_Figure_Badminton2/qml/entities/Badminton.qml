import QtQuick 2.0
import Felgo 3.0

EntityBase {
   id: badmintion
   entityType: "badmintion"
   entityId: "badmintion"

   Image {
       id: badmintionImage
       width: 30
       height: 30
       source: "../../assets/res/ball.png"
   }

   CircleCollider {
     id: collider
     radius: badmintionImage.width/2
     fixedRotation: true
     fixture.onBeginContact: {
       player.gameOver()
     }
   }
}
