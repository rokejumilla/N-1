#ifndef BLOCK_H
#define BLOCK_H

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include "SFMLRenderer.h"

class Block {
public:
    Block(b2World& world);
    void render(sf::RenderWindow& window);

private:
    b2Body* body;
};

#endif
