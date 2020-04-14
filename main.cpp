#include <iostream>
#include <ctime>
#include "Stopwatch.cpp"
#include "Clock.cpp"


int main() {
    Stopwatch* stopwatch=new Stopwatch();
    Clock* clock=new Clock();
    //clock->startClock24h();
    stopwatch->startStopwatch();



    return 0;
}