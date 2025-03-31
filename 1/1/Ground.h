#ifndef GROUND_H
#define GROUND_H

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include "SFMLRenderer.h"

class Ground {
public:
    Ground(b2World& world);
    void render(sf::RenderWindow& window);

private:
    b2Body* body;
};

#endif
