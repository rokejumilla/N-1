#include "World.h"

World::World() : physicsWorld(b2Vec2(0.0f, 9.8f)), ground(physicsWorld), block(physicsWorld) {
}

void World::update(float deltaTime) {
    physicsWorld.Step(deltaTime, 8, 3);
}

void World::render(sf::RenderWindow& window) {
    ground.render(window);
    block.render(window);
}
