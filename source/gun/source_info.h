#pragma once

#include "PxPhysicsAPI.h"

namespace gun {

struct SourceInfo {
	physx::PxVec3 position_;
	physx::PxVec3 direction_;
	float max_distance_;
};

} // namespace gun
