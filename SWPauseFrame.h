//
// Created by matte on 20/04/2020.
//

#ifndef TIMERCLOCKAPP_SWPAUSEFRAME_H
#define TIMERCLOCKAPP_SWPAUSEFRAME_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include <ctime>
#include "SWTimer.h"
#include "SWFrame.h"
#include "SWContinueFrame.h"

class SWPauseFrame : public wxFrame{
private:
    time_t sw;
    tm *swPtr;
    std::string stringTime;
    wxTextCtrl* timeBox;
    wxButton* pauseButton;
    wxButton* clearButton;
    SWContinueFrame* continueFrame;
    SWFrame* startFrame;
    SWTimer* timer;
    void OnClose(wxCloseEvent& event); //funzione per stoppare il timer prima di chiudere la finestra
    void SWButtonClickedPause(wxCommandEvent &evt);
    void SWButtonClickedClear(wxCommandEvent &evt);
    wxDECLARE_EVENT_TABLE();
public:
    SWPauseFrame(time_t sw);
    virtual ~SWPauseFrame();
};


#endif //TIMERCLOCKAPP_SWPAUSEFRAME_H
