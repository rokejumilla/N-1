#ifndef BOX2DHELPER_H
#define BOX2DHELPER_H

#include <Box2D/Box2D.h>

class Box2DHelper {
public:
    static b2Body* CreateRectangularStaticBody(b2World* world, float width, float height, b2Vec2 position) {
        b2BodyDef bodyDef;
        bodyDef.position = position;
        bodyDef.type = b2_staticBody;
        b2Body* body = world->CreateBody(&bodyDef);
        b2PolygonShape box;
        box.SetAsBox(width / 2, height / 2);
        body->CreateFixture(&box, 0.0f);
        return body;
    }

    static b2Body* CreateCircularDynamicBody(b2World* world, float radius, float density, float friction, float restitution, b2Vec2 position) {
        b2BodyDef bodyDef;
        bodyDef.type = b2_dynamicBody;
        bodyDef.position = position;
        b2Body* body = world->CreateBody(&bodyDef);
        b2CircleShape circle;
        circle.m_radius = radius;
        b2FixtureDef fixtureDef;
        fixtureDef.shape = &circle;
        fixtureDef.density = density;
        fixtureDef.friction = friction;
        fixtureDef.restitution = restitution;
        body->CreateFixture(&fixtureDef);
        return body;
    }
};

#endif // BOX2DHELPER_H
