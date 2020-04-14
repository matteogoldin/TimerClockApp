//
// Created by matte on 14/04/2020.
//

#ifndef TIMERCLOCKAPP_CLOCK_H
#define TIMERCLOCKAPP_CLOCK_H


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



#endif //TIMERCLOCKAPP_CLOCK_H
