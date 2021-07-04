#pragma once
#include "Component.h"
#include "Vector2D.h"
#include <iostream>

class TransformC : public Component {
public:
    TransformC() {
        position.zeroes();
        scale.ones();
        rotation = 0.0f;
        width = 0;
        height = 0;
    }

    TransformC(float x, float y, int w, int h) {
        position = Vector2D(x, y);
        scale.ones();
        rotation = 0;
        width = w;
        height = h;
    }

    TransformC(float x, float y, float scaleX, float scaleY, int w, int h) {
        position = Vector2D(x, y);
        scale = Vector2D(scaleX, scaleY);
        rotation = 0;
        width = w;
        height = h;
    }

    ~TransformC() {};

    int width, height;
    Vector2D position;
    Vector2D oldPosition;
    Vector2D scale;
    float rotation;
};