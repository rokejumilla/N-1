#include "Game.h"

Game::Game()
    : window(sf::VideoMode(800, 600), "Pelota Rebotando"),
    world(b2Vec2(0.0f, 9.8f)) { // Gravedad hacia abajo

    ball = new Ball(world, 400.0f, 300.0f, 15.0f);

    // Crear límites de la pantalla
    leftWall = new Boundary(world, 0, 300, 10, 600);
    rightWall = new Boundary(world, 800, 300, 10, 600);
    topWall = new Boundary(world, 400, 0, 800, 10);
    bottomWall = new Boundary(world, 400, 600, 800, 10);
}

void Game::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void Game::update() {
    world.Step(1.0f / 60.0f, 8, 3);
    ball->update();
}

void Game::render() {
    window.clear();
    ball->render(window);
    leftWall->render(window);
    rightWall->render(window);
    topWall->render(window);
    bottomWall->render(window);
    window.display();
}
