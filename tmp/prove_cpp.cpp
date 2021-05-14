#include <iostream>
#include <string>
#include <vector>
#include "../include/ariac_kitting/utils.h"

using namespace std;


// Laser constructor
Laser::Laser() {
    min_height = 100.0;
    laser_width = 4;
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


int main() {
    Laser laser_scarso;
    float arr[4] = {1.0, 2.0, 5.0, 0.5};
    laser_scarso.search_min(arr);
    cout << laser_scarso.min_height << '\n';
    return 0;
}