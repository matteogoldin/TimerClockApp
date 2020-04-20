//
// Created by matte on 19/04/2020.
//

#ifndef TIMERCLOCKAPP_CFRAME_H
#define TIMERCLOCKAPP_CFRAME_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include <wx/dataview.h>
#include <ctime>
#include "CTimer.h"

class CFrame : public wxFrame{
private:
    wxTextCtrl* dateBox24h;
    wxTextCtrl* dateBox12h;
    char* buffer24h; //utilizzo un buffer di char anziché una stringa per la funzione strftime
    char* buffer12h;
    time_t currentTime;
    CTimer* timer;

public:
    CFrame();
    virtual ~CFrame();


};


#endif //TIMERCLOCKAPP_CFRAME_H
