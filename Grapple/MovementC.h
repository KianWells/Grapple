#pragma once
#include "Component.h"
#include "Vector2D.h"
#include "TransformC.h"

class MovementC : public Component {
public:
	MovementC(float speed) {
		this->speed = speed;
	}
	~MovementC(){}

	void init() override {
		velocity.zeroes();
		transform = &entity->getComponent<TransformC>();
	}

	void update() override {
		transform->position = transform->position + velocity;
	}

	Vector2D velocity;
	float speed;

private:
	TransformC* transform;
};