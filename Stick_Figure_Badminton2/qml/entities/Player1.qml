import QtQuick 2.0
import Felgo 3.0

Item{
    id:player1

    property int contacts: 0
    state: contacts > 0 ? "walking" : "jumping"

    Image {
        //玩家1击球
        id: beatrightImage
        source: "../../assets/res/beatright/beatright.png"
        visible: false
    }
    Image {
        //玩家1跳起时击球
        id: hitleftImage
        source: "../../assets/res/hitright/hitright.png"
        visible: false
    }
    Image {
        id: player1runleftImage//玩家1向左跑
        source: "../../assets/res/player1runleft/player1left.png"
        visible: false
    }
    Image {
        id: player1runrightImage//玩家1向右跑
        source: "../../assets/res/player1runright/player1runright.png"
        visible: false
    }

    //精灵表单，用于表示player的各种动作
    EntityBase{
          x: 200
          y: 405

          BoxCollider{
            id:player1Collider
            width: 150
            height: 150
            fixedRotation: true
            // apply the horizontal value of the TwoAxisController as force to move the player left and right
            force: Qt.point(controller1.xAxis*170*32,0)
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
                  name: "beatright"
                  frameCount: 4
                  frameRate: 15

                  frameWidth: beatrightImage.width/4//单位是像素
                  frameHeight: beatrightImage.height
                  source: "../../assets/res/beatright/beatright.png"
              },
              Sprite {
                  name: "hitright"
                  frameCount: 5
                  frameRate: 15

                  frameWidth: hitrightImage.width/5//单位是像素
                  frameHeight: hitrightImage.height
                  source: "../../assets/res/hitright/hitright.png"
              },
              Sprite {
                  name: "player1runleft"
                  frameCount: 4
                  frameRate: 10

                  frameWidth: player1runleftImage.width/4
                  frameHeight: player1runleftImage.height
                  source: "../../assets/res/player1runleft/player1runleft.png"
              },
              Sprite {
                  name: "player1runright"
                  frameCount: 3
                  frameRate: 10

                  frameWidth: player1runrightImage.width/3
                  frameHeight: player1runrightImage.height
                  source: "../../assets/res/player1runright/player1runright.png"
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
            var xAxis = controller1.xAxis;
            // if xAxis is 0 (no movement command) we slow the player down until he stops
            if(xAxis === 0) {
              if(Math.abs(player1Collider.linearVelocity.x) > 10) player1Collider.linearVelocity.x /= 1.5
              else player1Collider.linearVelocity.x = 0
            }
          }
        }
    }

    function palyer1Contorl(){
        switch(arguments[0])
         {
         case "up":
             sequence.running = false;
             jump();
             break;
         case "down":
             sequence.jumpTo("beatright");
             sequence.running = true;
             break;
         case "left":
             sequence.jumpTo("player1runleft");
             sequence.running = true;
             break;
         case "right":
             sequence.jumpTo("player1runright");
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