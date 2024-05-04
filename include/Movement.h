#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <PxPhysicsAPI.h>

typedef struct {
    double x;
    double y;
    double z;
} t_movement;

namespace Movement {
class Movement {
public:
    Movement();
    // ~Movement();

    t_movement updatePosition();
private:
    physx::PxScene* scene;
    physx::PxPhysics* physics;
    physx::PxFoundation* foundation;
    physx::PxController* character;
    physx::PxControllerManager* manager;

    void initController();
    void initScene();
};

}

#endif