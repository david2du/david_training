/*
 * Q15_ut.cpp
 *
 *  Created on: 2020��4��11��
 *      Author: jbdu
 */
#include <gtest/gtest.h>
#include <gmock/gmock.h>


#include "Q15_3Sum.h"
#include <iostream>

using namespace std;

using namespace testing;


TEST(Q15_3Sum, T1)
{
	vector<int> av{-1, 0, 1, 2, -1, -4} ;
	Q15Solution Q15;
	vector<vector<int>> ans = { {-1, -1, 2},{-1, 0 , 1}};
	ASSERT_EQ(ans, Q15.threeSum(av));

}


TEST(Q15_3Sum, T2)
{
	vector<int> av{-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6} ;
	Q15Solution Q15;
	vector<vector<int>> ans = {
			{-4,-2,6},
			{-4,0,4},
			{-4,1,3},
			{-4,2,2},
			{-2,-2,4},
			{-2,0,2}};
	ASSERT_EQ(ans, Q15.threeSum(av));

}




