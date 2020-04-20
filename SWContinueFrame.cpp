//
// Created by matte on 20/04/2020.
//

#include "SWContinueFrame.h"

wxBEGIN_EVENT_TABLE(SWContinueFrame, wxFrame)
                EVT_CLOSE(SWContinueFrame::OnClose)
                EVT_BUTTON(1000,SWButtonClickedContinue)
                EVT_BUTTON(1001,SWButtonClickedClear)
wxEND_EVENT_TABLE()


SWContinueFrame::SWContinueFrame(time_t sw) : wxFrame(nullptr,wxID_ANY,"Stopwatch",wxPoint(50,50),wxSize(400,400)){
    this->sw=sw;
    swPtr=gmtime(&sw);
    stringTime=std::to_string(swPtr->tm_hour)+":"+std::to_string(swPtr->tm_min)+":"+std::to_string(swPtr->tm_sec);
    timeBox = new wxTextCtrl(this, wxID_ANY, stringTime, wxPoint(50,50), wxSize(200,50),
                             wxTE_MULTILINE | wxTE_RICH , wxDefaultValidator, wxTextCtrlNameStr);
    continueButton=new wxButton(this,1000,"CONTINUE",wxPoint(50,110),wxSize(150,50));
    clearButton=new wxButton(this,1001,"CLEAR",wxPoint(200,110),wxSize(150,50));

}

SWContinueFrame::~SWContinueFrame() {

}

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

void SWContinueFrame::OnClose(wxCloseEvent &event) {

}
