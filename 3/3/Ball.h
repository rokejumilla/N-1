#ifndef BALL_H
#define BALL_H

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

class Ball {
private:
    b2Body* body;                // Cuerpo de Box2D
    sf::CircleShape shape;        // Representación gráfica en SFML

public:
    Ball(b2World& world, float x, float y, float radius, float restitution);

    void update();
    void render(sf::RenderWindow& window);

    b2Body* getBody() { return body; }  // Acceso al cuerpo físico
};

#endif // BALL_H
