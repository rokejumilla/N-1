#include "World.h"

World::World() : physicsWorld(b2Vec2(0.0f, 9.8f)), ground(physicsWorld), ball(physicsWorld) {
    // Crear algunos obstáculos en la pantalla
    obstacles.emplace_back(physicsWorld, 300, 400);
    obstacles.emplace_back(physicsWorld, 500, 250);
    obstacles.emplace_back(physicsWorld, 200, 150);
}

void World::update(float deltaTime) {
    physicsWorld.Step(deltaTime, 8, 3);
}

void World::render(sf::RenderWindow& window) {
    ground.render(window);
    ball.render(window);

    for (auto& obstacle : obstacles) {
        obstacle.render(window);
    }
}
