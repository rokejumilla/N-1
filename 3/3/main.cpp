#include <SFML/Graphics.hpp>
#include "World.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Box2D - Pelota Rebotando con Obst�culos");

    sf::Clock clock;
    World world;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float deltaTime = clock.restart().asSeconds();
        world.update(deltaTime);

        window.clear(sf::Color::Black);
        world.render(window);
        window.display();
    }

    return 0;
}
