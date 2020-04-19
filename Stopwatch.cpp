//
// Created by matte on 07/10/2019.
//

#include "Stopwatch.h"
Stopwatch::Stopwatch():hours(0),minutes(0),seconds(0),stop(false),start(0),duration(0){}
Stopwatch::~Stopwatch() {}
void Stopwatch::startStopwatch(){
    stop=false;
    start= std::clock();
    while(!stop){               //not solo perché ha più senso che si fermi quando stop==true
        duration=( std::clock() - start) / (double) CLOCKS_PER_SEC;
        seconds=duration-minutes*60-hours*60*60;

        if(seconds>=60){
            minutes++;
            seconds=duration-minutes*60-hours*60*60;
        }


        if(minutes>=60){
            hours++;
            minutes=minutes-hours*60;
        }

        if(hours>=24)
            resetStopwatch();

        //std::cout<<Stopwatch::hours<<":"<<Stopwatch::minutes<<":"<<Stopwatch::seconds<<"\n";ù

        //update();           //funzione observer da definire
    }
}

void Stopwatch::pauseStopwatch(){
    stop=true;
}

void Stopwatch::resetStopwatch(){
    stop=true;
    hours=0;
    minutes=0;
    seconds=0;
    duration=0;
    //update();
}

std::clock_t Stopwatch::getStart()const{
    return start;
}

int Stopwatch::getHours() const {
    return hours;
}

int Stopwatch::getMinutes() const {
    return minutes;
}

int Stopwatch::getSeconds() const {
    return seconds;
}