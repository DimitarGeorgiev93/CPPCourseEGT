#include "Car.h"


/*oid Car::assignRoad(Road* road)
{
    if (this->road != NULL) {
        throw "can't override road";
    }
    this->road = road;
}

bool Car::hasFinished()
{
    return road == NULL;
}*/

void Car::tick(double sec)
{
    if (hasFinished()) {
        return;
    }
    //std::cout << "-------------------------------------------\n";
    // system("CLS"); //- screen clear
   // srand(time(NULL));
    int maxSpeed = road->maxSpeedAt(meters);
    int roadLen = road->totalLength();
    //std::cout << this->road->getSegmentAt(meters)->hiddenDanger << std::endl;
    double dist = maxSpeed * (sec / 3600) * 1000;
    double temp = (double)(rand() % 100) / 100 ;
    //std::cout << temp << std::endl;
    if (road->getSegmentHiddenDanger(meters) >= temp) {
        //this->road = nullptr;
        std::cout << "Car " << this->name << " crashed at " << dist <<
            ",sending repairs. " << std::endl;
        this->crashed = true;
        return;
    } 
    else if(!this->hasCrashed()){
        this->road->getSegmentAt(meters)->hiddenDanger += 0.01;
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

//Road* Car::getRoad() const
//{
//    return this->road;
//}
//
//bool Car::hasCrashed() const
//{
//    return this->crashed;
//}
//
//
//
//void Car::printName() const
//{
//    std::cout << this->name << std::endl;
//}
