//
// Created by matte on 20/04/2020.
//

#include "SWContinueFrame.h"
#include "Functions.h"

wxBEGIN_EVENT_TABLE(SWContinueFrame, wxFrame)
                EVT_BUTTON(1000,SWButtonClickedContinue)
                EVT_BUTTON(1001,SWButtonClickedClear)
wxEND_EVENT_TABLE()

SWContinueFrame::SWContinueFrame(time_t sw) : wxFrame(nullptr,wxID_ANY,"Stopwatch",wxPoint(50,50),wxSize(340,170)){
    SetBackgroundColour(*wxBLACK);
    this->sw=sw;
    swPtr=gmtime(&sw);
    stringTime=adaptTime(swPtr->tm_hour)+":"+adaptTime(swPtr->tm_min)+":"+adaptTime(swPtr->tm_sec);
    timeBox = new wxTextCtrl(this, wxID_ANY, stringTime, wxPoint(10,10), wxSize(300,50),
                             wxTE_MULTILINE | wxTE_RICH | wxTE_READONLY, wxDefaultValidator, wxTextCtrlNameStr);
    wxFont font(24,wxFONTFAMILY_TELETYPE,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false);
    timeBox->SetFont(font);
    continueButton=new wxButton(this,1000,"CONTINUE",wxPoint(10,70),wxSize(150,50));
    clearButton=new wxButton(this,1001,"CLEAR",wxPoint(160,70),wxSize(150,50));
}

SWContinueFrame::~SWContinueFrame() {}

void SWContinueFrame::SWButtonClickedClear(wxCommandEvent &evt) {
    startFrame=new SWFrame();
    startFrame->SetPosition(GetPosition());
    startFrame->Show();
    Destroy();
    evt.Skip();
}

void SWContinueFrame::SWButtonClickedContinue(wxCommandEvent &evt) {
    pauseFrame=new SWPauseFrame(sw);
    pauseFrame->SetPosition(GetPosition());
    pauseFrame->Show();
    Destroy();
    evt.Skip();
}