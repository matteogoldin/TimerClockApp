//
// Created by matte on 20/04/2020.
//

#ifndef TIMERCLOCKAPP_CTIMER_H
#define TIMERCLOCKAPP_CTIMER_H
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class CTimer : public wxTimer{
private:
    wxTextCtrl* dBox24h;
    wxTextCtrl* dBox12h;
    char* buffer24h;
    char* buffer12h;
    time_t currentTime;
public:
    CTimer(wxTextCtrl* dateBox24h,wxTextCtrl* dateBox12h,char* buffer24h,char* buffer12h);
    virtual ~CTimer();

    void Notify() override;
};


#endif //TIMERCLOCKAPP_CTIMER_H
