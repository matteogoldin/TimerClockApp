//
// Created by matte on 10/10/2019.
//

#ifndef UNTITLED71_CLOCK_H
#define UNTITLED71_CLOCK_H

#include <ctime>
#include <iostream>

class Clock{
public:
    Clock();
    ~Clock();

    void startClock24h();

    void startClock12h();

    void stopClock();
private:
    char *buffer;
    time_t currentTime;
    bool stop;
};


#endif //UNTITLED71_CLOCK_H
