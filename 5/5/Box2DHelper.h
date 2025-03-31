#ifndef BOX2DHELPER_H
#define BOX2DHELPER_H

#include <Box2D/Box2D.h>

class Box2DHelper {
public:
    // Crear un plano inclinado
    static b2Body* CreateInclinedPlane(b2World& world, float x, float y, float angle);

    // Crear una caja
    static b2Body* CreateBox(b2World& world, float x, float y, float width, float height, float friction);
};

#endif
