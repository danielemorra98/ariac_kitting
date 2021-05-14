#include "include/utils.h"

// Laser constructor
Laser::Laser() {
    min_height = 100.0;
    laser_width = 395;
}

void Laser::search_min(float* range_laser) {
    for (int i = 0; i < laser_width; i++)
    {
        if (range_laser[i] < min_height)
        {
            min_height = range_laser[i];
        }
    }
};