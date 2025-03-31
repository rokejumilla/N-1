#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "Box2DHelper.h"
#include "SFMLRenderer.h"

// Constantes
const float SCALE = 30.0f;   // Escala de Box2D a SFML
const int WIDTH = 800, HEIGHT = 600;
const float GRAVITY = 9.8f;  // Gravedad normal
const float FRICTION = 0.3f; // Coeficiente de fricción
const float ANGLE = 30.0f;   // Ángulo del plano inclinado (en grados)

int main() {
    // Crear ventana
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Ejercicio 5 - Box2D");

    // Mundo de Box2D
    b2Vec2 gravity(0.0f, GRAVITY);
    b2World world(gravity);

    // Crear plano inclinado
    b2Body* groundBody = Box2DHelper::CreateInclinedPlane(world, WIDTH / (2 * SCALE), HEIGHT / SCALE - 5, ANGLE);

    // Crear caja deslizante
    b2Body* boxBody = Box2DHelper::CreateBox(world, WIDTH / (2 * SCALE), HEIGHT / SCALE - 10, 1.0f, 1.0f, FRICTION);

    // Renderizador SFML
    SFMLRenderer renderer(SCALE);

    // Bucle principal
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Actualizar simulación
        world.Step(1.0f / 60.0f, 8, 3);

        // Dibujar
        window.clear();
        renderer.drawPlane(window, groundBody, WIDTH, HEIGHT, ANGLE);
        renderer.drawBox(window, boxBody);
        window.display();
    }

    return 0;
}
