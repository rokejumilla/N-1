#ifndef PLANEOBJECT_H
#define PLANEOBJECT_H

#include "GameObject.h"

class PlaneObject : public GameObject {
public:
    PlaneObject(b2World& world, float x, float y, float angle, float scale);
};

#endif

