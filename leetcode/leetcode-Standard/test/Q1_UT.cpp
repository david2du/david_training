/**
 * Q15_UT.cpp
 * 
 * Created on: 2021/2/9
 *      Author: David Du
*/
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "Q1.cpp"
#include <iostream>

using namespace std;

using namespace testing;

TEST(Q1, T1)
{
    Solution s;

    vector<int> input = {2, 7, 11, 15};
    vector<int> ans = {0, 1};

    ASSERT_EQ(ans, s.twoSum(input, 9));
}

TEST(Q1, T2)
{
    Solution s;

    vector<int> input = {3, 2, 4};
    vector<int> ans = {1, 2};

    ASSERT_EQ(ans, s.twoSum(input, 6));
}

TEST(Q1, T3)
{
    Solution s;

    vector<int> input = {3, 3};
    vector<int> ans = {0, 1};

    ASSERT_EQ(ans, s.twoSum(input, 6));
}