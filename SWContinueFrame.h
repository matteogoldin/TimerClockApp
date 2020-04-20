//
// Created by matte on 20/04/2020.
//

#ifndef TIMERCLOCKAPP_SWCONTINUEFRAME_H
#define TIMERCLOCKAPP_SWCONTINUEFRAME_H
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>

#endif
#include <ctime>
#include "SWTimer.h"
#include "SWFrame.h"
#include "SWPauseFrame.h"



class SWContinueFrame : public wxFrame{
private:
    time_t sw;
    tm *swPtr;
    std::string stringTime;
    wxTextCtrl* timeBox;
    wxButton* continueButton;
    wxButton* clearButton;
    SWPauseFrame* pauseFrame;
    SWFrame* startFrame;
    void OnClose(wxCloseEvent& event); //funzione per stoppare il timer prima di chiudere la finestra
    void SWButtonClickedContinue(wxCommandEvent &evt);
    void SWButtonClickedClear(wxCommandEvent &evt);
    wxDECLARE_EVENT_TABLE();
public:
    SWContinueFrame(time_t sw);
    virtual ~SWContinueFrame();
};


#endif //TIMERCLOCKAPP_SWCONTINUEFRAME_H
