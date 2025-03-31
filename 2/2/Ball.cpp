#include "Ball.h"

Ball::Ball(b2World& world, float x, float y, float radius) {
    // Definici�n del cuerpo f�sico
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(x, y);
    body = world.CreateBody(&bodyDef);

    // Forma de la pelota
    b2CircleShape circle;
    circle.m_radius = radius;

    // Propiedades f�sicas
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &circle;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    fixtureDef.restitution = 0.9f; // Rebote alto
    body->CreateFixture(&fixtureDef);

    // Configuraci�n de SFML
    shape.setRadius(radius);
    shape.setFillColor(sf::Color::Red);
    shape.setOrigin(radius, radius);
}

void Ball::update() {
    b2Vec2 pos = body->GetPosition();
    shape.setPosition(pos.x, pos.y);
}

void Ball::render(sf::RenderWindow& window) {
    window.draw(shape);
}
