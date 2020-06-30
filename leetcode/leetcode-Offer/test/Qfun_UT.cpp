/*
 * Q15_ut.cpp
 *
 *  Created on: 2020��4��11��
 *      Author: jbdu
 */
#include <gtest/gtest.h>
#include <gmock/gmock.h>


#include "fun.cpp"
#include <iostream>

using namespace std;

using namespace testing;


TEST(QFUN, T1)
{
ASSERT_EQ(4,add(2,2));

}




