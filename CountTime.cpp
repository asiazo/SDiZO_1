#include <iostream>
#include <chrono>
#include "CountTime.h"

using namespace std;
using namespace std::chrono;

// Funkcja timeStart() - ustawia wartość zmiennej startingTime na aktualny czas
void CountTime::timeStart() {
    startingTime = high_resolution_clock::now();
}
// Funkcja timeStop() - ustawia wartość zmiennej finishTime na aktualny czas
void CountTime::timeStop() {
    finishTime = high_resolution_clock::now();
}
// Funkcja workingTime() - zwraca czas w nanosekundach między startingTime, finishTime
long CountTime::workingTime() {

    return duration_cast<nanoseconds>(finishTime -startingTime).count();

}
