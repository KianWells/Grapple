#include "AssetManager.h"
#include "TextureManager.h"

void AssetManager::addTexture(std::string id, const char* path) {
	textureMap.emplace(id, TextureManager::loadTexture(path));
}

SDL_Texture* AssetManager::getTexture(std::string id) {
	return textureMap.at(id);
}