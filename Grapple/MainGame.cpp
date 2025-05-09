#include "MainGame.h"
#include "Components.h"
#include "Game.h"
#include "AssetManager.h"
#include "GlobalConsts.h"

void MainGame::init() {
	initAssets();
	initMap();
	initPlayer();
	
}
 
void MainGame::initPlayer() {
	auto& player(entityManager->addEntity());
	player.addComponent<TransformC>(200,200, 32, 32);
	player.addComponent<MovementC>(3);
	player.addComponent<PlayerInputC>();
	player.addComponent<SpriteC>("player");
	player.addComponent<ColliderC>(true);
	player.addGroup(GlobalConsts::groupPlayers);
}

void MainGame::initAssets() {
	Game::assets->addTexture("player", "assets/Player.png");
	Game::assets->addTexture("tilemap", "assets/Tileset.png");
}

void MainGame::initMap() {
	for (int x = 0; x < 20; x++) {
		for (int y = 0; y < 20; y++) {
			auto& tile(entityManager->addEntity());
			tile.addComponent<TransformC>(x * 32, y * 32, 32, 32);
			tile.addComponent<SpriteC>("tilemap");
			tile.addGroup(GlobalConsts::groupMap);
		}
	}

	auto& cTile(entityManager->addEntity());
	cTile.addComponent<TransformC>(25 * 32, 25 * 32, 32, 32);
	cTile.addComponent<SpriteC>("tilemap");
	cTile.addComponent<ColliderC>(false);
	cTile.addGroup(GlobalConsts::groupMap);

}