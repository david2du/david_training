#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>
using namespace std;
using namespace testing;

#include "Q38_CounterAndSay.h"


TEST(Q38, T1)
{
	vector<int> v = {3,2,2,3};
	Solution s;
	ASSERT_EQ("1",s.countAndSay(1));

}