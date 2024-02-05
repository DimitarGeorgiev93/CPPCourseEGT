#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <memory>
#include <exception>
#include<time.h>


#ifdef __unix__
# include <unistd.h>
#elif defined _WIN32
# include <windows.h>
#define sleep(x) Sleep(1000 * (x))
#endif


//#include "Car.h"
#include "Factory.h"


class Controller {
public:
    Controller() : timerInterval(10) {}

    void addCar();
    void addRoad();
    void loop();

private:


    double timerInterval;
    std::vector<std::unique_ptr<BaseVenicle>> cars;
    std::vector<std::unique_ptr<Road>> roads;
};
