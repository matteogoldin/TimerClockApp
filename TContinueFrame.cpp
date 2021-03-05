//
// Created by matte on 21/04/2020.
//

#include "TContinueFrame.h"

wxBEGIN_EVENT_TABLE(TContinueFrame, wxFrame)
                EVT_BUTTON(1000,TButtonClickedContinue)
                EVT_BUTTON(1001,TButtonClickedClear)
wxEND_EVENT_TABLE()

TContinueFrame::TContinueFrame(time_t time) : wxFrame(nullptr,wxID_ANY,"Timer",wxPoint(50,50),wxSize(340,170)){
    SetBackgroundColour(*wxBLACK);
    this->time=time;
    timePtr=gmtime(&time);
    stringTime=adaptTime(timePtr->tm_hour)+":"+adaptTime(timePtr->tm_min)+":"+adaptTime(timePtr->tm_sec);
    timeBox = new wxTextCtrl(this, wxID_ANY, stringTime, wxPoint(10,10), wxSize(300,50),
                             wxTE_MULTILINE | wxTE_RICH | wxTE_READONLY, wxDefaultValidator, wxTextCtrlNameStr);
    wxFont font(24,wxFONTFAMILY_TELETYPE,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false);
    timeBox->SetFont(font);
    continueButton=new wxButton(this,1000,"CONTINUE",wxPoint(10,70),wxSize(150,50));
    clearButton=new wxButton(this,1001,"CLEAR",wxPoint(160,70),wxSize(150,50));
}

TContinueFrame::~TContinueFrame() {}

void TContinueFrame::TButtonClickedClear(wxCommandEvent &evt) {
    startFrame=new TFrame();
    startFrame->SetPosition(GetPosition());
    startFrame->Show();
    Destroy();
    evt.Skip();
}

void TContinueFrame::TButtonClickedContinue(wxCommandEvent &evt) {
    pauseFrame = new TPauseFrame(time);
    pauseFrame->SetPosition(GetPosition());
    pauseFrame->Show();
    Destroy();
    evt.Skip();
}
