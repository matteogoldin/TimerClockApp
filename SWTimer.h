//
// Created by matte on 20/04/2020.
//

#ifndef TIMERCLOCKAPP_SWTIMER_H
#define TIMERCLOCKAPP_SWTIMER_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include <ctime>

class SWTimer : public wxTimer{
private:
    time_t sw;
    std::string stringTime;
    tm* swPtr;
    wxTextCtrl* timeBox;

public:
    SWTimer(wxTextCtrl* timeBox,time_t sw);
    virtual ~SWTimer();

    void Notify() override;
    time_t getSw() const;
};


#endif //TIMERCLOCKAPP_SWTIMER_H
