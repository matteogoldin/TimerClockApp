//
// Created by matte on 19/04/2020.
//

#include "Timer.h"

Timer::Timer() {}

Timer::~Timer() {

}

bool Timer::Start(int milliseconds, bool oneShot) {
    return wxTimer::Start(milliseconds, oneShot);
}

void Timer::Stop() {
    wxTimer::Stop();
}

void Timer::Notify() {
    wxTimer::Notify();

}
