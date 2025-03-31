#include "SFMLRenderer.h"

SFMLRenderer::SFMLRenderer(float scaleFactor) {
    scale = scaleFactor;
}

void SFMLRenderer::drawBox(sf::RenderWindow& window, b2Body* body) {
    sf::RectangleShape box(sf::Vector2f(2 * scale, 2 * scale));
    box.setOrigin(scale, scale);
    box.setPosition(body->GetPosition().x * scale, body->GetPosition().y * scale);
    box.setRotation(body->GetAngle() * 180 / b2_pi);
    box.setFillColor(sf::Color::Red);
    window.draw(box);
}

void SFMLRenderer::drawPlane(sf::RenderWindow& window, b2Body* body, int width, int height, float angle) {
    sf::RectangleShape plane(sf::Vector2f(width, 10));
    plane.setOrigin(width / 2, 5);
    plane.setPosition(body->GetPosition().x * scale, body->GetPosition().y * scale);
    plane.setRotation(-angle);
    plane.setFillColor(sf::Color::Blue);
    window.draw(plane);
}
