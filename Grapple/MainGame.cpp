#include "MainGame.h"
#include "Components.h"
#include "Game.h"
#include "AssetManager.h"
#include "GlobalConsts.h"

void MainGame::init() {
	initAssets();
	initBackground();
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
	//player.addComponent<GravityC>();
	player.addGroup(GlobalConsts::groupPlayers);
}

void MainGame::initAssets() {
	Game::assets->addTexture("default", "assets/Player.png", 32, 32);
	Game::assets->addTexture("player", "assets/Player.png", 32, 32);
	Game::assets->addTexture("tilemap", "assets/Tileset.png", 32, 32);
	Game::assets->addTexture("background", "assets/ScrollingBackground.png", 200, 200);
}

void MainGame::initMap() {
	std::cout << Game::camera.w << std::endl;
	for (int x = 0; x < Game::camera.w*2/32; x++) {
		auto& tileT(entityManager->addEntity());
		auto& tileB(entityManager->addEntity());
		tileT.addComponent<TransformC>(x * Game::assets->getImage("tilemap")->w, 0, Game::assets->getImage("tilemap")->w, Game::assets->getImage("tilemap")->h);
		tileB.addComponent<TransformC>(x * Game::assets->getImage("tilemap")->w, Game::camera.h - Game::assets->getImage("tilemap")->h, Game::assets->getImage("tilemap")->w, Game::assets->getImage("tilemap")->h);
		tileT.addComponent<SpriteC>("tilemap");
		tileB.addComponent<SpriteC>("tilemap");
		tileT.addGroup(GlobalConsts::groupMap);
		tileB.addGroup(GlobalConsts::groupMap);
		tileT.addComponent<ColliderC>(false);
		tileB.addComponent<ColliderC>(false);
		tileT.addComponent<ScrollingC>();
		tileB.addComponent<ScrollingC>();
	}

	auto& cTile(entityManager->addEntity());
	cTile.addComponent<TransformC>(60 * 32, 5 * 32, 32, 32);
	cTile.addComponent<SpriteC>("tilemap", 32, 0);
	cTile.addComponent<ColliderC>(false);
	cTile.addGroup(GlobalConsts::groupMap);
}

void MainGame::initBackground() {
	for (int x = 0; x < 2; x++) {
		auto& bg(entityManager->addEntity());
		bg.addComponent<TransformC>(x * Game::camera.w, 
			0,
			Game::camera.w / Game::assets->getImage("background")->w, 
			Game::camera.h / Game::assets->getImage("background")->h, 
			Game::assets->getImage("background")->w, 
			Game::assets->getImage("background")->h);
		bg.addComponent<SpriteC>("background");
		bg.addGroup(GlobalConsts::groupBackground);
		bg.addComponent<ScrollingC>();
	}
}