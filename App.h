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
    Frame* frame1= nullptr;
public:
    App();
    ~App();
    bool OnInit();
};

DECLARE_APP(App);

#endif //TIMERCLOCKAPP_APP_H
