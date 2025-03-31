#ifndef BOX2DHELPER_H
#define BOX2DHELPER_H

#include <Box2D/Box2D.h>
#include <SFML/System.hpp>

const float SCALE = 30.0f;  // Conversión de Box2D a SFML

inline sf::Vector2f B2VecToSFVec(const b2Vec2& vec) {
    return sf::Vector2f(vec.x * SCALE, vec.y * SCALE);
}

inline b2Vec2 SFVecToB2Vec(const sf::Vector2f& vec) {
    return b2Vec2(vec.x / SCALE, vec.y / SCALE);
}

#endif
