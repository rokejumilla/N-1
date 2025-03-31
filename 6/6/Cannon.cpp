#include "Cannon.h"

Cannon::Cannon(b2World& world, sf::Vector2f position) : angle(45.f) {
    shape.setSize(sf::Vector2f(50.f, 20.f));
    shape.setOrigin(0.f, 10.f);
    shape.setPosition(position);
}

void Cannon::Rotate(float deltaAngle) {
    angle += deltaAngle;
    if (angle < 0.f) angle = 0.f;
    if (angle > 90.f) angle = 90.f;
    shape.setRotation(-angle);
}

float Cannon::GetAngle() const {
    return angle;
}

void Cannon::Draw(sf::RenderWindow& window) {
    window.draw(shape);
}
