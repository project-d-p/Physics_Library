#include "physics.h"
#include "PxPhysicsAPI.h"
#include <iostream>

using namespace physx;

PxDefaultAllocator gAllocator;
PxDefaultErrorCallback gErrorCallback;
PxFoundation* gFoundation = nullptr;
PxPhysics* gPhysics = nullptr;
PxScene* gScene = nullptr;
PxDefaultCpuDispatcher* gDispatcher = nullptr;

void initPhysics() {
	gFoundation = PxCreateFoundation(PX_PHYSICS_VERSION, gAllocator, gErrorCallback);
    gPhysics = PxCreatePhysics(PX_PHYSICS_VERSION, *gFoundation, PxTolerancesScale());
    PxSceneDesc sceneDesc(gPhysics->getTolerancesScale());
    sceneDesc.gravity = PxVec3(0.0f, -9.81f, 0.0f);
    gDispatcher = PxDefaultCpuDispatcherCreate(4);
    sceneDesc.cpuDispatcher = gDispatcher;
    sceneDesc.filterShader = PxDefaultSimulationFilterShader;
    gScene = gPhysics->createScene(sceneDesc);
}

// physx::PxVec3 position_;
// 	physx::PxVec3 hitbox_;
// 	physx::PxVec3 velocity_;
// 	float materia_[3];
// 	float mass_;

// static TargetInfo OnShoot(const SourceInfo& source, physx::PxScene* scene, physx::PxQueryFilterData filterData);
// };

int main(void) {
	initPhysics();

	common::ObjectInfo objectInfo{PxVec3(0, 5, 0), PxVec3(1, 1, 1), PxVec3(0, 10, 0), {0.5, 0.5, 0.5}, 1.0, "test"};
	PxRigidDynamic* dynamic = common::ObjectTools::CreateDynamicObject(objectInfo, gPhysics);
	gScene->addActor(*dynamic);
	gun::SourceInfo sourceInfo{PxVec3(0, 15, 0), PxVec3(0, -1, 0), 100};
	gun::TargetInfo targetInfo = gun::HitscanShootProcess::OnShoot(sourceInfo, gScene, PxQueryFilterData());
	std::cout << targetInfo.distance_ << " " << targetInfo.id_ << std::endl;
	targetInfo = gun::HitscanShootProcess::OnShoot(sourceInfo, gScene, PxQueryFilterData());
	std::cout << targetInfo.distance_ << " " << targetInfo.id_ << std::endl;
}
