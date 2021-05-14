#include <iostream>
#include <vector>
// #include "sensor_msgs/LaserScan"        // da capire il corretto path

class Laser {
    private:
        int laser_width;
        // std::vector<float> range_laser;

    public:
        float min_height;
        void search_min(float* range_laser);
        explicit Laser();
};