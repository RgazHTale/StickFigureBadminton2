import QtQuick 2.0
import Felgo 3.0

Item{
    id:player2

    property int contacts: 0
    state: contacts > 0 ? "standing" : "jumping"

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
    Image {
        id: player2jump
        source: "../../assets/res/jumpIMG/jumpleft.png"
        visible: false
    }
    Image {
        id: player2stand
        source: "../../assets/res/standleft.png"
        visible: false
    }

    //精灵表单，用于表示player的各种动作
    EntityBase{
          x: 700
          y: 405
          entityType: "player"

          PolygonCollider {
            id: player2Collider

            vertices: [
               Qt.point(65,0),
               Qt.point(70,150),
               Qt.point(75,150),
               Qt.point(70,0)
            ]

            fixedRotation: true
            // apply the horizontal value of the TwoAxisController as force to move the player left and right
            force: Qt.point(controller2.xAxis*170*32,0)
            // limit the horizontal velocity
            onLinearVelocityChanged: {
              if(linearVelocity.x > 170) linearVelocity.x = 170
              if(linearVelocity.x < -170) linearVelocity.x = -170
            }
            fixture.onBeginContact: {
              var otherEntity = other.getBody().target
              if(otherEntity.entityType === "ground") player2.contacts++
            }
            fixture.onEndContact: {
              var otherEntity = other.getBody().target
              if(otherEntity.entityType === "ground") player2.contacts--
            }
          }

          SpriteSequence {
          id: sequence
          width: 150
          height: 150
          running: false
          sprites: [
              Sprite {
                    name: "stand"
                    frameCount: 1
                    frameRate: 1

                    frameWidth: player2stand
                    frameHeight: player2stand
                    source: player2stand.source
               },
              Sprite {
                  name: "beatleft"
                  frameCount: 4
                  frameRate: 15

                  frameWidth: beatleftImage.width/4//单位是像素
                  frameHeight: beatleftImage.height
                  source: "../../assets/res/beatleft/beatleft.png"
              },
              Sprite {
                  name: "hitleft"
                  frameCount: 5
                  frameRate: 15

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
              },
              Sprite {
                name: "jumpleft"
                frameCount: 1
                frameRate: 1

                frameWidth: player2jump
                frameHeight: player2jump
                source: player2jump.source
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

    function player2Contorl(){
        switch(arguments[0])
         {
         case "up":
             jump();
             sequence.jumpTo("jumpleft");
             sequence.running = true;
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
      if(player2.state === "standing") {
        // for the jump, we simply set the upwards velocity of the collider
        player2Collider.linearVelocity.y = -420
      }
    }

    function keyRelessed(){
        sequence.jumpTo("stand");
        sequence.running = false;
    }
}
