#pragma once

#include <bitset>
#include <array>

class Entity;
class Component;

using ComponentID = std::size_t;
using Group = std::size_t;

inline ComponentID getUniqueComponentID() {
    static ComponentID id = 0u;
    return id++;
}

template<typename T>
inline ComponentID getComponentTypeID() {
    static const ComponentID typeID = getUniqueComponentID();
    return typeID;
}

constexpr size_t MAX_ENTITIES = 5000;
constexpr size_t MAX_COMPONENTS = 32;
constexpr size_t MAX_GROUPS = 32;

using ComponentArray = std::array<Component*, MAX_COMPONENTS>;
using ComponentBitset = std::bitset<MAX_COMPONENTS>;
using GroupBitset = std::bitset<MAX_GROUPS>;