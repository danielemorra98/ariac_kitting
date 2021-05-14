#include "include/utils.h"
#ifndef LASER_INIT
#define LASER_INIT 100.0
#define LASER_WIDTH 395
#endif

// Laser constructor
Laser::Laser() {
    min_height = LASER_INIT;
    actual_iteration = LASER_INIT;
    laser_width = LASER_WIDTH;
}

// void Laser::search_min(float* range_laser) {
//     for (int i = 0; i < laser_width; i++)
//     {
//         if (range_laser[i] < min_height)
//         {
//             min_height = range_laser[i];
//         }
//     }
};