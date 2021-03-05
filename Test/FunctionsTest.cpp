//
// Created by matte on 05/03/2021.
//

#include "../Functions.h"
#include <gtest/gtest.h>

class FunctionsTest : public ::testing::Test{
protected:
    int time;
    std::string strTime;
};

TEST_F(FunctionsTest,AdaptTimeLesser10){
    time=rand()%10;
    strTime=std::to_string(time);
    ASSERT_EQ(adaptTime(time),"0"+strTime);
}

TEST_F(FunctionsTest,AdaptTimeGreater10){
    time=rand()%1000+10;
    strTime=std::to_string(time);
    ASSERT_EQ(adaptTime(time),strTime);
}
