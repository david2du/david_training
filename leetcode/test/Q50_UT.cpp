#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>
using namespace std;
using namespace testing;

#include "Q50.h"

TEST(Q50, T1)
{
    Solution s; 
	ASSERT_DOUBLE_EQ(2,s.myPow(2.00000,1));
}

TEST(Q50, T2)
{
    Solution s; 
	ASSERT_DOUBLE_EQ(4,s.myPow(2.00000,2));
}

TEST(Q50, T3)
{
    Solution s; 
	ASSERT_DOUBLE_EQ(8,s.myPow(2.00000,3));
}

TEST(Q50, T4)
{
    Solution s; 
	ASSERT_DOUBLE_EQ(16,s.myPow(2.00000,4));
}

TEST(Q50, T10)
{
    Solution s; 
	ASSERT_DOUBLE_EQ(1024,s.myPow(2.00000,10));
}

TEST(Q50, T11)
{
    Solution s; 
	ASSERT_DOUBLE_EQ(9.26100,s.myPow(2.10000,3));
}

TEST(Q50, T12)
{
    Solution s; 
	ASSERT_DOUBLE_EQ(0.25000,s.myPow(2.00000,-2));
}

TEST(Q50, T13)
{
    Solution s; 
	ASSERT_DOUBLE_EQ( 1, s.myPow(0.44528,0));
}

TEST(Q50, T14)
{
    Solution s; 
	ASSERT_DOUBLE_EQ( 1, s.myPow(1,-2147483648));
}

TEST(Q50, T15)
{
    Solution s; 
	ASSERT_DOUBLE_EQ( 1, s.myPow(-1,-2147483648)); 
}