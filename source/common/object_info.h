#pragma once

#include "physx/PxPhysicsAPI.h"
#include <vector>
#include <string>

namespace common {

struct ObjectInfo {
	physx::PxVec3 position_;
	physx::PxVec3 hitbox_;
	physx::PxVec3 velocity_;
	float materia_[3];
	float mass_;
	std::string id_;
};

} // namespace common
