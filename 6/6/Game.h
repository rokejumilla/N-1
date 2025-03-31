#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "Cannon.h"
#include "Projectile.h"
#include "Ground.h"

class Game {
public:
    Game();
    void Run();

private:
    sf::RenderWindow window;
    b2World world;
    Cannon cannon;
    Projectile projectile;
    Ground ground;
    bool isProjectileLaunched;

    void ProcessEvents();
    void Update();
    void Render();
};

#endif // GAME_H
