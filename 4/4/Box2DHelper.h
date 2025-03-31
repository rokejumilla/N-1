#ifndef BOX2D_HELPER_H
#define BOX2D_HELPER_H

#include <Box2D/Box2D.h>

class Box2DHelper {
public:
    static b2Body* CreateBox(b2World& world, float x, float y, float width, float height, float friction);
    static b2Body* CreateGround(b2World& world, float x, float y, float width, float height);
};

#endif
