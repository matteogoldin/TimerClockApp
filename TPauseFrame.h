//
// Created by matte on 21/04/2020.
//

#ifndef TIMERCLOCKAPP_TPAUSEFRAME_H
#define TIMERCLOCKAPP_TPAUSEFRAME_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include <list>
#include "TFrame.h"
#include "TContinueFrame.h"
#include "TObserver.h"
#include "Subject.h"

class TFrame;
class TContinueFrame;
class TObserver;

class TPauseFrame : public wxFrame, public Subject{
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
    TObserver* observer;
    void OnClose(wxCloseEvent& event); //funzione per stoppare il timer prima di chiudere la finestra
    void TButtonClickedPause(wxCommandEvent &evt);
    void TButtonClickedClear(wxCommandEvent &evt);
    void OnTimer(wxTimerEvent &evt);
    wxDECLARE_EVENT_TABLE();
public:
    explicit TPauseFrame(time_t time);
    virtual ~TPauseFrame();
    void notifyObservers() override;
    void attach(Observer *observer) override {};
    void detach(Observer *observer) override {};
};


#endif //TIMERCLOCKAPP_TPAUSEFRAME_H
