//
// Created by matte on 21/04/2020.
//

#include "TTimer.h"

TTimer::TTimer(wxTextCtrl* timeBox,time_t time) {
    this->timeBox=timeBox;
    this->time=time;
    timePtr=gmtime(&time);
    stringTime=std::to_string(timePtr->tm_hour)+":"+std::to_string(timePtr->tm_min)+":"+std::to_string(timePtr->tm_sec);
}

TTimer::~TTimer() {}

void TTimer::Notify() {
    if(time>0) {
        time--;
        timePtr = gmtime(&time);
        stringTime = std::to_string(timePtr->tm_hour) + ":" + std::to_string(timePtr->tm_min) + ":" +
                     std::to_string(timePtr->tm_sec);
        timeBox->Replace(0, 80, stringTime);
    } else{
        wxMessageBox( wxT("TIME OUT!"), wxT("Timer"), wxICON_INFORMATION);
    }
}

time_t TTimer::getTime() const {
    return time;
}

