import QtQuick 2.0
import Felgo 3.0

EntityBase {
   entityType: "badmintion"

   property alias collider: collider

   x: 200
   y: 100
   visible: false

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
     gravityScale: 0
     body.linearVelocity: Qt.point(0,0)
     bullet: true
     fixture.onBeginContact:{
        var otherEntity = other.getBody().target;
        if(otherEntity.entityType === "wall" || otherEntity.entityType === "ground"){
            if(badminton.x > gameScene.width/2 && gameScene.time != 0){
                score.score1++;
                badminton.visible = false;
                player1Start();
            }else{
                if(gameScene.time != 0){
                    score.score2++;
                    badminton.visible = false;
                    player2Start();
                }
            }
        };
     }
   }

   function player1Start(){
        player1.flag = 1;
        gamelogic.isContact = true;
   }

   function player2Start(){
        player2.flag = 1;
        gamelogic.isContact = true;
   }

}
