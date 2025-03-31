#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "Box2DHelper.h"
#include "SFMLRenderer.h"

const float SCALE = 30.f;
const float DEG_TO_RAD = 3.14159265359f / 180.f;

int main() {
    // Crear la ventana de SFML
    sf::RenderWindow window(sf::VideoMode(800, 600), "Juego de Cañón");

    // Crear el mundo de Box2D con gravedad hacia abajo
    b2Vec2 gravity(0.f, -9.8f);
    b2World world(gravity);

    // Crear el suelo (estático)
    b2Body* groundBody = Box2DHelper::CreateRectangularStaticBody(&world, 800.f / SCALE, 20.f / SCALE, b2Vec2(400.f / SCALE, 580.f / SCALE));

    // Crear el cañón
    sf::RectangleShape cannon(sf::Vector2f(50.f, 20.f));
    cannon.setOrigin(0.f, 10.f);
    cannon.setPosition(100.f, 500.f);
    float cannonAngle = 45.f;

    // Crear el proyectil (dinámico)
    b2Body* projectileBody = Box2DHelper::CreateCircularDynamicBody(&world, 5.f / SCALE, 1.f, 0.3f, 0.6f, b2Vec2(100.f / SCALE, 500.f / SCALE));
    sf::CircleShape projectile(5.f);
    projectile.setFillColor(sf::Color::Red);
    bool isProjectileLaunched = false;

    // Bucle principal
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Controlar el ángulo del cañón
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            cannonAngle -= 1.f;
            if (cannonAngle < 0.f) cannonAngle = 0.f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            cannonAngle += 1.f;
            if (cannonAngle > 90.f) cannonAngle = 90.f;
        }
        cannon.setRotation(-cannonAngle);

        // Disparar el proyectil
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !isProjectileLaunched) {
            float angleRad = cannonAngle * DEG_TO_RAD;
            float force = 50.f;
            b2Vec2 forceVec(force * std::cos(angleRad), -force * std::sin(angleRad));
            projectileBody->ApplyLinearImpulseToCenter(forceVec, true);
            isProjectileLaunched = true;
        }

        // Actualizar el mundo de Box2D
        world.Step(1 / 60.f, 8, 3);

        // Actualizar la posición del proyectil en SFML
        b2Vec2 position = projectileBody->GetPosition();
        projectile.setPosition(position.x * SCALE, position.y * SCALE);

        // Dibujar todo
        window.clear();
        window.draw(cannon);
        window.draw(projectile);
        window.display();
    }

    return 0;
}
