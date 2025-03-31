#include "Boundary.h"

Boundary::Boundary(b2World& world, float x, float y, float width, float height) {
    // Definir cuerpo estático
    b2BodyDef bodyDef;
    bodyDef.position.Set(x, y);
    body = world.CreateBody(&bodyDef);

    // Definir forma
    b2PolygonShape box;
    box.SetAsBox(width / 2, height / 2);

    // Crear fixture
    body->CreateFixture(&box, 0.0f);

    // Configuración de SFML
    shape.setSize(sf::Vector2f(width, height));
    shape.setFillColor(sf::Color::Blue);
    shape.setOrigin(width / 2, height / 2);
    shape.setPosition(x, y);
}

void Boundary::render(sf::RenderWindow& window) {
    window.draw(shape);
}
