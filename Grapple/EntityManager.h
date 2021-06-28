#pragma once
#include <vector>
#include <memory>
#include <SDL.h>

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

private:
	std::vector<std::unique_ptr<Entity>> entities;
};