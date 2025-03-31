#ifndef PHYSICSMANAGER_H
#define PHYSICSMANAGER_H

#include <Box2D/Box2D.h>

class PhysicsManager {
private:
    b2World world;
public:
    PhysicsManager(float gravityX, float gravityY);
    void Step(float timeStep, int velocityIterations, int positionIterations);
    b2World& GetWorld();
};

#endif
