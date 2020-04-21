//
// Created by matte on 20/04/2020.
//

#include "SWContinueFrame.h"

wxBEGIN_EVENT_TABLE(SWContinueFrame, wxFrame)
                EVT_BUTTON(1000,SWButtonClickedContinue)
                EVT_BUTTON(1001,SWButtonClickedClear)
wxEND_EVENT_TABLE()


SWContinueFrame::SWContinueFrame(time_t sw) : wxFrame(nullptr,wxID_ANY,"Stopwatch",wxPoint(50,50),wxSize(340,170)){
    SetBackgroundColour(*wxCYAN);
    this->sw=sw;
    swPtr=gmtime(&sw);
    stringTime=std::to_string(swPtr->tm_hour)+":"+std::to_string(swPtr->tm_min)+":"+std::to_string(swPtr->tm_sec);
    timeBox = new wxTextCtrl(this, wxID_ANY, stringTime, wxPoint(10,10), wxSize(300,50),
                             wxTE_MULTILINE | wxTE_RICH | wxTE_READONLY, wxDefaultValidator, wxTextCtrlNameStr);
    wxFont font(24,wxFONTFAMILY_TELETYPE,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false);
    timeBox->SetFont(font);
    continueButton=new wxButton(this,1000,"CONTINUE",wxPoint(10,70),wxSize(150,50));
    clearButton=new wxButton(this,1001,"CLEAR",wxPoint(160,70),wxSize(150,50));
}

SWContinueFrame::~SWContinueFrame() {}

void SWContinueFrame::SWButtonClickedClear(wxCommandEvent &evt) {
    Destroy();
    startFrame=new SWFrame();
    startFrame->Show();
}

void SWContinueFrame::SWButtonClickedContinue(wxCommandEvent &evt) {
    Destroy();
    pauseFrame=new SWPauseFrame(sw);
    pauseFrame->Show();

}