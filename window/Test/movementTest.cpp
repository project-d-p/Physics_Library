#include "Movement.h"
#include <iostream>

using namespace physx;
using namespace movement;

// PxDefaultAllocator gAllocator;
// PxDefaultErrorCallback gErrorCallback;
// PxFoundation* gFoundation = nullptr;
// PxPhysics* gPhysics = nullptr;
// PxScene* gScene = nullptr;
// PxDefaultCpuDispatcher* gDispatcher = nullptr;

// void initPhysics() 
// {
// 	gFoundation = PxCreateFoundation(PX_PHYSICS_VERSION, gAllocator, gErrorCallback);
//     gPhysics = PxCreatePhysics(PX_PHYSICS_VERSION, *gFoundation, PxTolerancesScale());
//     PxSceneDesc sceneDesc(gPhysics->getTolerancesScale());
//     sceneDesc.gravity = PxVec3(0.0f, -9.81f, 0.0f);
//     gDispatcher = PxDefaultCpuDispatcherCreate(4);
//     sceneDesc.cpuDispatcher = gDispatcher;
//     sceneDesc.filterShader = PxDefaultSimulationFilterShader;
//     gScene = gPhysics->createScene(sceneDesc);
// }

int main()
{
    // initPhysics();
    PxVec3 inputMove(1.0f, 0.0f, 0.0f);

    Movement movment;
    for (int i = 0; i < 10; i++) {
        t_movement pos = movment.updatePosition(1, inputMove);
        std::cout << pos.x << " " << pos.y << " " << pos.z << std::endl;
    }
}
