//
// Created by matte on 14/04/2020.
//

#ifndef TIMERCLOCKAPP_APP_H
#define TIMERCLOCKAPP_APP_H
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "Frame.h"


class App : public wxApp{
private:
    Frame* mainFrame= nullptr;
public:
    App();
    virtual ~App();
    bool OnInit();
};


#endif //TIMERCLOCKAPP_APP_H
