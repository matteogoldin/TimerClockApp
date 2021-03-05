//
// Created by matte on 05/08/2020.
//
#include "../TObserver.h"
#include "../TPauseFrame.h"
#include <gtest/gtest.h>

class TObserverTest : public ::testing::Test{
protected:
    TObserver* obs=new TObserver(1);
    TPauseFrame* pf;
};

TEST_F(TObserverTest,TimeZero){
    obs->update(0);
    ASSERT_EQ(obs->getEndTimer(),true);
}

TEST_F(TObserverTest,TimeLessZero){
    obs->update(-1);
    ASSERT_EQ(obs->getEndTimer(),true);
}

TEST_F(TObserverTest,TimeGreaterZero){
    obs->update(2);
    ASSERT_EQ(obs->getEndTimer(),false);
}
