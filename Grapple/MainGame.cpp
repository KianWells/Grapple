#include "MainGame.h"
#include "Components.h"
#include "Game.h"
#include "AssetManager.h"
void MainGame::init() {
	initAssets();
	initPlayer();
}

void MainGame::initPlayer() {
	auto& player = entityManager->addEntity();
	player.addComponent<TransformC>(200,200,5,5);
	player.addComponent<MovementC>(3);
	player.addComponent<PlayerInputC>();
	player.addComponent<SpriteC>("player", 32, 32);
}

void MainGame::initAssets() {
	Game::assets->addTexture("player", "assets/Player.png");
}