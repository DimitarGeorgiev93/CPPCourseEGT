#pragma once

#include<vector>
#include<iostream>
//#include "Car.h"


struct RoadSegment
{
    double begining; // meters
    int minSpeed; // km/h
    int maxSpeed; // km/h

    // int holes; //0 1
    double hiddenDanger; 
};


class Road {
public:
    Road(double meters, int numSegments);
    virtual int minSpeedAt(double meters) const;
    virtual int maxSpeedAt(double meters) const;
    virtual int totalLength() const;
    double getSegmentHiddenDanger(double meters) const;
    void printDangerLevels();

    
    RoadSegment* getSegmentAt(double meters);
private:
    const RoadSegment* getSegmentAt(double meters) const;

    std::vector<RoadSegment> segments;
};
