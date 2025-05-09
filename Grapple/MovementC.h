#pragma once
#include "Component.h"
#include "Vector2D.h"
#include "TransformC.h"

class MovementC : public Component {
public:
	MovementC(float maxSpeed) {
		this->maxSpeed = maxSpeed;
	}
	~MovementC(){}

	void init() override {
		velocity.zeroes();
		acceleration = 0.1;
		transform = &entity->getComponent<TransformC>();
	}

	void update() override {
		transform->oldPosition = transform->position;
		transform->position = transform->position + velocity;
	}

	Vector2D velocity;
	float maxSpeed, acceleration;

private:
	TransformC* transform;
};