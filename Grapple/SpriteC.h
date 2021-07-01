#pragma once
#include "Component.h"
#include "TextureManager.h"
#include "AssetManager.h"
#include "TransformC.h"
#include <string>

class SpriteC : public Component {
public:
	SpriteC(std::string id, int w, int h) {
		texture = Game::assets->getTexture(id);
		width = w;
		height = h;
		src.x = src.y = 0;
	}
	
	SpriteC(std::string id, int w, int h, int srcX, int srcY) {
		texture = Game::assets->getTexture(id);
		width = w;
		height = h;
		src.x = srcX;
		src.y = srcY;
	}

	void init() override {
		transform = &entity->getComponent<TransformC>();
		src.w = width;
		src.h = height;
	}

	void update() override {
		dest.w = width * transform->scale.x();
		dest.h = height * transform->scale.y();
		dest.x = transform->position.x();
		dest.y = transform->position.y();
	}

	void draw() override {
		TextureManager::drawTexture(texture, src, dest, SDL_FLIP_NONE);
	}
private:
	int width, height;
	TransformC* transform;
	SDL_Texture* texture;
	SDL_Rect src, dest;
};