#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include "Ground.h"
#include "Ball.h"
#include "Obstacle.h"

class World {
public:
    World();
    void update(float deltaTime);
    void render(sf::RenderWindow& window);

private:
    b2World physicsWorld;
    Ground ground;
    Ball ball;
    std::vector<Obstacle> obstacles;
};

#endif
