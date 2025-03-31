#include "Game.h"

Game::Game() : window(sf::VideoMode(800, 600), "Juego de Cañón"),
world(b2Vec2(0.f, -9.8f)),
cannon(world, sf::Vector2f(100.f, 500.f)),
projectile(world, sf::Vector2f(100.f, 500.f)),
ground(world, sf::Vector2f(400.f, 580.f)),
isProjectileLaunched(false) {}

void Game::Run() {
    while (window.isOpen()) {
        ProcessEvents();
        Update();
        Render();
    }
}

void Game::ProcessEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        cannon.Rotate(-1.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        cannon.Rotate(1.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !isProjectileLaunched) {
        projectile.Launch(cannon.GetAngle());
        isProjectileLaunched = true;
    }
}

void Game::Update() {
    world.Step(1 / 60.f, 8, 3);
    projectile.Update();
}

void Game::Render() {
    window.clear();
    cannon.Draw(window);
    projectile.Draw(window);
    ground.Draw(window);
    window.display();
}
