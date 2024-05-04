#include "Movement.h"

namespace Movement {

Movement::Movement()
{
    physx::PxDefaultErrorCallback errorCallback;
    physx::PxDefaultAllocator allocator;
    
    foundation = PxCreateFoundation(PX_PHYSICS_VERSION, allocator, errorCallback);
    // if (foundation) 에러 처리
    physics = PxCreatePhysics(PX_PHYSICS_VERSION, *foundation, physx::PxTolerancesScale(), true);
    // if (physics) 에러 처리
    
    initScene();
    manager = PxCreateControllerManager(*scene, false);
    initController();
}

void Movement::initScene() {
    physx::PxTolerancesScale scale;
    scale.length = 1.0f;  // 길이 단위를 미터로 설정
    scale.speed = 9.81f;  // 속도 단위를 m/s^2 (중력 가속도)로 설정
    
    physx::PxSceneDesc sceneDesc(scale);
    // if (!sceneDesc.isValid()) 에러 처리
    sceneDesc.gravity = physx::PxVec3(0.0f, -9.81f, 0.0f);
    scene = physics->createScene(sceneDesc);
    // if (!scene) 에러 처리
}

void Movement::initController() {
    physx::PxCapsuleControllerDesc desc;
    desc.height = 1.7f;
    desc.radius = 0.5f;
    desc.position = physx::PxExtendedVec3(0.0f, 0.0f, 0.0f);
    desc.material = physics->createMaterial(0.5f, 0.5f, 0.1f);

    if (!desc.isValid()) {
        // throw std::runtime_error("Controller description is not valid.");
    }
    character = manager->createController(desc);
}

t_movement Movement::updatePosition() {
    physx::PxVec3 displacement(1, 0, 0);
    physx::PxControllerFilters filters;
    character->move(displacement, 0.001f, 1.0f / 60.0f, filters);
    
    physx::PxExtendedVec3 position = character->getPosition();
    t_movement res;
    res.x = position.x;
    res.y = position.y;
    res.z = position.z;
    return res;
}

}
