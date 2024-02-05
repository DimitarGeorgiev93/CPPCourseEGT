#pragma once
#include "BaseVenicle.h"
#include "Car.h"



class RepairVenicle :
    public BaseVenicle
{
public:
    RepairVenicle(BaseVenicle*,std::string name);
    bool repairCar();
    virtual void tick(double sec);
    static int getRepairCount();
    ~RepairVenicle();
private:
    static int coming;
    BaseVenicle* toBeRepaired;
};

