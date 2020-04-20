//
// Created by matte on 19/04/2020.
//

#include "CFrame.h"


CFrame::CFrame() : wxFrame(nullptr,wxID_ANY,"Clock",wxPoint(50,50),wxSize(400,400)){
    char *buffer24h=new char[80];
    char *buffer12h=new char[80];
    time(&currentTime);
    strftime(buffer24h, 80, "%H:%M:%S", localtime(&currentTime));
    strftime(buffer12h, 80, "%I:%M:%S %p", localtime(&currentTime));
    dateBox24h = new wxTextCtrl(this, wxID_ANY, buffer24h, wxPoint(50,50), wxSize(200,50),
                                 wxTE_MULTILINE | wxTE_RICH , wxDefaultValidator, wxTextCtrlNameStr);
    dateBox12h = new wxTextCtrl(this, wxID_ANY, buffer12h, wxPoint(50,150), wxSize(200,50),
                                wxTE_MULTILINE | wxTE_RICH , wxDefaultValidator, wxTextCtrlNameStr);
    timer=new CTimer(dateBox24h,dateBox12h,buffer24h,buffer12h);
    timer->Start(1000,false);
}
CFrame::~CFrame() {}
