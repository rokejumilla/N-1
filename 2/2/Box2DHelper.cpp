#include "Box2DHelper.h"

// Escalado para compatibilidad entre Box2D y SFML
const float SCALE = 30.0f;

sf::Vector2f Box2DHelper::toSFML(const b2Vec2& vec) {
    return sf::Vector2f(vec.x * SCALE, -vec.y * SCALE);
}

b2Vec2 Box2DHelper::toBox2D(const sf::Vector2f& vec) {
    return b2Vec2(vec.x / SCALE, -vec.y / SCALE);
}

float Box2DHelper::toDegrees(float radians) {
    return radians * (180.0f / b2_pi);
}
