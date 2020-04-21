//
// Created by matte on 19/04/2020.
//

#ifndef TIMERCLOCKAPP_SWFRAME_H
#define TIMERCLOCKAPP_SWFRAME_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include <ctime>
#include "SWPauseFrame.h"

class SWPauseFrame;

class SWFrame : public wxFrame{
private:
    wxTextCtrl* timeBox;
    wxButton* startSWButton;
    std::string stringTime;
    time_t sw;
    tm *swPtr;
    SWPauseFrame* pauseFrame;
    void SWButtonClickedStart(wxCommandEvent &evt);
public:
    SWFrame();
    virtual ~SWFrame();
    wxDECLARE_EVENT_TABLE();
};


#endif //TIMERCLOCKAPP_SWFRAME_H
