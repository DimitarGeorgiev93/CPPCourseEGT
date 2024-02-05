#pragma once
#include "FastCar.h"
#include "RepairVenicle.h"
#include <sstream>

enum CarType { CAR , FASTCAR, REPAIRVENICLE};
enum RoadType {ROAD, SIMPLEROAD,  COMBINEDROAD,BADROAD};


class Factory
{
public:
    std::unique_ptr<BaseVenicle> buildCar(CarType);
    std::unique_ptr<BaseVenicle> buildRepairVenicle(BaseVenicle*);
    std::unique_ptr<Road> buildRoad();

private:
    std::string unique_name();

    static int carId;
};

