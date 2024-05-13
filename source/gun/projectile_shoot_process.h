#pragma once

#include "target_info.h"
#include "PxPhysicsAPI.h"
#include <vector>
#include <utility>
#include <string>

namespace gun {

class ProjectileShootProcess : public physx::PxSimulationEventCallback {
private:
	std::vector<std::pair<std::string, TargetInfo>> targets_;
public:
	void onContact(const physx::PxContactPairHeader& pairHeader, const physx::PxContactPair* pairs, physx::PxU32 nbPairs) override;
	void onTrigger(physx::PxTriggerPair* pairs, physx::PxU32 count) override {}
	void onConstraintBreak(physx::PxConstraintInfo* constraints, physx::PxU32 count) override {}
	void onWake(physx::PxActor** actors, physx::PxU32 count) override {}
	void onSleep(physx::PxActor** actors, physx::PxU32 count) override {}
	void onAdvance(const physx::PxRigidBody* const* bodyBuffer, const physx::PxTransform* poseBuffer, const physx::PxU32 count) override {}
	std::vector<std::pair<std::string, TargetInfo>>&& getTargets();
};

} // namespace gun
