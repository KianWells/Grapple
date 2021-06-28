#include "MainGame.h"
#include "Components.h"
void MainGame::init() {
	initPlayer();
}

void MainGame::initPlayer() {
	auto& player = entityManager->addEntity();
	player.addComponent<TransformC>();
	player.addComponent<MovementC>(3);
	player.addComponent<PlayerInputC>();
}