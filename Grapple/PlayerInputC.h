#pragma once
#include "Component.h"
#include "MovementC.h"

class PlayerInputC : public Component {
public:
	PlayerInputC() {}
	~PlayerInputC() {}

	void init() override {
		movement = &entity->getComponent<MovementC>();
	}

	void handleInput(SDL_Event& event) override{
		if (event.type == SDL_KEYDOWN) {
			switch (event.key.keysym.sym) {
			case SDLK_w:
				movement->velocity.y() = -movement->speed;
				break;
			case SDLK_a:
				movement->velocity.x() = -movement->speed;
				break;
			case SDLK_s:
				movement->velocity.y() = movement->speed;
				break;
			case SDLK_d:
				movement->velocity.x() = movement->speed;
				break;
			}

		}

		if (event.type == SDL_KEYUP) {
			switch (event.key.keysym.sym) {
			case SDLK_w:
				movement->velocity.y() = 0;
				break;
			case SDLK_a:
				movement->velocity.x() = 0;
				break;
			case SDLK_s:
				movement->velocity.y() = 0;
				break;
			case SDLK_d:
				movement->velocity.x() = 0;
				break;
			}

		}
	}
private:
	MovementC* movement;
};