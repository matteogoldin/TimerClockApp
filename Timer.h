//
// Created by matte on 19/04/2020.
//

#ifndef TIMERCLOCKAPP_TIMER_H
#define TIMERCLOCKAPP_TIMER_H

#include <wx/wx.h>


class Timer : public wxTimer{


public:
    Timer();
    virtual ~Timer();

    bool Start(int milliseconds, bool oneShot) override;
    void Stop() override;
    void Notify() override;
};


#endif //TIMERCLOCKAPP_TIMER_H
