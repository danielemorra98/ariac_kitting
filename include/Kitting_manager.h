#include <iostream>
#include <vector>
#include <list>
using namespace std;
// #include "sensor_msgs/LaserScan"        // da capire il corretto path

struct Kitting_object {
    char* type;
    float height;
    float position;
};

class Kitting_manager {
    private:
        int laser_width;
        list<Kitting_object> objects([]);
        // std::vector<float> range_laser;
        float min_height;

    public:
        void search_min(float* range_laser);
        explicit Laser();
};
