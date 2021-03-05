//
// Created by matte on 03/08/2020.
//

#include "TObserver.h"


TObserver::TObserver(time_t time){
    this->time=time;
    endTimer=false;
}
TObserver::~TObserver() {}

void TObserver::update(time_t time) {
    this->time=time;
    if(time<=0)
        endTimer = true;
    if(endTimer==true)
        display();
}

void TObserver::display() {
    wxMessageBox( wxT("TIME OUT!"), wxT("Timer"), wxICON_INFORMATION);
}

boolean TObserver::getEndTimer() const {
    return endTimer;
}

time_t TObserver::getTime() const {
    return time;
}



