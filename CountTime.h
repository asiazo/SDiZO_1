#include <iostream>
#include <chrono>

#ifndef SDIZO1_COUNTTIME_H
#define SDIZO1_COUNTTIME_H

using namespace std;
using namespace std::chrono;

class CountTime {
public:
    high_resolution_clock::time_point startingTime;
    high_resolution_clock::time_point finishTime;

    void timeStart();

    void timeStop();

    long int workingTime();
};


#endif //SDIZO1_COUNTTIME_H

