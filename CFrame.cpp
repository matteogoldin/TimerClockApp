///
// Created by matte on 19/04/2020.
//

#include "CFrame.h"
wxBEGIN_EVENT_TABLE(CFrame, wxFrame)
                EVT_CLOSE(CFrame::OnClose)
wxEND_EVENT_TABLE()

CFrame::CFrame() : wxFrame(nullptr,wxID_ANY,"Clock",wxPoint(50,50),wxSize(285,180)){
    SetBackgroundColour(*wxBLACK);
    char *buffer24h=new char[80];
    char *buffer12h=new char[80];
    time(&currentTime);
    strftime(buffer24h, 80, "%H:%M:%S", localtime(&currentTime));
    strftime(buffer12h, 80, "%I:%M:%S %p", localtime(&currentTime));
    dateBox24h = new wxTextCtrl(this, wxID_ANY, buffer24h, wxPoint(10,10), wxSize(250,40),
                                wxTE_MULTILINE | wxTE_RICH | wxTE_READONLY, wxDefaultValidator, wxTextCtrlNameStr);
    dateBox12h = new wxTextCtrl(this, wxID_ANY, buffer12h, wxPoint(10,80), wxSize(250,40),
                                wxTE_MULTILINE | wxTE_RICH | wxTE_READONLY, wxDefaultValidator, wxTextCtrlNameStr);
    wxFont font(24,wxFONTFAMILY_TELETYPE,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false);
    dateBox24h->SetFont(font);
    dateBox12h->SetFont(font);
    timer=new CTimer(dateBox24h,dateBox12h,buffer24h,buffer12h);
    timer->Start(1000,false);
}
CFrame::~CFrame() {
    delete[] buffer12h;
    delete[] buffer24h;
}

void CFrame::OnClose(wxCloseEvent &event) {
    timer->Stop();
    Destroy();
}
