#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

class GameObject {
protected:
    b2Body* body;
    sf::RectangleShape shape;
    float scale;

public:
    GameObject(b2World& world, float x, float y, float width, float height, bool dynamic, float scale);
    virtual void Update();
    virtual void Draw(sf::RenderWindow& window);
};

#endif

