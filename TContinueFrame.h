//
// Created by matte on 21/04/2020.
//

#ifndef TIMERCLOCKAPP_TCONTINUEFRAME_H
#define TIMERCLOCKAPP_TCONTINUEFRAME_H
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include "TFrame.h"
class TFrame;
class TPauseFrame;

class TContinueFrame : public wxFrame{
private:
    time_t time;
    tm *timePtr;
    std::string stringTime;
    wxTextCtrl* timeBox;
    wxButton* continueButton;
    wxButton* clearButton;
    TPauseFrame* pauseFrame;
    TFrame* startFrame;
    void TButtonClickedContinue(wxCommandEvent &evt);
    void TButtonClickedClear(wxCommandEvent &evt);
wxDECLARE_EVENT_TABLE();
public:
    TContinueFrame(time_t sw);
    virtual ~TContinueFrame();


};


#endif //TIMERCLOCKAPP_TCONTINUEFRAME_H
