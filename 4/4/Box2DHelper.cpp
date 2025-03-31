#include "Box2DHelper.h"

b2Body* Box2DHelper::CreateBox(b2World& world, float x, float y, float width, float height, float friction) {
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(x / 30.0f, y / 30.0f);
    b2Body* body = world.CreateBody(&bodyDef);

    b2PolygonShape shape;
    shape.SetAsBox((width / 2) / 30.0f, (height / 2) / 30.0f);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &shape;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = friction;

    body->CreateFixture(&fixtureDef);
    return body;
}

b2Body* Box2DHelper::CreateGround(b2World& world, float x, float y, float width, float height) {
    b2BodyDef bodyDef;
    bodyDef.position.Set(x / 30.0f, y / 30.0f);
    b2Body* body = world.CreateBody(&bodyDef);

    b2PolygonShape shape;
    shape.SetAsBox((width / 2) / 30.0f, (height / 2) / 30.0f);

    body->CreateFixture(&shape, 0.0f);
    return body;
}
