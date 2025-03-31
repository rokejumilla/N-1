#ifndef BOXOBJECT_H
#define BOXOBJECT_H

#include "GameObject.h"

class BoxObject : public GameObject {
public:
    BoxObject(b2World& world, float x, float y, float scale);
};

#endif
