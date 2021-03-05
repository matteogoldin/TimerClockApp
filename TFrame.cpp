//
// Created by matte on 21/04/2020.
//

#include "TFrame.h"

wxBEGIN_EVENT_TABLE(TFrame,wxFrame)
                EVT_BUTTON(10,TButtonClickedStart)
                EVT_BUTTON(100,UpHoursClicked)
                EVT_BUTTON(101,DownHoursClicked)
                EVT_BUTTON(102,UpMinutesClicked)
                EVT_BUTTON(103,DownMinutesClicked)
                EVT_BUTTON(104,UpSecondsClicked)
                EVT_BUTTON(105,DownSecondsClicked)

wxEND_EVENT_TABLE()

TFrame::TFrame() : wxFrame(nullptr,wxID_ANY,"Timer",wxPoint(50,50),wxSize(340,200)){
    SetBackgroundColour(*wxBLACK);
    time=0;
    timePtr=gmtime(&time);
    hoursBox = new wxTextCtrl(this, wxID_ANY, "00", wxPoint(10,10), wxSize(80,50),
                             wxTE_MULTILINE | wxTE_RICH | wxTE_READONLY, wxDefaultValidator, wxTextCtrlNameStr);
    colonBox1=new wxTextCtrl(this, wxID_ANY, ":", wxPoint(90,10), wxSize(30,50),
                             wxTE_MULTILINE | wxTE_RICH | wxTE_READONLY , wxDefaultValidator, wxTextCtrlNameStr);
    minutesBox = new wxTextCtrl(this, wxID_ANY, "00", wxPoint(120,10), wxSize(80,50),
                             wxTE_MULTILINE | wxTE_RICH | wxTE_READONLY, wxDefaultValidator, wxTextCtrlNameStr);
    colonBox2=new wxTextCtrl(this, wxID_ANY, ":", wxPoint(200,10), wxSize(30,50),
                             wxTE_MULTILINE | wxTE_RICH | wxTE_READONLY , wxDefaultValidator, wxTextCtrlNameStr);
    secondsBox = new wxTextCtrl(this, wxID_ANY, "00", wxPoint(230,10), wxSize(80,50),
                             wxTE_MULTILINE | wxTE_RICH | wxTE_READONLY, wxDefaultValidator, wxTextCtrlNameStr);
    startTButton=new wxButton(this,10,"START",wxPoint(85,105),wxSize(150,50));
    wxFont font(24,wxFONTFAMILY_TELETYPE,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false);
    hoursBox->SetFont(font);
    minutesBox->SetFont(font);
    secondsBox->SetFont(font);
    colonBox1->SetFont(font);
    colonBox2->SetFont(font);
    upHoursButton=new wxButton(this,100,"+",wxPoint(20,70),wxSize(25,25));
    downHoursButton=new wxButton(this,101,"-",wxPoint(55,70),wxSize(25,25));
    upMinutesButton=new wxButton(this,102,"+",wxPoint(130,70),wxSize(25,25));
    downMinutesButton=new wxButton(this,103,"-",wxPoint(165,70),wxSize(25,25));
    upSecondsButton=new wxButton(this,104,"+",wxPoint(240,70),wxSize(25,25));
    downSecondsButton=new wxButton(this,105,"-",wxPoint(275,70),wxSize(25,25));
}

TFrame::~TFrame() {

}

void TFrame::TButtonClickedStart(wxCommandEvent &evt) {
    pauseFrame=new TPauseFrame(time);
    pauseFrame->SetPosition(GetPosition());
    pauseFrame->Show();
    Destroy();
    evt.Skip();
}

void TFrame::UpHoursClicked(wxCommandEvent &evt) {
    time=time+3600;
    timePtr=gmtime(&time);
    hoursBox->Replace(0,80,adaptTime(timePtr->tm_hour));
    evt.Skip();
}

void TFrame::DownHoursClicked(wxCommandEvent &evt) {
    if(time>=3600){
        time=time-3600;
        timePtr=gmtime(&time);
        hoursBox->Replace(0,80,adaptTime(timePtr->tm_hour));
    }
    evt.Skip();
}

void TFrame::UpMinutesClicked(wxCommandEvent &evt) {
    time=time+60;
    timePtr=gmtime(&time);
    hoursBox->Replace(0,80,adaptTime(timePtr->tm_hour));
    minutesBox->Replace(0,80,adaptTime(timePtr->tm_min));
    evt.Skip();
}

void TFrame::DownMinutesClicked(wxCommandEvent &evt) {
    if(time>=60){
        time=time-60;
        timePtr=gmtime(&time);
        hoursBox->Replace(0,80,adaptTime(timePtr->tm_hour));
        minutesBox->Replace(0,80,adaptTime(timePtr->tm_min));
    }
    evt.Skip();
}

void TFrame::UpSecondsClicked(wxCommandEvent &evt) {
    time=time+1;
    timePtr=gmtime(&time);
    hoursBox->Replace(0,80,adaptTime(timePtr->tm_hour));
    minutesBox->Replace(0,80,adaptTime(timePtr->tm_min));
    secondsBox->Replace(0,80,adaptTime(timePtr->tm_sec));
    evt.Skip();
}

void TFrame::DownSecondsClicked(wxCommandEvent &evt) {
    if(time>0){
        time=time-1;
        timePtr=gmtime(&time);
        hoursBox->Replace(0,80,adaptTime(timePtr->tm_hour));
        minutesBox->Replace(0,80,adaptTime(timePtr->tm_min));
        secondsBox->Replace(0,80,adaptTime(timePtr->tm_sec));
    }
    evt.Skip();
}
