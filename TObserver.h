//
// Created by matte on 03/08/2020.
//

#ifndef TIMERCLOCKAPP_TOBSERVER_H
#define TIMERCLOCKAPP_TOBSERVER_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include <ctime>
#include "Observer.h"


class TObserver: public Observer{
private:
    time_t time;
    boolean endTimer;
public:
    explicit TObserver(time_t time);
    virtual ~TObserver();
    void update(time_t time) override;
    void display();
    boolean getEndTimer() const;
    time_t getTime() const;
};


#endif //TIMERCLOCKAPP_TOBSERVER_H
