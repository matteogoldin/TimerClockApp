//
// Created by matte on 19/04/2020.
//

#include "SWFrame.h"
#include "TimeAdapter.h"

wxBEGIN_EVENT_TABLE(SWFrame,wxFrame)
                EVT_BUTTON(10,SWButtonClickedStart)
wxEND_EVENT_TABLE()

SWFrame::SWFrame() : wxFrame(nullptr,wxID_ANY,"Stopwatch",wxPoint(50,50),wxSize(340,170)){
    SetBackgroundColour(*wxBLACK);
    sw=0;
    swPtr=gmtime(&sw); //converte time_t in tm
    stringTime=TimeAdapter::adaptTime(swPtr->tm_hour)+":"+TimeAdapter::adaptTime(swPtr->tm_min)+":"+
            TimeAdapter::adaptTime(swPtr->tm_sec);
    timeBox = new wxTextCtrl(this, wxID_ANY, stringTime, wxPoint(10,10), wxSize(300,50),
                                wxTE_MULTILINE | wxTE_RICH | wxTE_READONLY , wxDefaultValidator, wxTextCtrlNameStr);
    wxFont font(24,wxFONTFAMILY_TELETYPE,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false);
    timeBox->SetFont(font);
    startSWButton=new wxButton(this,10,"START",wxPoint(85,70),wxSize(150,50));
}

SWFrame::~SWFrame() {}

void SWFrame::SWButtonClickedStart(wxCommandEvent &evt) {
    pauseFrame=new SWPauseFrame(sw);
    pauseFrame->SetPosition(GetPosition());
    pauseFrame->Show();
    Destroy();
    evt.Skip();
}
