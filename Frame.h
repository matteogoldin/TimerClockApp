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
#include "TFrame.h"


class Frame: public wxFrame {
private:
    wxButton* stopwatchButton;
    wxButton* clockButton;
    wxButton* timerButton;
    SWFrame* swFrame;
    CFrame* cFrame;
    TFrame* tFrame;
    void SWButtonClicked(wxCommandEvent &evt);
    void CButtonClicked(wxCommandEvent &evt);
    void TButtonClicked(wxCommandEvent &evt);
public:
    Frame();
    virtual ~Frame();
    wxDECLARE_EVENT_TABLE();
};


#endif //TIMERCLOCKAPP_FRAME_H
