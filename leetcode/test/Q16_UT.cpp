/*
 * Q16_UT.cpp
 *
 *  Created on: 2020Äê4ÔÂ15ÈÕ
 *      Author: jbdu
 */
#include <gtest/gtest.h>
#include <gmock/gmock.h>


#include "Q16_3Sum_closest.h"
#include <iostream>

using namespace std;

using namespace testing;


TEST(Q16, T1)
{
	vector<int> av{-1, 2 , 1, -4} ;
	Q16Solution Q16;
	ASSERT_EQ(2, Q16.threeSumClosest(av,2));

}

TEST(Q16, T2)
{
	vector<int> av{1, 1 , 1, 0} ;
	Q16Solution Q16;
	ASSERT_EQ(2, Q16.threeSumClosest(av,-100));

}


TEST(Q16, T3)
{
	vector<int> av{0, 0, 0} ;
	Q16Solution Q16;
	ASSERT_EQ(0, Q16.threeSumClosest(av,1));

}



TEST(Q16, T4)
{
	vector<int> av{1, 1, -1,-1,3} ;
	Q16Solution Q16;
	ASSERT_EQ(-1, Q16.threeSumClosest(av,-1));

}


TEST(Q16, T5)
{
	vector<int> av{0, 2, 1,-3} ;
	Q16Solution Q16;
	ASSERT_EQ(0, Q16.threeSumClosest(av, 1));

}


