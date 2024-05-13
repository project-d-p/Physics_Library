#pragma once

#include "object_info.h"
#include "PxPhysicsAPI.h"
#include <vector>

namespace common {

class ObjectTools {
public:
	/*
	 * Create a dynamic object with the given information.
	 * @param info The information of the object.
	 * @param physics The physics engine.
	 * @return The created object.
	*/
	static physx::PxRigidDynamic* CreateDynamicObject(const ObjectInfo& info, physx::PxPhysics* physics);
	// Create a list of dynamic objects with the given information.
	static std::vector<physx::PxRigidDynamic*> CreateDynamicObjectLists(const std::vector<ObjectInfo>& info, physx::PxPhysics* physics);
	// Set the position of the dynamic object.
	static void SetDynamicObjectPosition(physx::PxRigidDynamic* object, const physx::PxVec3& position);
	// Set the velocity of the dynamic object.
	static void SetDynamicObjectVelocity(physx::PxRigidDynamic* object, const physx::PxVec3& velocity);
	// Create a static object with the given information
	static physx::PxRigidStatic* CreateStaticObject(const ObjectInfo& info, physx::PxPhysics* physics);
	// Create a list of static objects with the given information.
	static std::vector<physx::PxRigidStatic*> CreateStaticObjectLists(const std::vector<ObjectInfo>& info, physx::PxPhysics* physics);
	// Set the position of the static object.
	static void SetStaticObjectPosition(physx::PxRigidStatic* object, const physx::PxVec3& position);
};

} // namespace gun
