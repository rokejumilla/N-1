#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

class Projectile {
public:
    Projectile(b2World& world, sf::Vector2f position);
    void Launch(float angle);
    void Update();
    void Draw(sf::RenderWindow& window);

private:
    b2Body* body;
    sf::CircleShape shape;
};

#endif // PROJECTILE_H
