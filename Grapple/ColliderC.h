#pragma once

#include "Component.h"
#include "TransformC.h"
#include "GlobalConsts.h"

class ColliderC : public Component {
public:
	ColliderC(bool moving) : movingCollider(moving) {}

	ColliderC() {
		ColliderC(false);
	}

	void init() override {
		transform = &entity->safeGetComponent<TransformC>();
		colliderBox.w = transform->width * transform->scale.x;
		colliderBox.h = transform->height * transform->scale.y;
		if (!entity->inGroup(GlobalConsts::groupColliders)) {
			entity->addGroup(GlobalConsts::groupColliders);
		}
	}

	void update() override{
		colliderBox.x = transform->position.x;
		colliderBox.y = transform->position.y;
		if (movingCollider) {
			for (auto c : entity->getManager().getGroup(GlobalConsts::groupColliders)) {
				if (AABBcheck(c->getComponent<ColliderC>()) == SDL_TRUE && c != entity) {
					transform->position = transform->oldPosition;
				}
			}
		}
	}

	bool AABBcheck(ColliderC& col) {
		return SDL_HasIntersection(&colliderBox, &col.colliderBox);
	}

	SDL_Rect colliderBox;

private:
	bool movingCollider;
	TransformC* transform;
};