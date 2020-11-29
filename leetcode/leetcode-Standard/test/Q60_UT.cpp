#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>
#include <vector>
using namespace std;
using namespace testing;

#include "Q60.h"


TEST(Q60, T1)
{
    Solution s;
    ASSERT_EQ("213", s.getPermutation1(3, 3));
}
