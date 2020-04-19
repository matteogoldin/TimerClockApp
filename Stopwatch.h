//
// Created by matte on 07/10/2019.
//

#ifndef TIMERCLOCK_STOPWATCH_H
#define _STOPWATCH_H
#include <cstdio>
#include <ctime>
#include <iostream>


class Stopwatch{
public:
    Stopwatch();
    ~Stopwatch();
    void startStopwatch();

    void pauseStopwatch();

    void resetStopwatch();


    std::clock_t getStart()const;

    int getHours() const;

    int getMinutes() const;

    int getSeconds() const;

private:
    int hours,minutes,seconds;
    double duration;
    std::clock_t start;
    bool stop;

};

#endif //UNTITLED71_STOPWATCH_H
