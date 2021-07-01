#include "MainGame.h"
#include "Components.h"
#include "Game.h"
#include "AssetManager.h"
void MainGame::init() {
	initAssets();
	initMap();
	initPlayer();
	
}
 
void MainGame::initPlayer() {
	auto& player(entityManager->addEntity());
	player.addComponent<TransformC>(200,200,5,5);
	player.addComponent<MovementC>(3);
	player.addComponent<PlayerInputC>();
	player.addComponent<SpriteC>("player", 32, 32);
	player.addGroup(groupPlayers);
}

void MainGame::initAssets() {
	Game::assets->addTexture("player", "assets/Player.png");
	Game::assets->addTexture("tilemap", "assets/Tileset.png");
}

void MainGame::initMap() {
	for (int x = 0; x < 20; x++) {
		for (int y = 0; y < 20; y++) {
			auto& tile(entityManager->addEntity());
			tile.addComponent<TransformC>(x * 32, y * 32);
			tile.addComponent<SpriteC>("tilemap", 32, 32);
			tile.addGroup(groupMap);
		}
	}
}