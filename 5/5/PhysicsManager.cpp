#include "PhysicsManager.h"

PhysicsManager::PhysicsManager(float gravityX, float gravityY) : world(b2Vec2(gravityX, gravityY)) {}

void PhysicsManager::Step(float timeStep, int velocityIterations, int positionIterations) {
    world.Step(timeStep, velocityIterations, positionIterations);
}

b2World& PhysicsManager::GetWorld() {
    return world;
}
