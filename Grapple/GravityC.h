#pragma once

#include "Component.h"
#include "MovementC.h"

class GravityC : public Component {
public:
	GravityC() {}

	void init() override {
		movement = &entity->getComponent<MovementC>();
	}

	void update() override {
		movement->velocity.y() = gravity;
	}
private:
	float gravity = 3;
	MovementC* movement;
};