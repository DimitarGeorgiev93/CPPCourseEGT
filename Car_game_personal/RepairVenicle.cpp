#include "RepairVenicle.h"

RepairVenicle::RepairVenicle(BaseVenicle* toBeRepaired, std::string name) : BaseVenicle(name+"rv")
{
    this->toBeRepaired = toBeRepaired;
    coming = 1;
}


bool RepairVenicle::repairCar()
{
    if ( this->meters >= toBeRepaired->getMeters())  {
        toBeRepaired->getRepaired();
        std::cout << "deleting repair venicle" << std::endl;
        return true;
    }
    return false;
}

void RepairVenicle::tick(double sec){
    if (hasFinished()) {
        return;
    }
    //std::cout << "-------------------------------------------\n";
    //system("CLS"); //- screen clear
    // srand(time(NULL));
    int maxSpeed = road->maxSpeedAt(meters);
    int roadLen = road->totalLength();
    //std::cout << this->road->getSegmentAt(meters)->hiddenDanger << std::endl;
    double dist = maxSpeed * (sec / 3600) * 1000;
    //double temp = (double)(rand() % 100) / 100;
    //std::cout << temp << std::endl;
   /* if (road->getSegmentHiddenDanger(meters) >= temp) {
        this->road = nullptr;
        std::cout << "Car " << this->name << " crashed at " << dist <<
            ",sending repairs. " << std::endl;
        this->crashed = true;
        return;
    }*/
    if (repairCar()) {
        delete this;
    }
    else {
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

int RepairVenicle::getRepairCount()
{
    return coming;
}

RepairVenicle::~RepairVenicle()
{
    this->coming = 0;
}
