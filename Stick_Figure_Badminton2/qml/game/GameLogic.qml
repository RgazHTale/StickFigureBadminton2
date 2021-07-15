import QtQuick 2.0
import Felgo 3.0
import "../common"
import "../entities"
import "../game"

Item {
    id:gamelogic

    PhysicsWorld{
        id:physicsWorld
        gravity: Qt.point(0, 25)
        updatesPerSecondForPhysics:60
        velocityIterations: 5
        positionIterations: 5
        debugDrawVisible: true // enable this for physics debugging
        z: 1000

        //判断是那两个物体之间发生了碰撞，根据物体的情况做出不同的判定
        onPreSolve: {
            //this is called before the Box2DWorld handles contact events
            var entityA = contact.fixtureA.getBody().target
            var entityB = contact.fixtureB.getBody().target
            if(entityB.entityType === "badmintion" && entityA.entityType === "player" && !player1.sequence.running) {
               contact.enabled = false;
           }
            if(entityB.entityType === "badmintion" && entityA.entityType === "wall" ) {
              //gamefail();
           }
            if(entityB.entityType === "badmintion" && entityA.entityType === "net" ) {
              //gamefail();
           }
        }
    }

    //不同的击球情况对球体施加不同的脉冲
    function beatright(){
        var localForwardVector = badminton.collider.body.toWorldVector(Qt.point(300, -600));
        badminton.collider.body.applyLinearImpulse(localForwardVector, badminton.collider.body.getWorldCenter());
    }

    function beatleft(){
        var localForwardVector = badminton.collider.body.toWorldVector(Qt.point(300, -600));
        badminton.collider.body.applyLinearImpulse(localForwardVector, badminton.collider.body.getWorldCenter());
    }

    function hitright(){
        var localForwardVector = badminton.collider.body.toWorldVector(Qt.point(300, -600));
        badminton.collider.body.applyLinearImpulse(localForwardVector, badminton.collider.body.getWorldCenter());
    }

    function hitleft(){
        var localForwardVector = badminton.collider.body.toWorldVector(Qt.point(300, -600));
        badminton.collider.body.applyLinearImpulse(localForwardVector, badminton.collider.body.getWorldCenter());
    }
}
