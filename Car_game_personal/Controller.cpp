#include "Controller.h"

void Controller::addCar()
{
    // Car *p = new Car(unique_name());
    // cars.emplace_back(p);
    /*std::unique_ptr<Car> p = std::make_unique<Car>(unique_name());
    cars.push_back(std::move(p));*/
    //srand(time(NULL));
    Factory* factory = new Factory();
    //std::unique_ptr<Car> carPtr = std::make_unique<Car>(factory->buildCar(unique_name()));
    cars.emplace_back(factory->buildCar((CarType)(rand() % 2)));

    delete factory;
}

void Controller::addRoad()
{   

    Factory* factory = new Factory();
    roads.emplace_back(factory->buildRoad());

    delete factory;
}



void Controller::loop()
{
    std::cout << "-------------------------------------------\n";
    for (auto& car : cars) {
        if (car->hasFinished()) {
            car->assignRoad(roads[rand() % roads.size()].get());
        }
    }


    for (int i = 0; i < cars.size(); i++) {
        
        //if(!cars.at(i)) cars.erase(cars.begin() + i--);

        if (cars.at(i)->hasCrashed() && RepairVenicle::getRepairCount() == 0) {
            //cars.erase(cars.begin()+i--);
            Factory* factory = new Factory();
            cars.emplace_back(factory->buildRepairVenicle(cars.at(i).get()));
        }
        else if (cars.at(i)->hasCrashed() == false) {
            cars.at(i)->tick(timerInterval);
        }
    }

   /* for (auto& car : cars) {
        car->tick(timerInterval);
        if (car->hasCrashed()) {
           // cars.
        }
    }*/
    for (std::unique_ptr<Road>& a : roads) {
        a->printDangerLevels();
    }
}


