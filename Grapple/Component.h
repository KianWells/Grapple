#pragma once
#include "Entity.h"
#include <SDL.h>

class Component {
public:
    Component() = default;
    virtual ~Component() = default;

    Entity* entity;

    virtual void init() {}
    virtual void handleInput(SDL_Event& event) {}
    virtual void update() {}
    virtual void draw() {}
};