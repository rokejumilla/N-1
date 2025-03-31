#ifndef SFMLRENDERER_H
#define SFMLRENDERER_H

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

class SFMLRenderer {
public:
    SFMLRenderer(sf::RenderWindow& window, float scale);
    void Render(b2Body* body);
    void RenderWorld(b2World& world);

private:
    sf::RenderWindow& m_window;
    float m_scale;
};

#endif // SFMLRENDERER_H
