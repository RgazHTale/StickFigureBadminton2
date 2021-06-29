import QtQuick 2.0
import Felgo 3.0

Item{
    id:player2

    property int contacts: 0
    state: contacts > 0 ? "walking" : "jumping"

    Image {
        //玩家2击球
        id: beatleftImage
        source: "../../assets/res/beatleft/beatleft.png"
        visible: false
    }
    Image {
        //玩家2跳起时击球
        id: hitleftImage
        source: "../../assets/res/hitleft/hitleft.png"
        visible: false
    }
    Image {
        id: player2runleftImage//玩家2向左跑
        source: "../../assets/res/player2runleft/player2runleft.png"
        visible: false
    }
    Image {
        id: player2runrightImage//玩家2向右跑
        source: "../../assets/res/player2runright/player2runright.png"
        visible: false
    }

    //精灵表单，用于表示player的各种动作
    EntityBase{
          x: 700
          y: 405

          BoxCollider{
            id:player2Collider
            width: 150
            height: 150
            fixedRotation: true
            // apply the horizontal value of the TwoAxisController as force to move the player left and right
            force: Qt.point(controller2.xAxis*170*32,0)
            // limit the horizontal velocity
            onLinearVelocityChanged: {
              if(linearVelocity.x > 170) linearVelocity.x = 170
              if(linearVelocity.x < -170) linearVelocity.x = -170
            }
          }

          SpriteSequence {
          id: sequence
          width: 100
          height: 100
          running: false
          sprites: [
             Sprite {
                  name: "beatleft"
                  frameCount: 4
                  frameRate: 40

                  frameWidth: beatleftImage.width/4//单位是像素
                  frameHeight: beatleftImage.height
                  source: "../../assets/res/beatleft/beatleft.png"
              },
              Sprite {
                  name: "hitleft"
                  frameCount: 5
                  frameRate: 40

                  frameWidth: hitleftImage.width/5//单位是像素
                  frameHeight: hitleftImage.height
                  source: "../../assets/res/hitleft/hitleft.png"
              },
              Sprite {
                  name: "player2runleft"
                  frameCount: 6
                  frameRate: 10

                  frameWidth: player2runleftImage.width/6
                  frameHeight: player2runleftImage.height
                  source: "../../assets/res/player2runleft/player2runleft.png"
              },
              Sprite {
                  name: "player2runright"
                  frameCount: 5
                  frameRate: 10

                  frameWidth: player2runrightImage.width/5
                  frameHeight: player2runrightImage.height
                  source: "../../assets/res/player2runright/player2runright.png"
              }
          ]
        }
        Timer {
          id: updateTimer
          // set this interval as high as possible to improve performance, but as low as needed so it still looks good
          interval: 60
          running: true
          repeat: true
          onTriggered: {
            var xAxis = controller2.xAxis;
            // if xAxis is 0 (no movement command) we slow the player down until he stops
            if(xAxis === 0) {
              if(Math.abs(player2Collider.linearVelocity.x) > 10) player2Collider.linearVelocity.x /= 1.5
              else player2Collider.linearVelocity.x = 0
            }
          }
        }
    }

    function palyer2Contorl(){
        switch(arguments[0])
         {
         case "up":
             sequence.running = false;
             jump();
             break;
         case "down":
             sequence.jumpTo("beatleft");
             sequence.running = true;
             break;
         case "left":
             sequence.jumpTo("player2runleft");
             sequence.running = true;
             break;
         case "right":
             sequence.jumpTo("player2runright");
             sequence.running = true;
             break;
         default:
             ;
         }
    }

    function jump() {
      console.debug("jump requested at player.state " + state)
      if(player.state === "walking") {
        console.debug("do the jump")
        // for the jump, we simply set the upwards velocity of the collider
        collider.linearVelocity.y = -420
      }
    }

    function keyRelessed(){
        sequence.running = false;
    }
}
