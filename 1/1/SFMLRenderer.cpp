#include "SFMLRenderer.h"
#include "Box2DHelper.h"

void SFMLRenderer::drawBox(sf::RenderWindow& window, b2Body* body, sf::Color color) {
    for (b2Fixture* fixture = body->GetFixtureList(); fixture; fixture = fixture->GetNext()) {
        if (fixture->GetType() == b2Shape::e_polygon) {
            b2PolygonShape* polyShape = (b2PolygonShape*)fixture->GetShape();
            sf::ConvexShape shape;
            shape.setPointCount(polyShape->m_count);
            shape.setFillColor(color);

            for (int i = 0; i < polyShape->m_count; ++i) {
                b2Vec2 point = body->GetWorldPoint(polyShape->m_vertices[i]);
                shape.setPoint(i, B2VecToSFVec(point));
            }

            window.draw(shape);
        }
    }
}
