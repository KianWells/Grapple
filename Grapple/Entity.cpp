#include "Entity.h"
#include "EntityManager.h"

void Entity::addGroup(Group g) {
	groupBitset[g] = true;
	manager.addGroup(*this, g);
}