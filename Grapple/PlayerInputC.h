#pragma once
#include "Component.h"
#include "MovementC.h"
//TODO: fix issue with stopping and starting
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
				break;
			case SDLK_a:
				break;
			case SDLK_s:
				break;
			case SDLK_d:
				break;
			}

		}

		if (event.type == SDL_KEYUP) {
			switch (event.key.keysym.sym) {
			case SDLK_w:
				break;
			case SDLK_a:
				break;
			case SDLK_s:
				break;
			case SDLK_d:
				break;
			}

		}
	}
private:
	MovementC* movement;
};