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
	for (auto i(0u); i < MAX_GROUPS; i++)
	{
		auto& v(groupedEntities[i]);
		v.erase(
			std::remove_if(std::begin(v), std::end(v),
				[i](Entity* mEntity)
				{
					return !mEntity->isActive() || !mEntity->inGroup(i);
				}),
			std::end(v));
	}

	entities.erase(std::remove_if(std::begin(entities), std::end(entities),
		[](const std::unique_ptr<Entity>& mEntity)
		{
			return !mEntity->isActive();
		}),
		std::end(entities));
}

Entity& EntityManager::addEntity()
{
	Entity* e = new Entity(*this);
	std::unique_ptr<Entity> uPtr{ e };
	entities.emplace_back(std::move(uPtr));
	return *e;
}

void EntityManager::addGroup(Entity& entity, Group g) {
	groupedEntities[g].emplace_back(&entity);
}