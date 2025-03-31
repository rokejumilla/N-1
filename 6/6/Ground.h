#ifndef GROUND_H
#define GROUND_H

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

class Ground {
public:
    Ground(b2World& world, sf::Vector2f position);
    void Draw(sf::RenderWindow& window);

private:
    b2Body* body;
    sf::RectangleShape shape;
};

#endif // GROUND_H
