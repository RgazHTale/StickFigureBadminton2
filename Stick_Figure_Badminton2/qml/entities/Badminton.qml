import QtQuick 2.0
import Felgo 3.0

EntityBase {
   entityType: "badmintion"
   entityId: "badmintion"

   property alias collider: collider

   Image {
       id: badmintionImage
       width: 25
       height: 25
       source: "../../assets/res/ball.png"
   }

   CircleCollider {
     id: collider
     radius: badmintionImage.width/2
     fixedRotation: true
     fixture.friction: 0.5
     fixture.restitution: 0.5
     //gravityScale: 0.1
     body.linearVelocity: Qt.point(0,0)
     /*fixture.onBeginContact: {
         collider.linearVelocity.y = -620
         collider.linearVelocity.x = 300
     }*/
     bullet: true
   }

   //Component.onCompleted: {
       //var localForwardVector = collider.body.toWorldVector(Qt.point(300, -600));
       //collider.body.applyLinearImpulse(localForwardVector, collider.body.getWorldCenter());
       //collider.linearVelocity.y = -620
       //collider.linearVelocity.x = 300
       //console.debug("1111111111");
//}
}
