//
// Created by matte on 20/04/2020.
//

#include "SWPauseFrame.h"

wxBEGIN_EVENT_TABLE(SWPauseFrame, wxFrame)
                EVT_CLOSE(SWPauseFrame::OnClose)
                EVT_BUTTON(100,SWButtonClickedPause)
                EVT_BUTTON(101,SWButtonClickedClear)
wxEND_EVENT_TABLE()

SWPauseFrame::SWPauseFrame(time_t sw) : wxFrame(nullptr,wxID_ANY,"Stopwatch",wxPoint(50,50),wxSize(400,400)){
    this->sw=sw;
    swPtr=gmtime(&sw);
    stringTime=std::to_string(swPtr->tm_hour)+":"+std::to_string(swPtr->tm_min)+":"+std::to_string(swPtr->tm_sec);
    timeBox = new wxTextCtrl(this, wxID_ANY, stringTime, wxPoint(50,50), wxSize(200,50),
                             wxTE_MULTILINE | wxTE_RICH , wxDefaultValidator, wxTextCtrlNameStr);
    pauseButton=new wxButton(this,100,"PAUSE",wxPoint(50,110),wxSize(150,50));
    clearButton=new wxButton(this,101,"CLEAR",wxPoint(200,110),wxSize(150,50));
    timer=new SWTimer(timeBox,sw);
    timer->Start(1000,false);
}

SWPauseFrame::~SWPauseFrame() {

}

void SWPauseFrame::OnClose(wxCloseEvent &event) {
    timer->Stop();
    Destroy();
}

void SWPauseFrame::SWButtonClickedPause(wxCommandEvent &evt) {
    sw=timer->getSw();
    timer->Stop();
    Destroy();
    continueFrame=new SWContinueFrame(sw);
    continueFrame->Show();
    evt.Skip();
}

void SWPauseFrame::SWButtonClickedClear(wxCommandEvent &evt) {
    timer->Stop();
    Destroy();
    startFrame=new SWFrame();
    startFrame->Show();
    evt.Skip();
}
