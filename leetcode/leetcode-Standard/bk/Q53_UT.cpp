#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>
using namespace std;
using namespace testing;

#include "Q53.h"

TEST(Q53, T2)
{
    Solution s;
    vector<int> v = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    ASSERT_EQ(6, s.maxSubArray(v));
}