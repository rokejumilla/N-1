#include "Ball.h"
#include "Box2DHelper.h"

Ball::Ball(b2World& world) {
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(400.0f / SCALE, 100.0f / SCALE);
    body = world.CreateBody(&bodyDef);

    b2CircleShape shape;
    shape.m_radius = 20.0f / SCALE;

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &shape;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    fixtureDef.restitution = 0.8f;  // Rebote alto
    body->CreateFixture(&fixtureDef);
}

void Ball::render(sf::RenderWindow& window) {
    SFMLRenderer::drawCircle(window, body, sf::Color::Blue);
}
