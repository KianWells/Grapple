#pragma once

#include "Component.h"
#include "SpriteC.h"

class ScrollingC : public Component {
public:
	ScrollingC() {}

	void init() override {
		transform = &entity->safeGetComponent<TransformC>();
		sprite = &entity->safeGetComponent<SpriteC>();
	}

	void update() override {
		if (Game::camera.x > sprite->dest.w + transform->position.x) {
			transform->position.x += sprite->dest.w + Game::camera.w;
		}
	}
private:
	TransformC* transform;
	SpriteC* sprite;
};