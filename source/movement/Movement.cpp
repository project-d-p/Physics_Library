#include "Movement.h"

namespace movement {

// 이후에 구조체로 변경
float jumpVelocity = 10.0f;
float verticalVelocity;
float moveSpeed = 0.1f;

Movement::Movement()
{
    // manager = PxCreateControllerManager(*gScene, false);
}

physx::PxControllerManager* Movement::initManager(physx::PxScene* scene)
{
    return PxCreateControllerManager(*scene, false);
}

// 추후에 인자로 받아서 초기화가 진행될 수 있도록 변경, manager 또한 인자로 받아서.
// 호출자가 객체를 관리할 수 있도록 진행.
physx::PxController* Movement::initController(physx::PxPhysics* physics, physx::PxControllerManager* manager) {
    physx::PxCapsuleControllerDesc desc;
    desc.height = 1.7f;
    desc.radius = 0.5f;
    // 디폴트 부분
    desc.position = physx::PxVec3d(0.0f, 0.0f, 0.0f);
    desc.material = physics->createMaterial(0.5f, 0.5f, 0.1f);
    desc.stepOffset = 0.3f;
    
    if (!desc.isValid()) {
        // throw std::runtime_error("Controller description is not valid.");
    }
    return manager->createController(desc);
}

void Movement::jump() {
    if (isGrounded()) {
        verticalVelocity = jumpVelocity;
    }
}

// void Movement::move(physx::PxVec3 input) {
//     horizontalInput += input;
// }

bool Movement::isGrounded() {
    // const float rayLength = 0.1f;
    // physx::PxVec3 rayStart = physx::PxVec3\
    //     (static_cast<float>(character->getPosition().x), \
    //     static_cast<float>(character->getPosition().y), \
    //     static_cast<float>(character->getPosition().z));
    // physx::PxVec3 rayDir = physx::PxVec3(0, -1, 0);

    // physx::PxRaycastBuffer hit;
    // return scene->raycast(rayStart, rayDir, rayLength, hit);
    return true;
}

/*
// XXX: horizontalInput represents whether there is movement other than jumping.
// If there is movement, set the corresponding axis to 1.
*/
t_movement Movement::updatePosition(float deltaTime, physx::PxVec3 horizontalInput, physx::PxController* character) {
    physx::PxVec3 displacement(horizontalInput * moveSpeed);
    // displacement.y += verticalVelocity * deltaTime;
    
    // verticalVelocity += scene->getGravity().y * deltaTime;
    
    physx::PxControllerFilters filters;
    character->move(displacement, 0.001f, deltaTime, filters);
    
    physx::PxVec3d position = character->getPosition();
    t_movement res;
    res.x = position.x;
    res.y = position.y;
    res.z = position.z;
    return res;
}

} // namespace movement
