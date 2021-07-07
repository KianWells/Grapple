#pragma once
#include "ECS.h"
#include <vector>
#include <memory>
#include "Component.h"
#include <iostream>
#include "EntityManager.h"

class Entity {
public:
    Entity(EntityManager& eManager) : manager(eManager) {}
    virtual ~Entity() = default;

    template<typename T, typename... TArgs>
    inline T& addComponent(TArgs&&... args) {
        if (compBitset[getComponentTypeID<T>()]) {
            std::cout << "Entity already has component" << std::endl;
            return *static_cast<T*>(nullptr);
        }
        T* c(new T(std::forward<TArgs>(args)...));
        c->entity = this;
        compArr[getComponentTypeID<T>()] = c;
        compBitset[getComponentTypeID<T>()] = true;

        std::unique_ptr<Component> uptr{ c };
        components.emplace_back(std::move(uptr));

        c->init();

        return *c;
    }

    template<typename T>
    inline T& getComponent() {
        auto ptr(compArr[getComponentTypeID<T>()]);
        return *static_cast<T*>(ptr);
    }

    template<typename T>
    inline bool hasComponent(){
        return compBitset[getComponentTypeID<T>()];
    }

    EntityManager& getManager() {
        return manager;
    }

    void addGroup(Group g);

    bool inGroup(Group g) {
        return groupBitset[g];
    }

    void handleInput(SDL_Event& event) {
        for (auto& c : components) {
            c->handleInput(event);
        }
    }

    void update() {
        for (auto& c : components) {
            c->update();
        }
    }

    void draw() {
        for (auto& c : components) {
            c->draw();
        }
    }

    bool isActive() {
        return active;
    }

private:
    std::vector<std::unique_ptr<Component>> components;
    ComponentArray compArr;
    ComponentBitset compBitset;
    GroupBitset groupBitset;
    EntityManager& manager;
    bool active = true;
};