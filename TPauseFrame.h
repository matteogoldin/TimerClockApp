//
// Created by matte on 21/04/2020.
//

#ifndef TIMERCLOCKAPP_TPAUSEFRAME_H
#define TIMERCLOCKAPP_TPAUSEFRAME_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "TFrame.h"
#include "TContinueFrame.h"

class TFrame;
class TContinueFrame;

class TPauseFrame : public wxFrame{
private:
    time_t time;
    tm *timePtr;
    std::string stringTime;
    wxTextCtrl* timeBox;
    wxButton* pauseButton;
    wxButton* clearButton;
    TContinueFrame* continueFrame;
    TFrame* startFrame;
    wxTimer* timer;
    void OnClose(wxCloseEvent& event); //funzione per stoppare il timer prima di chiudere la finestra
    void TButtonClickedPause(wxCommandEvent &evt);
    void TButtonClickedClear(wxCommandEvent &evt);
    void OnTimer(wxTimerEvent &evt);
    wxDECLARE_EVENT_TABLE();
public:
    explicit TPauseFrame(time_t time);
    virtual ~TPauseFrame();
};


#endif //TIMERCLOCKAPP_TPAUSEFRAME_H
