#include "BoxObject.h"

BoxObject::BoxObject(b2World& world, float x, float y, float scale)
    : GameObject(world, x, y, 1.0f, 1.0f, true, scale) {}
