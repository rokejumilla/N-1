#include "SFMLRenderer.h"
#include "Box2DHelper.h"

const int WIDTH = 800, HEIGHT = 600;
const float SCALE = 30.0f; // Conversión de metros a píxeles

int main() {
    // Crear la ventana de SFML
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Ejercicio 4 - Box2D");

    // Crear el mundo de Box2D sin gravedad en el eje Y (para deslizar horizontalmente)
    b2World world(b2Vec2(0.0f, 0.0f));

    // Crear el suelo y la caja con fricción ajustable
    float friction = 0.3f;  // Puedes cambiar este valor para probar distintos coeficientes
    b2Body* ground = Box2DHelper::CreateGround(world, WIDTH / 2.0f, HEIGHT - 30.0f, WIDTH, 20.0f);
    b2Body* box = Box2DHelper::CreateBox(world, WIDTH / 2.0f, HEIGHT / 2.0f, 50.0f, 50.0f, friction);

    // Renderizador
    SFMLRenderer renderer(window, world);

    // Bucle principal
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Aplicar fuerza según la entrada del usuario
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            box->ApplyForceToCenter(b2Vec2(-5.0f * box->GetMass(), 0.0f), true);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            box->ApplyForceToCenter(b2Vec2(5.0f * box->GetMass(), 0.0f), true);
        }

        // Actualizar simulación
        world.Step(1.0f / 60.0f, 8, 3);

        // Dibujar escena
        window.clear();
        renderer.RenderBody(box, sf::Color::Red);
        renderer.RenderBody(ground, sf::Color::Blue);
        window.display();
    }

    return 0;
}
