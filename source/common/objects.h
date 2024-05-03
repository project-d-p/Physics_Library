#pragma once

#include "object_info.h"
#include "PxPhysicsAPI.h"
#include <vector>

namespace common {

class ObjectTools {
public:
	static physx::PxRigidDynamic* CreateDynamicObject(const ObjectInfo& info, physx::PxPhysics* physics);
	static std::vector<physx::PxRigidDynamic*> CreateDynamicObjectLists(const std::vector<ObjectInfo>& info, physx::PxPhysics* physics);
	static void SetDynamicObjectPosition(physx::PxRigidDynamic* object, const physx::PxVec3& position);
	static void SetDynamicObjectVelocity(physx::PxRigidDynamic* object, const physx::PxVec3& velocity);
	static physx::PxRigidStatic* CreateStaticObject(const ObjectInfo& info, physx::PxPhysics* physics);
	static std::vector<physx::PxRigidStatic*> CreateStaticObjectLists(const std::vector<ObjectInfo>& info, physx::PxPhysics* physics);
	static void SetStaticObjectPosition(physx::PxRigidStatic* object, const physx::PxVec3& position);
};

} // namespace gun
