#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

// Constantes
const float SCALE = 30.0f; // Factor de escala para dibujar en píxeles
const int WIDTH = 800, HEIGHT = 600;
const float GRAVITY = 0.0f; // Sin gravedad en el eje Y para este ejercicio
const float FRICTION = 0.2f; // Cambiar para probar diferentes coeficientes de fricción

int main() {
    // Ventana
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Ejercicio 4 - Box2D");

    // Mundo Box2D
    b2Vec2 gravity(0.0f, GRAVITY);
    b2World world(gravity);

    // Definir suelo
    b2BodyDef groundDef;
    groundDef.position.Set(WIDTH / (2 * SCALE), HEIGHT / SCALE - 1);
    b2Body* groundBody = world.CreateBody(&groundDef);
    b2PolygonShape groundBox;
    groundBox.SetAsBox(WIDTH / (2 * SCALE), 0.5f);
    groundBody->CreateFixture(&groundBox, 0.0f);

    // Definir caja
    b2BodyDef boxDef;
    boxDef.type = b2_dynamicBody;
    boxDef.position.Set(WIDTH / (2 * SCALE), HEIGHT / SCALE - 2);
    b2Body* boxBody = world.CreateBody(&boxDef);
    b2PolygonShape boxShape;
    boxShape.SetAsBox(1.0f, 1.0f);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &boxShape;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = FRICTION;
    boxBody->CreateFixture(&fixtureDef);

    // Crear representación gráfica del suelo
    sf::RectangleShape ground(sf::Vector2f(WIDTH, SCALE));
    ground.setOrigin(WIDTH / 2, SCALE / 2);
    ground.setPosition(WIDTH / 2, HEIGHT - SCALE);
    ground.setFillColor(sf::Color::Blue);

    // Bucle principal
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Controles - Aplicar fuerza proporcional a la masa
        float force = 10.0f * boxBody->GetMass();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            boxBody->ApplyForceToCenter(b2Vec2(-force, 0.0f), true);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            boxBody->ApplyForceToCenter(b2Vec2(force, 0.0f), true);
        }

        // Actualizar mundo
        world.Step(1.0f / 60.0f, 8, 3);

        // Dibujar escena
        window.clear();

        // Dibujar suelo
        window.draw(ground);

        // Dibujar caja
        sf::RectangleShape box(sf::Vector2f(2 * SCALE, 2 * SCALE));
        box.setOrigin(SCALE, SCALE);
        box.setPosition(boxBody->GetPosition().x * SCALE, boxBody->GetPosition().y * SCALE);
        box.setRotation(boxBody->GetAngle() * 180 / b2_pi);
        box.setFillColor(sf::Color::Red);
        window.draw(box);

        window.display();
    }

    return 0;
}
