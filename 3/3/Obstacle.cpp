#include "Obstacle.h"
#include "Box2DHelper.h"

Obstacle::Obstacle(b2World& world, float x, float y) {
    b2BodyDef bodyDef;
    bodyDef.position.Set(x / SCALE, y / SCALE);
    body = world.CreateBody(&bodyDef);

    b2PolygonShape shape;
    shape.SetAsBox(40.0f / SCALE, 10.0f / SCALE);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &shape;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.5f;
    body->CreateFixture(&fixtureDef);
}

void Obstacle::render(sf::RenderWindow& window) {
    SFMLRenderer::drawBox(window, body, sf::Color::Yellow);
}
