//
// Created by matte on 04/03/2021.
//

#include "Functions.h"

std::string adaptTime(int time) {
        std::string strTime=std::to_string(time);
        if(time<10)
            strTime="0"+strTime;
        return strTime;
    }
