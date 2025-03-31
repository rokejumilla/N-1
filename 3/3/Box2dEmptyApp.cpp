#include <SFML/Graphics.hpp>
#include "World.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Box2D + SFML - Pelota con Obstáculos");
    World world;

    sf::Clock clock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float deltaTime = clock.restart().asSeconds();
        world.update(deltaTime);

        window.clear();
        world.render(window);
        window.display();
    }

    return 0;
}
