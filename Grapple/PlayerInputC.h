#pragma once
#include "Component.h"
#include "MovementC.h"
//TODO: fix this as it breaks the ray colliding
class PlayerInputC : public Component {
public:
	PlayerInputC() {}
	~PlayerInputC() {}

	void init() override {
		movement = &entity->safeGetComponent<MovementC>();
	}

	void handleInput(SDL_Event& event) override{
		if (event.type == SDL_KEYDOWN) {
			switch (event.key.keysym.sym) {
			case SDLK_w:
				movement->velocity.y = -1;
				break;
			case SDLK_a:
				movement->velocity.x = -1;
				break;
			case SDLK_s:
				movement->velocity.y = 1;
				break;
			case SDLK_d:
				movement->velocity.x = 1;
				break;
			}

		}

		if (event.type == SDL_KEYUP) {
			switch (event.key.keysym.sym) {
			case SDLK_w:
				movement->velocity.y = 0;
				break;
			case SDLK_a:
				movement->velocity.x = 0;
				break;
			case SDLK_s:
				movement->velocity.y = 0;
				break;
			case SDLK_d:
				movement->velocity.x = 0;
				break;
			}

		}
	}
private:
	MovementC* movement;
};