#include "projectile_shoot_process.h"
#include <cstring>
#include <iostream>

namespace gun {

void ProjectileShootProcess::onContact(const physx::PxContactPairHeader& pairHeader, const physx::PxContactPair* pairs, physx::PxU32 nbPairs) {
	for (physx::PxU32 i = 0; i < nbPairs; i++) {
		const physx::PxContactPair& cp = pairs[i];
		if (cp.events & physx::PxPairFlag::eNOTIFY_TOUCH_FOUND) {
			physx::PxActor* target;
			physx::PxActor* bullet;
			if (!strncmp(pairHeader.actors[0]->getName(), "bullet", strlen("bullet"))) {
				bullet = pairHeader.actors[0];
				target = pairHeader.actors[1];
			}
			else if (strncmp(pairHeader.actors[1]->getName(), "bullet", strlen("bullet"))) {
				target = pairHeader.actors[0];
				bullet = pairHeader.actors[1];
			}
			else 
				continue;
			TargetInfo info;
			info.id_ = target->getName();
			info.distance_ = 0;
			std::string bulletName = bullet->getName();
			targets_.push_back(std::make_pair(bulletName, info));
		}
	}
}


std::vector<std::pair<std::string, TargetInfo>>&& ProjectileShootProcess::getTargets() {
	return std::move(this->targets_);
}

} // namespace gun
