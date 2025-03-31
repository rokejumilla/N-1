#include "Projectile.h"
#include <cmath>

const float SCALE = 30.f;
const float DEG_TO_RAD = 3.14159265359f / 180.f;

Projectile::Projectile(b2World& world, sf::Vector2f position) {
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position = b2Vec2(position.x / SCALE, position.y / SCALE);
    body = world.CreateBody(&bodyDef);

    b2CircleShape circle;
    circle.m_radius = 5.f / SCALE;

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &circle;
    fixtureDef.density = 1.f;
    fixtureDef.friction = 0.3f;
    fixtureDef.restitution = 0.6f;

    body->CreateFixture(&fixtureDef);

    shape.setRadius(5.f);
    shape.setFillColor(sf::Color::Red);
}

void Projectile::Launch(float angle) {
    float force = 50.f;
    b2Vec2 forceVec(force * std::cos(angle * DEG_TO_RAD), -force * std::sin(angle * DEG_TO_RAD));
    body->ApplyLinearImpulseToCenter(forceVec, true);
}

void Projectile::Update() {
    b2Vec2 position = body->GetPosition();
    shape.setPosition(position.x * SCALE, position.y * SCALE);
}

void Projectile::Draw(sf::RenderWindow& window) {
    window.draw(shape);
}
