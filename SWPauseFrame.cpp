//
// Created by matte on 20/04/2020.
//

#include "SWPauseFrame.h"

wxBEGIN_EVENT_TABLE(SWPauseFrame, wxFrame)
                EVT_CLOSE(SWPauseFrame::OnClose)
                EVT_BUTTON(100,SWButtonClickedPause)
                EVT_BUTTON(101,SWButtonClickedClear)
wxEND_EVENT_TABLE()

SWPauseFrame::SWPauseFrame(time_t sw) : wxFrame(nullptr,wxID_ANY,"Stopwatch",wxPoint(50,50),wxSize(340,170)){
    SetBackgroundColour(*wxBLACK);
    this->sw=sw;
    swPtr=gmtime(&sw);
    stringTime=std::to_string(swPtr->tm_hour)+":"+std::to_string(swPtr->tm_min)+":"+std::to_string(swPtr->tm_sec);
    timeBox = new wxTextCtrl(this, wxID_ANY, stringTime,wxPoint(10,10), wxSize(300,50),
                             wxTE_MULTILINE | wxTE_RICH |wxTE_READONLY, wxDefaultValidator, wxTextCtrlNameStr);
    wxFont font(24,wxFONTFAMILY_TELETYPE,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false);
    timeBox->SetFont(font);
    pauseButton=new wxButton(this,100,"PAUSE",wxPoint(10,70),wxSize(150,50));
    clearButton=new wxButton(this,101,"CLEAR",wxPoint(160,70),wxSize(150,50));
    timer=new SWTimer(timeBox,sw);
    timer->Start(1000,false);
}

SWPauseFrame::~SWPauseFrame() {

}

void SWPauseFrame::OnClose(wxCloseEvent &event) {
    timer->Stop();
    Destroy();
    event.Skip();
}

void SWPauseFrame::SWButtonClickedPause(wxCommandEvent &evt) {
    sw=timer->getSw();
    timer->Stop();
    continueFrame=new SWContinueFrame(sw);
    continueFrame->SetPosition(GetPosition());
    continueFrame->Show();
    Destroy();
    evt.Skip();
}

void SWPauseFrame::SWButtonClickedClear(wxCommandEvent &evt) {
    timer->Stop();
    startFrame=new SWFrame();
    startFrame->SetPosition(GetPosition());
    startFrame->Show();
    Destroy();
    evt.Skip();
}
