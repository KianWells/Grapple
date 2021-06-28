#include "EntityManager.h"
#include "Entity.h"

void EntityManager::handleInput(SDL_Event& event)
{
	for (auto& e : entities) {
		e->handleInput(event);
	}
}

void EntityManager::update()
{
	for (auto& e : entities) {
		e->update();
	}
}

void EntityManager::draw()
{
	for (auto& e : entities) {
		e->draw();
	}
}

void EntityManager::refresh()
{
}

Entity& EntityManager::addEntity()
{
	Entity* e = new Entity();
	std::unique_ptr<Entity> uPtr{ e };
	entities.emplace_back(std::move(uPtr));
	return *e;
}

