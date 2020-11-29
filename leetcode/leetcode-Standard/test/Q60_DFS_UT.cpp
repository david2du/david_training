#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>
using namespace std;
using namespace testing;

#include "Q60_DFS.h"

TEST(Q60_DFS, T1)
{
    Solution s;
    ASSERT_EQ("213", s.getPermutation(3,3));
}

TEST(Q60_DFS, T2)
{
    Solution s;
    ASSERT_EQ("2314", s.getPermutation(4,9));
}

/*TEST(Q60, T3)
{
    Solution s;
    ASSERT_EQ("2314", s.getPermutation(4,9));
}*/
