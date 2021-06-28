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
	}

	void init() override {
		transform = &entity->getComponent<TransformC>();
		src.x = src.y = 0;
		src.w = src.h = dest.w = dest.h = 32;
	}

	void update() override {
		dest.x = transform->position.x();
		dest.y = transform->position.y();
	}

	void draw() override {
		TextureManager::drawTexture(texture, src, dest, SDL_FLIP_NONE);
	}
private:
	TransformC* transform;
	SDL_Texture* texture;
	SDL_Rect src, dest;
};