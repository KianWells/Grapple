#pragma once

#include <SDL.h>
#include "TextureManager.h"

class Image {
public:
	Image(const char* path, int w, int h)
	{
		texture = TextureManager::loadTexture(path);
		this->w = w;
		this->h = h;
	}

	SDL_Texture* texture;
	int w;
	int h;
};