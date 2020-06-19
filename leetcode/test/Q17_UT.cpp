#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
using namespace testing;

#include "Q17.h"

TEST(Q17, T1)
{
    Solution s;
    string sdig = "2";
    vector<string> v = {"a", "b", "c"};
    ASSERT_EQ(v, s.letterCombinations(sdig));
}

TEST(Q17, T2)
{
    Solution s;
    string sdig = "23";
    vector<string> v = {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};
    ASSERT_EQ(v, s.letterCombinations(sdig));
}