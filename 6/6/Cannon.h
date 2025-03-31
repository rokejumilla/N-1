#ifndef CANNON_H
#define CANNON_H

#include <SFML/Graphics.hpp>

class Cannon {
public:
    Cannon(b2World& world, sf::Vector2f position);
    void Rotate(float angle);
    float GetAngle() const;
    void Draw(sf::RenderWindow& window);

private:
    sf::RectangleShape shape;
    float angle;
};

#endif // CANNON_H
