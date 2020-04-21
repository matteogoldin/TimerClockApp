//
// Created by matte on 20/04/2020.
//

#include "CTimer.h"

CTimer::CTimer(wxTextCtrl* dateBox24h,wxTextCtrl* dateBox12h,char* buffer24h,char* buffer12h) {
    dBox24h=dateBox24h;
    dBox12h=dateBox12h;
    this->buffer24h=buffer24h;
    this->buffer12h=buffer12h;
}

CTimer::~CTimer() {

}

void CTimer::Notify() {
    time(&currentTime);
    strftime(buffer24h, 80, "%H:%M:%S", localtime(&currentTime));
    strftime(buffer12h, 80, "%I:%M:%S %p", localtime(&currentTime));
    dBox24h->Replace(0,80,buffer24h);
    dBox12h->Replace(0,80,buffer12h);
}