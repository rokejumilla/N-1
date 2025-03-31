#include <SFML/Graphics.hpp>
#include "World.h"

int main() {
    // Crear ventana SFML
    sf::RenderWindow window(sf::VideoMode(800, 600), "Box2D - Caída de Bloque");

    // Control de tiempo para simulación
    sf::Clock clock;

    // Crear el mundo de Box2D
    World world;

    // Bucle principal
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Calcular deltaTime
        float deltaTime = clock.restart().asSeconds();

        // Actualizar mundo
        world.update(deltaTime);

        // Renderizar
        window.clear(sf::Color::Black);
        world.render(window);
        window.display();
    }

    return 0;
}
