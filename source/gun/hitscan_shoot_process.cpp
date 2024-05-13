#include "hitscan_shoot_process.h"
#include <iostream>

namespace gun {

TargetInfo HitscanShootProcess::OnShoot(const SourceInfo& source, physx::PxScene* scene, physx::PxQueryFilterData filterData) {
	physx::PxRaycastBuffer hit;

	TargetInfo targetInfo;
	if (scene->raycast(source.position_, source.direction_, source.max_distance_, hit, physx::PxHitFlag::eDEFAULT, filterData)) {
		if (hit.hasBlock) {
			targetInfo.distance_ = hit.block.distance;
			targetInfo.id_ = hit.block.actor->getName();
		}
	} else {
		targetInfo.distance_ = source.max_distance_;
		targetInfo.id_ = "";
	}
	return targetInfo;
}

} // namespace gun
