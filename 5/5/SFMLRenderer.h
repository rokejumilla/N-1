#ifndef SFMLRENDERER_H
#define SFMLRENDERER_H

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

class SFMLRenderer {
private:
    float scale;

public:
    SFMLRenderer(float scaleFactor);
    void drawBox(sf::RenderWindow& window, b2Body* body);
    void drawPlane(sf::RenderWindow& window, b2Body* body, int width, int height, float angle);
};

#endif
