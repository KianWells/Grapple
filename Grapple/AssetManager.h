#pragma once

#include <map>
#include <string>
#include <SDL.h>
#include "Image.h"

class AssetManager {
public:
	AssetManager() {}
	~AssetManager() {}

	void addTexture(std::string id, const char* path, int w, int h);

	SDL_Texture* getTexture(std::string id);
	Image* getImage(std::string id);
private:
	std::map<std::string, Image*> imageMap;
};