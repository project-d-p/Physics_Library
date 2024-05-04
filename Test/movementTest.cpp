#include "Movement.h"
#include <iostream>

int main()
{
    Movement::Movement movment;
    for (int i = 0; i < 10; i++) {
        t_movement pos = movment.updatePosition();
        std::cout << pos.x << " " << pos.y << " " << pos.z << std::endl;
    }   
}