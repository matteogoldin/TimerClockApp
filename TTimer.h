//
// Created by matte on 21/04/2020.
//

#ifndef TIMERCLOCKAPP_TTIMER_H
#define TIMERCLOCKAPP_TTIMER_H
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif


class TTimer : public wxTimer{
private:
    time_t time;
    std::string stringTime;
    tm* timePtr;
    wxTextCtrl* timeBox;

public:
    TTimer(wxTextCtrl* timeBox,time_t time);
    virtual ~TTimer();

    void Notify() override;

    time_t getTime() const;
};


#endif //TIMERCLOCKAPP_TTIMER_H
