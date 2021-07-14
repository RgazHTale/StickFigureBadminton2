import QtQuick 2.0
import Felgo 3.0

Item {
    id:gamelogic

    PhysicsWorld{
        id:physicsWorld
        gravity: Qt.point(0, 25)
        updatesPerSecondForPhysics:60
        debugDrawVisible: true // enable this for physics debugging
        z: 1000

        onPreSolve: {
            //this is called before the Box2DWorld handles contact events
            var entityA = contact.fixtureA.getBody().target
            var entityB = contact.fixtureB.getBody().target
            if(entityB.entityType === "player" && entityA.entityType === "player" ) {
              //by setting enabled to false, they can be filtered out completely
              //-> disable cloud platform collisions when the player is below the platform
              contact.enabled = false
            }
        }
    }
}
