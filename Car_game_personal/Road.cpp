#include "Road.h"
//#include "Car.h"

Road::Road(double meters, int numSegments)
{
    double segLen = meters / numSegments;
    for (int i = 0; i < numSegments; ++i) {
        //srand(time(NULL));
        int maxSpeed = 50 + rand() % 50;

        segments.push_back(RoadSegment{
                i * segLen,
                maxSpeed - 10,
                maxSpeed,
                (double)(rand()%20)/100,
            });
    }
    segments.push_back(RoadSegment{ meters, 0, 0, 0 });
}

int Road::minSpeedAt(double meters) const
{
    return getSegmentAt(meters)->minSpeed;
}

int Road::maxSpeedAt(double meters) const
{
    return getSegmentAt(meters)->maxSpeed;
}

int Road::totalLength() const
{
    return segments[segments.size() - 1].begining;
}

double Road::getSegmentHiddenDanger(double meters) const
{
    return getSegmentAt(meters)->hiddenDanger;
}


void Road::printDangerLevels()
{
    for (RoadSegment rs : segments) {
        std::cout << rs.hiddenDanger << " ";
    }
    std::cout << std::endl;
}


RoadSegment* Road::getSegmentAt(double meters)
{
    if (meters >= totalLength()) {
        return NULL;
    }
    for (int i = 0; i < segments.size(); ++i) {
        if (segments[i].begining <= meters &&
            segments[i + 1].begining > meters) {
            return &segments[i];
        }
    }
    return NULL;
}

const RoadSegment* Road::getSegmentAt(double meters) const
{
    if (meters >= totalLength()) {
        return NULL;
    }
    for (int i = 0; i < segments.size(); ++i) {
        if (segments[i].begining <= meters &&
            segments[i + 1].begining > meters) {
            return &segments[i];
        }
    }
    return NULL;
}
