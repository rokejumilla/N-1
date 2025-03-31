#include "Ground.h"
#include "Box2DHelper.h"

Ground::Ground(b2World& world) {
    b2BodyDef bodyDef;
    bodyDef.position.Set(400.0f / SCALE, 550.0f / SCALE);
    body = world.CreateBody(&bodyDef);

    b2PolygonShape shape;
    shape.SetAsBox(400.0f / SCALE, 10.0f / SCALE);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &shape;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.5f;
    body->CreateFixture(&fixtureDef);
}

void Ground::render(sf::RenderWindow& window) {
    SFMLRenderer::drawBox(window, body, sf::Color::Green);
}
