//
// Created by matte on 14/04/2020.
//

#ifndef TIMERCLOCKAPP_FRAME_H
#define TIMERCLOCKAPP_FRAME_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "SWFrame.h"
#include "CFrame.h"


class Frame: public wxFrame {
private:
    wxButton* stopwatchButton;
    wxButton* clockButton;
    SWFrame* swFrame;
    CFrame* cFrame;
public:
    Frame();
    virtual ~Frame();

    void SWButtonClicked(wxCommandEvent &evt);
    void CButtonClicked(wxCommandEvent &evt);
    wxDECLARE_EVENT_TABLE();
};


#endif //TIMERCLOCKAPP_FRAME_H
