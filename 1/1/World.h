#ifndef WORLD_H
#define WORLD_H

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include "Ground.h"
#include "Block.h"

class World {
public:
    World();
    void update(float deltaTime);
    void render(sf::RenderWindow& window);

private:
    b2World physicsWorld;
    Ground ground;
    Block block;
};

#endif
