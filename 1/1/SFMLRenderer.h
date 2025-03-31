#ifndef SFMLRENDERER_H
#define SFMLRENDERER_H

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

class SFMLRenderer {
public:
    static void drawBox(sf::RenderWindow& window, b2Body* body, sf::Color color);
};

#endif
