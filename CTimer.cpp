//
// Created by matte on 20/04/2020.
//

#include "CTimer.h"

CTimer::CTimer(wxTextCtrl* timeBox24h,wxTextCtrl* timeBox12h,char* buffer24h,char* buffer12h) {
    tBox24h=timeBox24h;
    tBox12h=timeBox12h;
    this->buffer24h=buffer24h;
    this->buffer12h=buffer12h;
}

CTimer::~CTimer() {}

void CTimer::Notify() {
    time(&currentTime);
    strftime(buffer24h, 80, "%H:%M:%S", localtime(&currentTime));
    strftime(buffer12h, 80, "%I:%M:%S %p", localtime(&currentTime));
    tBox24h->Replace(0,80,buffer24h);
    tBox12h->Replace(0,80,buffer12h);
}