#pragma once

#include "Component.h"
#include "MovementC.h"
#include "GlobalConsts.h"
#include "ColliderC.h"
#include <algorithm>

class RayColliderC : public Component {
public:
	RayColliderC() {}
	~RayColliderC() {}
	void init() override {
		transform = &entity->safeGetComponent<TransformC>();
		movement = &entity->safeGetComponent<MovementC>();
	}

	int x, y;
	bool hold;

	void update() override {
		//for (auto c : entity->getManager().getGroup(GlobalConsts::groupColliders)) {
		//	if (c != entity) {
		//		if (SDL_GetMouseState(&x, &y) & SDL_BUTTON(1)) {
		//			movement->velocity = Vector2D(((x + Game::camera.x) - transform->position.x) / 20, ((y + Game::camera.y) - transform->position.y) / 20);
		//		}
		//		//ResolveMovingRectVsRect(c->getComponent<ColliderC>().colliderBox);
		//	}
		//}

		// Sort collisions in order of distance
		Vector2D cp, cn;
		float t = 0, min_t = INFINITY;
		std::vector<std::pair<SDL_Rect, float>> z;

		// Work out collision point, add it to vector along with rect ID
		for (auto c : entity->getManager().getGroup(GlobalConsts::groupColliders)) {
			if (MovingRectVsRect(c->getComponent<ColliderC>().colliderBox, t, cp, cn))
			{
				z.push_back({ c->getComponent<ColliderC>().colliderBox, t });
			}
		}
		
			
		

		// Do the sort
		std::sort(z.begin(), z.end(), [](const std::pair<SDL_Rect, float>& a, const std::pair<SDL_Rect, float>& b)
			{
				return a.second < b.second;
			});

		// Now resolve the collision in correct order 
		for (auto j : z)
			ResolveMovingRectVsRect(j.first);

	}

	void draw() override {
		SDL_SetRenderDrawColor(Game::renderer, 0, 0, 0, 255);
		SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, 255);
	}

	
	bool RayVsRect(Vector2D& origin, Vector2D& direction, SDL_Rect& target, float& contactTime, Vector2D& contactPoint, Vector2D& normal) {
		//initialise the return values to zero
		contactTime = 0.0f;
		contactPoint.zeroes();
		normal.zeroes();

		Vector2D invDir(1 / direction.x, 1 / direction.y);

		//work out time near for x and y
		Vector2D tNear(
			(target.x - origin.x) * invDir.x,
			(target.y - origin.y) * invDir.y
		);

		//work out time far for x and y
		Vector2D tFar(
			(target.x - origin.x + target.w) * invDir.x,
			(target.y - origin.y + target.h) * invDir.y
		);

		if (std::isnan(tNear.x) || std::isnan(tNear.y)) return false;
		if (std::isnan(tFar.x) || std::isnan(tFar.y)) return false;

		// Sort distances
		if (tNear.x > tFar.x) std::swap(tNear.x, tFar.x);
		if (tNear.y > tFar.y) std::swap(tNear.y, tFar.y);

		// Early rejection		
		if (tNear.x > tFar.y || tNear.y > tFar.x) return false;

		// Closest 'time' will be the first contact
		contactTime = std::max(tNear.x, tNear.y);

		// Furthest 'time' is contact on opposite side of target
		float tContactFar = std::min(tFar.x, tFar.y);

		// Reject if ray direction is pointing away from object
		if (tContactFar < 0)
			return false;

		// Contact point of collision from parametric line equation
		Vector2D intersectDir(
			contactTime * direction.x,
			contactTime * direction.y);

		contactPoint = origin + intersectDir;

		if (tNear.x > tNear.y)
			if (invDir.x < 0)
				normal = { 1, 0 };
			else
				normal = { -1, 0 };
		else if (tNear.x < tNear.y)
			if (invDir.y < 0)
				normal = { 0, 1 };
			else
				normal = { 0, -1 };

		// Note if tNear == tFar, collision is principly in a diagonal
		// so pointless to resolve. By returning a CN={0,0} even though its
		// considered a hit, the resolver wont change anything.
		return true;
	}

	bool MovingRectVsRect(SDL_Rect& target, float& contactTime, Vector2D& contactPoint, Vector2D& normal) {
		Vector2D origin(
			transform->position.x + transform->width/2,
			transform->position.y + transform->width/2
		);
		Vector2D velocity = movement->velocity;

		if (velocity.x == 0 && velocity.y == 0)
			return false;

		SDL_Rect expandedTarget{};
		expandedTarget.x = target.x - transform->width / 2;
		expandedTarget.y = target.y - transform->height / 2;
		expandedTarget.w = target.w + transform->width;
		expandedTarget.h = target. h + transform->height;

		if (RayVsRect(origin, velocity, expandedTarget, contactTime, contactPoint, normal)) {
			return (contactTime >= 0.0f && contactTime < 1.0f);
		}
		
		return false;
	}

	bool ResolveMovingRectVsRect(SDL_Rect& target) {
		Vector2D contactPoint, normal;
		float contactTime = 0.0f;
		if (MovingRectVsRect(target, contactTime, contactPoint, normal))
		{
			//movement->velocity.zeroes();
			//std::cout << "Normal: " << normal << ", Velocity: " << movement->velocity << std::endl;
			movement->velocity.x += std::abs(movement->velocity.x) * normal.x * (1 - contactTime);
			movement->velocity.y += std::abs(movement->velocity.y) * normal.y * (1 - contactTime);
			//std::cout << "New Velocity: " << movement->velocity << std::endl;
			return true;
		}

		return false;
	}
private:
	TransformC* transform;
	MovementC* movement;
};