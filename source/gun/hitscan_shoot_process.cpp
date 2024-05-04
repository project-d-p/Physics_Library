#include "hitscan_shoot_process.h"

namespace gun {

TargetInfo HitscanShootProcess::OnShoot(const SourceInfo& source, physx::PxScene* scene, physx::PxQueryFilterData filterData) {
	physx::PxRaycastBuffer hit;

	TargetInfo targetInfo;
	if (scene->raycast(source.position, source.direction, source.maxDistance, hit, physx::PxHitFlag::eDEFAULT, filterData)) {
		if (hit.hasBlock) {
			targetInfo.distance_ = hit.block.distance;
			targetInfo.id_ = hit.block.actor->getName();
		}
	} else {
		targetInfo.distance_ = source.maxDistance;
		targetInfo.id_ = "";
	}
	return targetInfo;
}

} // namespace gun
