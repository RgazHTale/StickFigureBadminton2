import QtQuick 2.0
import Felgo 3.0
import "../common"
import "../entities"
import "../game"

Item {
    id:gamelogic

    property bool isContact: true

    PhysicsWorld{
        id:physicsWorld
        gravity: Qt.point(0, 25)
        updatesPerSecondForPhysics:60
        debugDrawVisible: true
        velocityIterations: 5
        positionIterations: 5
        z: 1000

        //判断两个物体之间发生了碰撞，根据物体的情况做出不同的判定
        onPreSolve: {
            //this is called before the Box2DWorld handles contact events
            var entityA = contact.fixtureA.getBody().target
            var entityB = contact.fixtureB.getBody().target
            if(entityB.entityType === "badmintion" && entityA.entityType === "player" && !gameScene.player1DownIsPressed) {
              isContact = false;
              contact.enabled = false;
           }
            if(entityB.entityType === "badmintion" && entityA.entityType === "player" && !gameScene.player2DownIsPressed) {
              isContact = false;
              contact.enabled = false;
           }
        }
    }
}
