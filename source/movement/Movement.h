#pragma once

#include <PxPhysicsAPI.h>
#include "character_info.h"

namespace movement {
class Movement {
public:
    Movement();
    // ~Movement();

    t_movement updatePosition(float deltaTime, physx::PxVec3 horizontalInput, physx::PxController* character);
    void jump();
    void move(physx::PxVec3 input);
    void initPhysics();
    physx::PxControllerManager* initManager(physx::PxScene* scene);
    physx::PxController* initController(physx::PxPhysics* physics, physx::PxControllerManager* manager);
    bool isGrounded();
private:
    // physx::PxController* character;
    // physx::PxControllerManager* manager;
    // physx::PxScene* scene;

    // physx::PxDefaultAllocator gAllocator;
	// physx::PxDefaultErrorCallback gErrorCallback;
	// physx::PxFoundation* gFoundation = nullptr;
	// physx::PxPhysics* gPhysics = nullptr;
	// physx::PxScene* gScene = nullptr;
	// physx::PxDefaultCpuDispatcher* gDispatcher = nullptr;
};

} // namespace movement
