#include "PlaneObject.h"

PlaneObject::PlaneObject(b2World& world, float x, float y, float angle, float scale)
    : GameObject(world, x, y, 10.0f, 0.5f, false, scale) {
    body->SetTransform(body->GetPosition(), -angle * b2_pi / 180.0f);
    shape.setFillColor(sf::Color::Blue);
}
