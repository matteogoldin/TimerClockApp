//
// Created by matte on 25/02/2021.
//
#ifndef TIMERCLOCKAPP_SUBJECT_H
#define TIMERCLOCKAPP_SUBJECT_H


#include "Observer.h"

class Subject {
public:
    virtual ~Subject(){};
    virtual void attach(Observer *observer) = 0;
    virtual void detach(Observer *observer) = 0;
    virtual void notifyObservers() = 0;
};


#endif //TIMERCLOCKAPP_SUBJECT_H
