#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <memory>
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

    t_movement updatePosition();
private:
    std::shared_ptr<physx::PxScene> scene;
    std::shared_ptr<physx::PxPhysics> physics;
    std::shared_ptr<physx::PxController> character;
    std::shared_ptr<physx::PxControllerManager> manager;

    void initializeController();
};

}

#endif