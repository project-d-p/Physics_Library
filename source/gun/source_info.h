#pragma once

#include "PxPhysicsAPI.h"

namespace gun {

struct SourceInfo {
	physx::PxVec3 position;
	physx::PxVec3 direction;
	float maxDistance;
};

} // namespace gun
