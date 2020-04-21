//
// Created by matte on 20/04/2020.
//

#include "SWTimer.h"


SWTimer::SWTimer(wxTextCtrl* timeBox,time_t sw) {
    this->timeBox=timeBox;
    this->sw=sw;
    swPtr=gmtime(&sw);
    stringTime=std::to_string(swPtr->tm_hour)+":"+std::to_string(swPtr->tm_min)+":"+std::to_string(swPtr->tm_sec);
}

SWTimer::~SWTimer() {

}

void SWTimer::Notify() {
    sw++;
    swPtr=gmtime(&sw);
    stringTime=std::to_string(swPtr->tm_hour)+":"+std::to_string(swPtr->tm_min)+":"+std::to_string(swPtr->tm_sec);
    timeBox->Replace(0,80,stringTime);
}

time_t SWTimer::getSw() const {
    return sw;
}
