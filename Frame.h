//
// Created by matte on 14/04/2020.
//

#ifndef TIMERCLOCKAPP_FRAME_H
#define TIMERCLOCKAPP_FRAME_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif


class Frame: public wxFrame {
private:
    wxButton* timerButton;
    wxButton* clockButton;
public:
    Frame();
    ~Frame();
};


#endif //TIMERCLOCKAPP_FRAME_H
