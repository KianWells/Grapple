#pragma once
#include <cstddef>

class GlobalConsts {
public:
	static enum groupLabels : std::size_t
	{
		groupMap,
		groupPlayers,
		groupColliders,
		groupProjectiles,
		groupMovingCollider
	};
};