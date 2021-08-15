#pragma once
#include "Component.h"
#include "MovementC.h"

class GrappleMouseC : public Component {
public:
	GrappleMouseC() {}
	~GrappleMouseC() {}

	void init() override {
		movement = &entity->safeGetComponent<MovementC>();
		rayCol = &entity->safeGetComponent<RayColliderC>();
		transform = &entity->safeGetComponent<TransformC>();
	}

	void handleInput(SDL_Event& event) override {
		if (event.type == SDL_MOUSEBUTTONDOWN && down == false) {
			down = true;
			SDL_GetMouseState(&x, &y);
			x += Game::camera.x;
			y += Game::camera.y;
			std::cout << x << ", " << y << std::endl;
		}
		if (event.type == SDL_MOUSEBUTTONUP) {
			down = false;
		}
	}

	void update() override {
		if (down) {
			//work out direction


			// Sort collisions in order of distance
			Vector2D cp, cn;
			float t = 0, min_t = INFINITY;

			finalPoint = { 0,0 };

			Vector2D origin(
				transform->position.x + transform->width / 2,
				transform->position.y + transform->width / 2
			);

			Vector2D direction(
				x - origin.x,
				y - origin.y
			);

			// Work out collision point, add it to vector along with rect ID
			for (auto c : entity->getManager().getGroup(GlobalConsts::groupColliders)) {
				if (rayCol->RayVsRect(origin, direction, c->getComponent<ColliderC>().colliderBox, t, cp, cn))
				{
					if (t < min_t) {
						min_t = t;
						finalPoint = cp;
					}
				}
			}

			movement->velocity = (finalPoint - origin).perpendicular() * movement->maxSpeed;
		}
		else {
			movement->velocity = Vector2D(0, 0);
		}
	}

	void draw() override {

	}

private:
	Vector2D finalPoint;
	int x, y;
	bool down = false;
	TransformC* transform;
	MovementC* movement;
	RayColliderC* rayCol;
};