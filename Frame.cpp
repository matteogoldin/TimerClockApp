//
// Created by matte on 14/04/2020.
//

#include "Frame.h"

Frame::Frame() : wxFrame(nullptr,wxID_ANY,"TimerClockApp",wxPoint(50,50),wxSize(380,110)){
    timerButton=new wxButton(this,wxID_ANY,"TIMER",wxPoint(10,10),wxSize(150,50));
    clockButton=new wxButton(this,wxID_ANY,"CLOCK",wxPoint(200,10),wxSize(150,50));

}

Frame::~Frame() {

}
