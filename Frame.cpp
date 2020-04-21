//
// Created by matte on 14/04/2020.
//

#include "Frame.h"

wxBEGIN_EVENT_TABLE(Frame,wxFrame)
    EVT_BUTTON(1,SWButtonClicked)
    EVT_BUTTON(2,CButtonClicked)
    EVT_BUTTON(3,TButtonClicked)
wxEND_EVENT_TABLE()


Frame::Frame() : wxFrame(nullptr,wxID_ANY,"TimerClockApp",wxPoint(50,50),wxSize(380,170)){
    SetBackgroundColour(*wxCYAN);
    stopwatchButton=new wxButton(this,1,"STOPWATCH",wxPoint(10,10),wxSize(150,50));
    clockButton=new wxButton(this,2,"CLOCK",wxPoint(200,10),wxSize(150,50));
    timerButton=new wxButton(this,3,"TIMER",wxPoint(105,70),wxSize(150,50));
}
Frame::~Frame() {}

void Frame::SWButtonClicked(wxCommandEvent &evt) {
    swFrame=new SWFrame();
    swFrame->Show();
    evt.Skip();
}

void Frame::CButtonClicked(wxCommandEvent &evt) {
    cFrame=new CFrame();
    cFrame->Show();
    evt.Skip();
}

void Frame::TButtonClicked(wxCommandEvent &evt) {
    tFrame=new TFrame();
    tFrame->Show();
    evt.Skip();
}

