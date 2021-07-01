#pragma once
#include "EntityManager.h"
#include "Entity.h"
#include "ECS.h"

class GameScene {
public:
	GameScene(EntityManager* entityManager) {
		this->entityManager = entityManager;
	}
	~GameScene() {}

	virtual void init() = 0;

	enum groupLabels : std::size_t
	{
		groupMap,
		groupPlayers,
		groupColliders,
		groupProjectiles
	};

protected:
	EntityManager* entityManager;
};