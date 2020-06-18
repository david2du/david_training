#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>
using namespace std;
using namespace testing;

#include "Q27_RemoveNumber.h"


TEST(Q27, T1)
{
	vector<int> v = {3,2,2,3};
	Solution s;
	ASSERT_EQ(2,s.removeElement(v, 3));

}