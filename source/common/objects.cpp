#include "objects.h"

namespace common {

physx::PxRigidDynamic* ObjectTools::CreateDynamicObject(const ObjectInfo& info, physx::PxPhysics* physics) {
	physx::PxMaterial* material = physics->createMaterial(info.materia_[0], info.materia_[1], info.materia_[2]);
	physx::PxBoxGeometry hitbox(info.hitbox_);
	physx::PxTransform position(info.position_);

	physx::PxRigidDynamic* object = physx::PxCreateDynamic(*physics, position, hitbox, *material, info.mass_);
	object->setLinearVelocity(info.velocity_);
	object->setName(info.id_.c_str());
	return object;
}

std::vector<physx::PxRigidDynamic*> ObjectTools::CreateDynamicObjectLists(const std::vector<ObjectInfo>& info, physx::PxPhysics* physics) {
	std::vector<physx::PxRigidDynamic*> objects;
	for (const ObjectInfo& object_info : info) {
		objects.push_back(CreateDynamicObject(object_info, physics));
	}
	return objects;
}

void ObjectTools::SetDynamicObjectPosition(physx::PxRigidDynamic* object, const physx::PxVec3& position) {
	object->setGlobalPose(physx::PxTransform(position));
}

void ObjectTools::SetDynamicObjectVelocity(physx::PxRigidDynamic* object, const physx::PxVec3& velocity) {
	object->setLinearVelocity(velocity);
}

physx::PxRigidStatic* ObjectTools::CreateStaticObject(const ObjectInfo& info, physx::PxPhysics* physics) {
	physx::PxMaterial* material = physics->createMaterial(info.materia_[0], info.materia_[1], info.materia_[2]);
	physx::PxBoxGeometry hitbox(info.hitbox_);
	physx::PxTransform position(info.position_);

	physx::PxRigidStatic* object = physx::PxCreateStatic(*physics, position, hitbox, *material);
	object->setName(info.id_.c_str());
	return object;
}

std::vector<physx::PxRigidStatic*> ObjectTools::CreateStaticObjectLists(const std::vector<ObjectInfo>& info, physx::PxPhysics* physics) {
	std::vector<physx::PxRigidStatic*> objects;
	for (const ObjectInfo& object_info : info) {
		objects.push_back(CreateStaticObject(object_info, physics));
	}
	return objects;
}

void ObjectTools::SetStaticObjectPosition(physx::PxRigidStatic* object, const physx::PxVec3& position) {
	object->setGlobalPose(physx::PxTransform(position));
}

} // namespace common
