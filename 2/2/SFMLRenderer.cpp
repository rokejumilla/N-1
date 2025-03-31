#include "SFMLRenderer.h"
#include "Box2DHelper.h"

void SFMLRenderer::drawCircle(sf::RenderWindow& window, b2Body* body, float radius, sf::Color color) {
    sf::CircleShape shape(radius * 30.0f);
    shape.setFillColor(color);
    shape.setOrigin(radius * 30.0f, radius * 30.0f);

    b2Vec2 pos = body->GetPosition();
    shape.setPosition(Box2DHelper::toSFML(pos));
    shape.setRotation(Box2DHelper::toDegrees(body->GetAngle()));

    window.draw(shape);
}

void SFMLRenderer::drawRectangle(sf::RenderWindow& window, b2Body* body, float width, float height, sf::Color color) {
    sf::RectangleShape shape(sf::Vector2f(width * 30.0f, height * 30.0f));
    shape.setFillColor(color);
    shape.setOrigin(width * 15.0f, height * 15.0f);

    b2Vec2 pos = body->GetPosition();
    shape.setPosition(Box2DHelper::toSFML(pos));
    shape.setRotation(Box2DHelper::toDegrees(body->GetAngle()));

    window.draw(shape);
}
