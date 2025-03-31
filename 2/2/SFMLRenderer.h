#ifndef SFMLRENDERER_H
#define SFMLRENDERER_H

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

class SFMLRenderer {
public:
    static void drawCircle(sf::RenderWindow& window, b2Body* body, float radius, sf::Color color);
    static void drawRectangle(sf::RenderWindow& window, b2Body* body, float width, float height, sf::Color color);
};

#endif
