#pragma once
#include "Component.h"
#include "TextureManager.h"
#include "AssetManager.h"
#include "TransformC.h"
#include <string>

class SpriteC : public Component {
public:
	SpriteC(std::string id) {
		texture = Game::assets->getTexture(id);
		src.x = src.y = 0;
	}
	
	SpriteC(std::string id, int srcX, int srcY) {
		texture = Game::assets->getTexture(id);
		src.x = srcX;
		src.y = srcY;
	}

	void init() override {
		if (entity->hasComponent<TransformC>()) {
			transform = &entity->getComponent<TransformC>();
		}
		else {
			transform = &entity->addComponent<TransformC>();
		}
		src.w = transform->width;
		src.h = transform->height;
	}

	void update() override {
		dest.w = transform->width * transform->scale.x();
		dest.h = transform->height * transform->scale.y();
		dest.x = static_cast<int>(transform->position.x()) - Game::camera.x;
		dest.y = static_cast<int>(transform->position.y()) - Game::camera.y;
	}

	void draw() override {
		TextureManager::drawTexture(texture, src, dest, SDL_FLIP_NONE);
	}
private:
	TransformC* transform;
	SDL_Texture* texture;
	SDL_Rect src, dest;
};