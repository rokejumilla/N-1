#ifndef BOUNDARY_H
#define BOUNDARY_H

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

class Boundary {
public:
    Boundary(b2World& world, float x, float y, float width, float height);
    void render(sf::RenderWindow& window);

private:
    b2Body* body;
    sf::RectangleShape shape;
};

#endif
