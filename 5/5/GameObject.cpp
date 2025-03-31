#include "GameObject.h"

GameObject::GameObject(b2World& world, float x, float y, float width, float height, bool dynamic, float scale)
    : scale(scale) {

    b2BodyDef bodyDef;
    bodyDef.position.Set(x, y);
    bodyDef.type = dynamic ? b2_dynamicBody : b2_staticBody;
    body = world.CreateBody(&bodyDef);

    b2PolygonShape boxShape;
    boxShape.SetAsBox(width / 2, height / 2);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &boxShape;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    body->CreateFixture(&fixtureDef);

    shape.setSize(sf::Vector2f(width * scale, height * scale));
    shape.setOrigin(width * scale / 2, height * scale / 2);
    shape.setFillColor(sf::Color::Red);
}

void GameObject::Update() {
    shape.setPosition(body->GetPosition().x * scale, body->GetPosition().y * scale);
    shape.setRotation(body->GetAngle() * 180 / b2_pi);
}

void GameObject::Draw(sf::RenderWindow& window) {
    window.draw(shape);
}
