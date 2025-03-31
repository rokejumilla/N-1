#ifndef BALL_H
#define BALL_H

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

class Ball {
public:
    Ball(b2World& world, float x, float y, float radius);
    void update();
    void render(sf::RenderWindow& window);

private:
    b2Body* body;
    sf::CircleShape shape;
};

#endif
