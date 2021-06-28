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
    }

    TransformC(float x, float y) {
        position = Vector2D(x, y);
        scale.ones();
        rotation = 0;
    }

    TransformC(float x, float y, float scaleX, float scaleY) {
        position = Vector2D(x, y);
        scale = Vector2D(scaleX, scaleY);
        rotation = 0;
    }

    ~TransformC() {};

    void update() override {
        std::cout << position << std::endl;
    }


    Vector2D position;
    Vector2D scale;
    float rotation;
};