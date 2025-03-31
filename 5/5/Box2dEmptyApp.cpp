#include "Box2DHelper.h"

b2Body* Box2DHelper::CreateInclinedPlane(b2World& world, float x, float y, float angle) {
    b2BodyDef groundDef;
    groundDef.position.Set(x, y);
    groundDef.angle = -angle * b2_pi / 180.0f; // Convertir a radianes
    b2Body* groundBody = world.CreateBody(&groundDef);

    b2PolygonShape groundBox;
    groundBox.SetAsBox(10.0f, 0.5f);
    groundBody->CreateFixture(&groundBox, 0.0f);

    return groundBody;
}

b2Body* Box2DHelper::CreateBox(b2World& world, float x, float y, float width, float height, float friction) {
    b2BodyDef boxDef;
    boxDef.type = b2_dynamicBody;
    boxDef.position.Set(x, y);
    b2Body* boxBody = world.CreateBody(&boxDef);

    b2PolygonShape boxShape;
    boxShape.SetAsBox(width / 2, height / 2);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &boxShape;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = friction;
    boxBody->CreateFixture(&fixtureDef);

    return boxBody;
}
