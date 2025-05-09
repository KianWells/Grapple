#pragma once

#include "GameScene.h"

class MainGame : public GameScene {
public:
	MainGame(EntityManager* entityManager) : GameScene(entityManager) {}


	void init() override;
private:
	void initPlayer();
	void initAssets();
	void initMap();
};