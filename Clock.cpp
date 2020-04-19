//
// Created by matte on 10/10/2019.
//

#include "Clock.h"

Clock::Clock() {
    char *buffer=new char[80];
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
