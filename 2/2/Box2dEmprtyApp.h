#ifndef BOX2D_EMPTY_APP_H
#define BOX2D_EMPTY_APP_H

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "SFMLRenderer.h"
#include "Box2DHelper.h"

class Box2dEmptyApp {
public:
    Box2dEmptyApp();
    void run();

private:
    void processEvents();
    void update();
    void render();

    sf::RenderWindow window;
    b2World world;
    b2Body* ball;
    b2Body* ground;
};

#endif
