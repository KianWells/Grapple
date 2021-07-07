#pragma once

#include "Component.h"
#include "SpriteC.h"

class ScrollingC : public Component {
public:
	ScrollingC() {}

	void init() override {
		if (entity->hasComponent<TransformC>()) {
			transform = &entity->getComponent<TransformC>();
		}
		else {
			transform = &entity->addComponent<TransformC>();
		}
		if (entity->hasComponent<SpriteC>()) {
			sprite = &entity->getComponent<SpriteC>();
		}
		else {
			sprite = &entity->addComponent<SpriteC>("default");
		}
	}

	void update() override {
		if (Game::camera.x > sprite->dest.w + transform->position.x()) {
			transform->position.x() += sprite->dest.w + Game::camera.w;
		}
	}
private:
	TransformC* transform;
	SpriteC* sprite;
};