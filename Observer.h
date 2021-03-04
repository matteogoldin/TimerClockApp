//
// Created by matte on 25/02/2021.
//

#ifndef TIMERCLOCKAPP_OBSERVER_H
#define TIMERCLOCKAPP_OBSERVER_H


#include <ctime>

class Observer {
public:
    virtual ~Observer(){};
    virtual void update(time_t time) = 0;
};


#endif //TIMERCLOCKAPP_OBSERVER_H
