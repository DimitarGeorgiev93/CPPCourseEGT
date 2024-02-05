#include "FastCar.h"

void FastCar::tick(double sec)
{
    if (hasFinished()) {
        return;
    }
    int maxSpeed = road->maxSpeedAt(meters)*2;
    int roadLen = road->totalLength();
    double dist = maxSpeed * (sec / 3600) * 1000;
    double temp = (double)(rand() % 100) / 200;
    //std::cout << temp << std::endl;
    if (road->getSegmentHiddenDanger(meters) >= temp) {
        //this->road = nullptr;
        std::cout << "Car " << this->name << " crashed at " << dist <<
            ",sending repairs. " << std::endl;
        this->crashed = true;
        return;
    }
    else if (!this->hasCrashed()) {
        this->road->getSegmentAt(meters)->hiddenDanger += 0.02;
        std::cout << "Car " << this->name << " traveled " << dist <<
            " with " << maxSpeed << std::endl;
        meters += dist;
        if (meters >= roadLen) {
            std::cout << "Car " << this->name << " reached end of road"
                << std::endl;
            road = NULL;
            meters = 0;
        }
        else {
            std::cout << "Car " << this->name << " at "
                << meters << "/" << roadLen << " on road" << std::endl;
        }
    }
}