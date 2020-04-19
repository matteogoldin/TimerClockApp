//
// Created by matte on 14/04/2020.
//

#include "App.h"
wxIMPLEMENT_APP(App);

App::App(){

}

App::~App() {

}

bool App::OnInit() {
    mainFrame=new Frame();
    mainFrame->Show();
    return true;
}