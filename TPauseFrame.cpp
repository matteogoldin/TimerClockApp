//
// Created by matte on 21/04/2020.
//

#include "TPauseFrame.h"
wxBEGIN_EVENT_TABLE(TPauseFrame, wxFrame)
                EVT_CLOSE(TPauseFrame::OnClose)
                EVT_BUTTON(100,TButtonClickedPause)
                EVT_BUTTON(101,TButtonClickedClear)
wxEND_EVENT_TABLE()

TPauseFrame::TPauseFrame(time_t time) : wxFrame(nullptr,wxID_ANY,"Stopwatch",wxPoint(50,50),wxSize(340,200)){
    SetBackgroundColour(*wxBLACK);
    this->time=time;
    timePtr=gmtime(&time);
    stringTime=std::to_string(timePtr->tm_hour)+":"+std::to_string(timePtr->tm_min)+":"+std::to_string(timePtr->tm_sec);
    timeBox = new wxTextCtrl(this, wxID_ANY, stringTime,wxPoint(10,10), wxSize(300,50),
                             wxTE_MULTILINE | wxTE_RICH |wxTE_READONLY, wxDefaultValidator, wxTextCtrlNameStr);
    wxFont font(24,wxFONTFAMILY_TELETYPE,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false);
    timeBox->SetFont(font);
    pauseButton=new wxButton(this,100,"PAUSE",wxPoint(10,70),wxSize(150,50));
    clearButton=new wxButton(this,101,"CLEAR",wxPoint(160,70),wxSize(150,50));
    timer=new TTimer(timeBox,time);
    timer->Start(1000,false);
}

TPauseFrame::~TPauseFrame() {

}

void TPauseFrame::OnClose(wxCloseEvent &event) {
    timer->Stop();
    Destroy();
}

void TPauseFrame::TButtonClickedPause(wxCommandEvent &evt) {
    /*time=timer->getTime();
    timer->Stop();
    Destroy();
    continueFrame=new TContinueFrame(Time);
    continueFrame->Show();
    evt.Skip();*/
}

void TPauseFrame::TButtonClickedClear(wxCommandEvent &evt) {

}

