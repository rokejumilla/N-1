#include "SFMLRenderer.h"

SFMLRenderer::SFMLRenderer(sf::RenderWindow& window, b2World& world) : window(window), world(world) {}

void SFMLRenderer::RenderBody(b2Body* body, sf::Color color) {
    if (!body) return;

    for (b2Fixture* fixture = body->GetFixtureList(); fixture; fixture = fixture->GetNext()) {
        if (b2PolygonShape* shape = dynamic_cast<b2PolygonShape*>(fixture->GetShape())) {
            sf::ConvexShape polygon;
            polygon.setPointCount(shape->m_count);
            polygon.setFillColor(color);

            for (int i = 0; i < shape->m_count; ++i) {
                b2Vec2 point = body->GetWorldPoint(shape->m_vertices[i]);
                polygon.setPoint(i, sf::Vector2f(point.x * 30.0f, point.y * 30.0f));
            }

            window.draw(polygon);
        }
    }
}
