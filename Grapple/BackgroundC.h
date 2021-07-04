#pragma once

#include "Component.h"
#include "SpriteC.h"

class BackgroundC : public Component {
public:
	BackgroundC(std::string id, int w, int h) {
		bg = Game::assets->getTexture(id);
		src.x = src.y = 0;
		src.w = w;
		src.h = h;
		std::cout << "created" << std::endl;
	}

	void init() override {
		entity->addGroup(GlobalConsts::groupBackground);
		dest1.x = 0;
		dest1.y = dest2.y = 0;
		dest1.w = dest2.w = Game::camera.w;
		dest1.h = dest2.h = Game::camera.h;
		dest2.x = dest1.x + dest2.w;
		i = 0;
		std::cout << dest1.x << "," << dest1.y << "," << dest1.w << "," << dest1.h << std::endl;
	}

	void update() override {
		dest1.x = i*dest1.w -Game::camera.x;
		dest2.x = dest1.x + dest1.w;
		if (dest1.x < - dest1.w) {
			std::cout << dest1.x << "," << dest1.y << "," << dest1.w << "," << dest1.h << std::endl;
			dest1.x = dest2.x + dest2.w;
			SDL_Rect temp;
			temp = dest1;
			dest1 = dest2;
			dest2 = temp;
			i++;
			std::cout << dest1.x << "," << dest1.y << "," << dest1.w << "," << dest1.h << std::endl;
		}
	}

	void draw() override {
		TextureManager::drawTexture(bg, src, dest1, SDL_FLIP_NONE);
		TextureManager::drawTexture(bg, src, dest2, SDL_FLIP_NONE);
	}


	
private:
	SDL_Texture* bg;
	SDL_Rect src, dest1, dest2;
	int i;
};