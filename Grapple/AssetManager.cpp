#include "AssetManager.h"

void AssetManager::addTexture(std::string id, const char* path, int w, int h) {
	imageMap.emplace(id, new Image(path, w, h));
}

SDL_Texture* AssetManager::getTexture(std::string id) {
	return imageMap.at(id)->texture;
}

Image* AssetManager::getImage(std::string id) {
	return imageMap.at(id);
}