//
// Created by matte on 03/08/2020.
//

#include "TObserver.h"


TObserver::TObserver(time_t time): endTimer(false){
    this->time=time;
}

TObserver::~TObserver() {}

void TObserver::update(time_t time) {
    this->time=time;
    if(time<=0){
        display();
        endTimer=true;
    } else
        endTimer=false;
}

void TObserver::display() {
    wxMessageBox( wxT("TIME OUT!"), wxT("Timer"), wxICON_INFORMATION);
}

boolean TObserver::getEndTimer() const {
    return endTimer;
}



