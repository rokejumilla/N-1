#include "Block.h"
#include "Box2DHelper.h"

Block::Block(b2World& world) {
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(400.0f / SCALE, 50.0f / SCALE);
    body = world.CreateBody(&bodyDef);

    b2PolygonShape shape;
    shape.SetAsBox(25.0f / SCALE, 25.0f / SCALE);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &shape;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    body->CreateFixture(&fixtureDef);
}

void Block::render(sf::RenderWindow& window) {
    SFMLRenderer::drawBox(window, body, sf::Color::Red);
}
