#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "Ball.h"
#include "Boundary.h"

class Game {
public:
    Game();
    void run();

private:
    void processEvents();
    void update();
    void render();

    sf::RenderWindow window;
    b2World world;
    Ball* ball;
    Boundary* leftWall;
    Boundary* rightWall;
    Boundary* topWall;
    Boundary* bottomWall;
};

#endif
