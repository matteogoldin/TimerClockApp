//
// Created by matte on 14/04/2020.
//

#include "Clock.h"
#include "Timer.h"

Clock::Clock() {
    char *buffer=new char[80];//cambia in stringa
    currentTime=0;
    stop=false;
}

Clock::~Clock(){
    delete buffer;
}

void Clock::startClock24h(){
    stop=false;
    while(!stop){
        time(&currentTime);
        strftime(buffer, 80, "%H:%M:%S", localtime(&currentTime));
        std::cout << buffer << std::endl;
    }
}

void Clock::startClock12h(){
    stop=false;
    while(!stop){
        time(&currentTime);
        strftime(buffer, 80, "%I:%M:%S %p", localtime(&currentTime));
        std::cout << buffer << std::endl;
    }
}

void Clock::stopClock(){
    stop=true;
}

time_t Clock::getCurrentTime() const {
    return currentTime;
}
