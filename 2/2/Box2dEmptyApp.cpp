#include "Box2dEmptyApp.h"

Box2dEmptyApp::Box2dEmptyApp()
    : window(sf::VideoMode(800, 600), "Box2D + SFML"),
    world(b2Vec2(0.0f, 9.8f)) { // Gravedad

    // Crear pelota
    b2BodyDef ballDef;
    ballDef.type = b2_dynamicBody;
    ballDef.position.Set(400.0f / 30.0f, 100.0f / 30.0f);
    ball = world.CreateBody(&ballDef);

    b2CircleShape circle;
    circle.m_radius = 15.0f / 30.0f;

    b2FixtureDef ballFixture;
    ballFixture.shape = &circle;
    ballFixture.density = 1.0f;
    ballFixture.restitution = 0.8f;
    ball->CreateFixture(&ballFixture);

    // Crear suelo
    b2BodyDef groundDef;
    groundDef.position.Set(400.0f / 30.0f, 550.0f / 30.0f);
    ground = world.CreateBody(&groundDef);

    b2PolygonShape groundBox;
    groundBox.SetAsBox(400.0f / 30.0f, 10.0f / 30.0f);
    ground->CreateFixture(&groundBox, 0.0f);
}

void Box2dEmptyApp::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Box2dEmptyApp::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void Box2dEmptyApp::update() {
    world.Step(1.0f / 60.0f, 8, 3);
}

void Box2dEmptyApp::render() {
    window.clear();
    SFMLRenderer::drawCircle(window, ball, 15.0f, sf::Color::Red);
    SFMLRenderer::drawRectangle(window, ground, 800.0f, 20.0f, sf::Color::Blue);
    window.display();
}
