//
// Created by matte on 21/04/2020.
//

#ifndef TIMERCLOCKAPP_TFRAME_H
#define TIMERCLOCKAPP_TFRAME_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include "TPauseFrame.h"
class TPauseFrame;

class TFrame : public wxFrame{
private:
    time_t time;
    tm *timePtr;
    int hours,seconds,minutes;
    wxTextCtrl* hoursBox;
    wxTextCtrl* minutesBox;
    wxTextCtrl* secondsBox;
    wxTextCtrl* colonBox1;
    wxTextCtrl* colonBox2;
    wxButton* startTButton;
    wxButton* upHoursButton;
    wxButton* downHoursButton;
    wxButton* upMinutesButton;
    wxButton* downMinutesButton;
    wxButton* upSecondsButton;
    wxButton* downSecondsButton;
    TPauseFrame* pauseFrame;
public:
    TFrame();
    virtual ~TFrame();

    void TButtonClickedStart(wxCommandEvent &evt);
    void UpHoursClicked(wxCommandEvent &evt);
    void DownHoursClicked(wxCommandEvent &evt);
    void UpMinutesClicked(wxCommandEvent &evt);
    void DownMinutesClicked(wxCommandEvent &evt);
    void UpSecondsClicked(wxCommandEvent &evt);
    void DownSecondsClicked(wxCommandEvent &evt);
    wxDECLARE_EVENT_TABLE();
};


#endif //TIMERCLOCKAPP_TFRAME_H
