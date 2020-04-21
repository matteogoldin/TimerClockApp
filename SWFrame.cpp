//
// Created by matte on 19/04/2020.
//

#include "SWFrame.h"

wxBEGIN_EVENT_TABLE(SWFrame,wxFrame)
                EVT_BUTTON(10,SWButtonClickedStart)
wxEND_EVENT_TABLE()

SWFrame::SWFrame() : wxFrame(nullptr,wxID_ANY,"Stopwatch",wxPoint(50,50),wxSize(400,400)){
    sw=0;
    swPtr=gmtime(&sw);
    stringTime=std::to_string(swPtr->tm_hour)+":"+std::to_string(swPtr->tm_min)+":"+std::to_string(swPtr->tm_sec);
    timeBox = new wxTextCtrl(this, wxID_ANY, stringTime, wxPoint(50,50), wxSize(200,50),
                                wxTE_MULTILINE | wxTE_RICH , wxDefaultValidator, wxTextCtrlNameStr);
    startSWButton=new wxButton(this,10,"START",wxPoint(50,110),wxSize(150,50));
}
SWFrame::~SWFrame() {}

void SWFrame::SWButtonClickedStart(wxCommandEvent &evt) {
    Destroy();
    pauseFrame=new SWPauseFrame(sw);
    pauseFrame->Show();
    evt.Skip();
    }
