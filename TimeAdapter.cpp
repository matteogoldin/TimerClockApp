//
// Created by matte on 25/02/2021.
//

#include <cstring>
#include "TimeAdapter.h"

std::string TimeAdapter::adaptTime(int time) {
    std::string strTime="";
    strTime=std::to_string(time);
    if(time<10)
        strTime="0"+strTime;
    return strTime;
}
