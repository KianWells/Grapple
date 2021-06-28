#pragma once

#include <map>
#include <string>
#include <SDL.h>

class AssetManager {
public:
	AssetManager() {}
	~AssetManager() {}

	void addTexture(std::string id, const char* path);

	SDL_Texture* getTexture(std::string id);
private:
	std::map<std::string, SDL_Texture*> textureMap;
};