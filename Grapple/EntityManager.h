#pragma once
#include <vector>
#include <memory>
#include <SDL.h>
#include "ECS.h"

class Entity;
class EntityManager {
public:
	EntityManager() {}
	~EntityManager() {}

	void handleInput(SDL_Event& event);
	void update();
	void draw();
	void refresh();

	Entity& addEntity();
	void addGroup(Entity& entity, Group g);
	std::vector<Entity*>& getGroup(Group g) {
		return groupedEntities[g];
	}

private:
	std::vector<std::unique_ptr<Entity>> entities;
	std::array<std::vector<Entity*>, MAX_GROUPS> groupedEntities;
};