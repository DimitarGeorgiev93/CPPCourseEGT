#include "Factory.h"


int Factory::carId = 0;

std::unique_ptr<BaseVenicle> Factory::buildCar(CarType carType)
{
    if (carType == CAR) {
        //return new Car(unique_name());
        //std::unique_ptr<Car> newCarPtr = std::make_unique<Car>(unique_name());
        return std::make_unique<Car>(unique_name());
        // return std::make_unique<Car>(unique_name());
    }
    /*if (carType == REPAIRVENICLE) {
        std::cout << "Repair venicle created " << std::endl;
        return std::make_unique<RepairVenicle>(unique_name());
    }*/
    else {
        //std::unique_ptr<Car> newCarPtr = std::make_unique<FastCar>(unique_name());
        return std::make_unique<FastCar>(unique_name());
    }
  
}


std::unique_ptr<Road> Factory::buildRoad()
{
      return std::make_unique<Road>(10000,10);
}



std::unique_ptr<BaseVenicle> Factory::buildRepairVenicle(BaseVenicle* toBeRepaired)
{
    std::cout << "Repair venicle created " << std::endl;

    return std::make_unique<RepairVenicle>(toBeRepaired,unique_name());
}




std::string Factory::unique_name()
{
    std::ostringstream os;
    os << "car-id-" << carId++;
    return os.str();
}
