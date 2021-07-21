import QtQuick 2.0
import Felgo 3.0
import "../common"
import "../entities"
import "../game"

Item {
    id:gamelogic

    //这个property用来检测是否可以发生碰撞
    //如果这个为真，player碰到球之后才会击球
    property bool isContact: true

    PhysicsWorld{
        id:physicsWorld
        gravity: Qt.point(0, 25)
        updatesPerSecondForPhysics:60
        velocityIterations: 5
        positionIterations: 5
        z: 1000

        //判断两个物体之间发生了碰撞，根据物体的情况做出不同的判定
        onPreSolve: {
            //this is called before the Box2DWorld handles contact events
            var entityA = contact.fixtureA.getBody().target
            var entityB = contact.fixtureB.getBody().target
            if(entityB.entityType === "badmintion" && entityA.entityType === "player1" && !gameScene.player1DownIsPressed) {
              isContact = false;
              contact.enabled = false;
           }
            if(entityB.entityType === "badmintion" && entityA.entityType === "player2" && !gameScene.player2DownIsPressed) {
              isContact = false;
              contact.enabled = false;
           }
        }
    }
}
