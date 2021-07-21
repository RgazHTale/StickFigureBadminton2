import QtQuick 2.0
import Felgo 3.0

Item{
    id:player1

    property alias entityx: entity.x
    property alias entityy: entity.y

    //设置一个状态标志，防止人物无限制地跳跃
    property int contacts: 0
    property int flag: 1

    signal hit
    signal beat

    state: contacts > 0 ? "standing" : "jumping"

    Image {
        //玩家1击球
        id: beatrightImage
        source: "../../assets/res/beatright/beatright.png"
        visible: false
    }
    Image {
        //玩家1跳起时击球
        id: hitrightImage
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
    Image {
        id: player1jump
        source: "../../assets/res/jumpIMG/jumpright.png"
        visible: false
    }
    Image {
        id: player1stand
        source: "../../assets/res/standright.png"
        visible: false
    }

    //精灵表单，用于表示player的各种动作
    EntityBase{
          id: entity
          entityType: "player1"

          PolygonCollider {
            id: player1Collider

            //我们需要设置物体之间的摩擦力为0,以防止人物卡在墙上    
            fixture.friction: 0
            vertices: [
               Qt.point(65,30),
               Qt.point(70,150),
               Qt.point(140,100),
               Qt.point(70,30)
            ]

            fixedRotation: true
            // apply the horizontal value of the TwoAxisController as force to move the player left and right
            force: Qt.point(controller1.xAxis*170*32,0)
            // limit the horizontal velocity
            onLinearVelocityChanged: {
              if(linearVelocity.x > 170) linearVelocity.x = 170
              if(linearVelocity.x < -170) linearVelocity.x = -170
            }
            fixture.onBeginContact: {
              var otherEntity = other.getBody().target
              if(otherEntity.entityType === "ground") player1.contacts++
              if(gamelogic.isContact) hitright();
            }
            fixture.onEndContact: {
              var otherEntity = other.getBody().target
              if(otherEntity.entityType === "ground") player1.contacts--
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

                  frameWidth: player1stand
                  frameHeight: player1stand
                  source: player1stand.source
             },
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
              },
              Sprite {
                name: "jumpright"
                frameCount: 1
                frameRate: 1

                frameWidth: player1jump
                frameHeight: player1jump
                source: player1jump.source
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

    function player1Contorl(){
        switch(arguments[0])
         {
         case "up":
             jump();
             sequence.jumpTo("jumpright");
             sequence.running = true;
             break;
         case "down":
             if(flag == 1){
                 sequence.jumpTo("hitright");
                 startGame();
                 flag = 0;
             }
             if(badminton.y > entityy + 30){
                 sequence.jumpTo("hitright");
             }else{
                 sequence.jumpTo("beatright");
             }
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
      if(player1.state === "standing") {
        // for the jump, we simply set the upwards velocity of the collider
        player1Collider.linearVelocity.y = -420
      }
    }

    function keyRelessed(){
        sequence.jumpTo("stand");
        sequence.running = false;
    }

    //不同的击球情况对球体施加不同的脉冲
    function beatright(){
        badminton.collider.body.linearVelocity = Qt.point(0,0);
        var localForwardVector = badminton.collider.body.toWorldVector(Qt.point(300, -600));
        badminton.collider.body.applyLinearImpulse(localForwardVector, badminton.collider.body.getWorldCenter());
    }

    function hitright(){
        badminton.collider.body.linearVelocity = Qt.point(0,0);
        var localForwardVector = badminton.collider.body.toWorldVector(Qt.point(300, -600));
        badminton.collider.body.applyLinearImpulse(localForwardVector, badminton.collider.body.getWorldCenter());
    }

    //发球
    function startGame(){
        badminton.collider.body.linearVelocity = Qt.point(0,0);
        badminton.visible = true;
        badminton.x = player1.entityx + 121;
        badminton.y = player1.entityy + 90;
        hitright();
        badminton.collider.gravityScale = 1;
    }

    function reSetPlayer(){
        player1Collider.force = 0;
    }
}
