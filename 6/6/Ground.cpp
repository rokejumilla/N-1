#include "Ground.h"

const float SCALE = 30.f;

Ground::Ground(b2World& world, sf::Vector2f position) {
    b2BodyDef bodyDef;
    bodyDef.position = b2Vec2(position.x / SCALE, position.y / SCALE);
    bodyDef.type = b2_staticBody;
    body = world.CreateBody(&bodyDef);

    b2PolygonShape box;
    box.SetAsBox(400.f / SCALE, 10.f / SCALE);

    body->CreateFixture(&box, 0.0f);

    shape.setSize(sf::Vector2f(800.f, 20.f));
    shape.setFillColor(sf::Color::Green);
    shape.setOrigin(400.f, 10.f);
    shape.setPosition(position);
}

void Ground::Draw(sf::RenderWindow& window) {
    window.draw(shape);
}
