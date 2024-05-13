#include "physics.h"
#include <iostream>
#include <utility>
#include <vector>

using namespace physx;

PxDefaultAllocator gAllocator;
PxDefaultErrorCallback gErrorCallback;
PxFoundation* gFoundation = nullptr;
PxPhysics* gPhysics = nullptr;
PxScene* gScene = nullptr;
PxDefaultCpuDispatcher* gDispatcher = nullptr;
gun::ProjectileShootProcess projectileShootProcess;

void initPhysics() {
	gFoundation = PxCreateFoundation(PX_PHYSICS_VERSION, gAllocator, gErrorCallback);
    gPhysics = PxCreatePhysics(PX_PHYSICS_VERSION, *gFoundation, PxTolerancesScale());
    PxSceneDesc sceneDesc(gPhysics->getTolerancesScale());
    sceneDesc.gravity = PxVec3(0.0f, -9.81f, 0.0f);
    gDispatcher = PxDefaultCpuDispatcherCreate(4);
    sceneDesc.cpuDispatcher = gDispatcher;
	sceneDesc.simulationEventCallback = &projectileShootProcess;
    sceneDesc.filterShader = filter::GunFilter::gunfilter;
    gScene = gPhysics->createScene(sceneDesc);
}

int main(void) {
	initPhysics();

	PxMaterial* gMaterial = gPhysics->createMaterial(0.5, 0.5, 0.6);
	PxRigidStatic* groundPlane = PxCreatePlane(*gPhysics, PxPlane(0,1,0,0), *gMaterial);
	groundPlane->setName("groundPlane");
	gScene->addActor(*groundPlane);

	common::ObjectInfo object{PxVec3(0, 2, 0), PxVec3(1, 1, 1), PxVec3(0, 0, 0), {0.5, 0.5, 0.6}, 1.0, "test"};
	PxRigidStatic* ob = common::ObjectTools::CreateStaticObject(object, gPhysics);
	gScene->addActor(*ob);
	common::ObjectInfo object1{PxVec3(5, 2, 0), PxVec3(1, 1, 1), PxVec3(0, 0, 0), {0.5, 0.5, 0.6}, 1.0, "test2"};
	PxRigidStatic* ob1 = common::ObjectTools::CreateStaticObject(object1, gPhysics);
	gScene->addActor(*ob1);

	common::ObjectInfo bullet{PxVec3(0, 5, 0), PxVec3(1, 1, 1), PxVec3(0, 0, 0), {0.5, 0.5, 0.6}, 1.0, "bullet_1"};
	PxRigidDynamic* bu = common::ObjectTools::CreateDynamicObject(bullet, gPhysics);
	gScene->addActor(*bu);

	common::ObjectInfo bullet1{PxVec3(5, 5, 0), PxVec3(1, 1, 1), PxVec3(0, 0, 0), {0.5, 0.5, 0.6}, 1.0, "bullet_2"};
	PxRigidDynamic* bu1 = common::ObjectTools::CreateDynamicObject(bullet1, gPhysics);
	gScene->addActor(*bu1);

	common::ObjectInfo bullet2{PxVec3(10, 2, 0), PxVec3(1, 1, 1), PxVec3(-50, 0, 0), {0, 0, 0}, 1.0, "bullet_3"};
	PxRigidDynamic* bu2 = common::ObjectTools::CreateDynamicObject(bullet2, gPhysics);
	gScene->addActor(*bu2);
	// gun::ProjectileShootProcess projectileShootProcess;
	// gScene->setSimulationEventCallback(&projectileShootProcess);


	for (int i = 0; i < 120; i++) {
		gScene->simulate(1.0 / 60.0);
		gScene->fetchResults(true);
		std::vector<std::pair<std::string, gun::TargetInfo>> targets = projectileShootProcess.getTargets();
		for (auto& target : targets) {
			std::cout << target.first << " " << target.second.id_ << std::endl;
			if (target.first == "bullet_1") {
				gScene->removeActor(*bu);
				bu->release();
			}
			else if (target.first == "bullet_2") {
				gScene->removeActor(*bu1);
				bu1->release();
			}
			else if (target.first == "bullet_3") {
				gScene->removeActor(*bu2);
				bu2->release();
			}
			else {
				std::cout << "no bullet" << std::endl;
			}
		}
	}


	gScene->release();
	gDispatcher->release();
	gPhysics->release();
	gFoundation->release();
	return 0;
}
