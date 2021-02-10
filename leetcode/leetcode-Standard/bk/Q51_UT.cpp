#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>
#include <vector>
using namespace std;
using namespace testing;

#include "Q51.h"

TEST(Q51, T1)
{
    Solution s;
    vector<vector<string>> v = {{"Q"}};
    ASSERT_EQ(v, s.solveNQueens(1));
}