#pragma once

#include "target_info.h"
#include "source_info.h"
#include "PxPhysicsAPI.h"

namespace gun {

class HitscanShootProcess {
public:
	static TargetInfo OnShoot(const SourceInfo& source, physx::PxScene* scene, physx::PxQueryFilterData filterData);
};

} // namespace gun
