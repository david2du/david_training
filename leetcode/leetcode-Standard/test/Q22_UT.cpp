/*
 * Q22_Parenthesis.cpp
 *
 *  Created on: 2020��4��17��
 *      Author: jbdu
 */


#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>
using namespace std;
using namespace testing;

#include "Q22.cpp"

TEST(Q22, T1)
{
	vector<string> ans = {
			  "()"
	};

	Solution s;
	ASSERT_EQ(ans,s.generateParenthesis(1));
	

}

TEST(Q22, T2)
{
	vector<string> ans = {
			  "(())",
			  "()()"
	};

	Solution solution;
	ASSERT_EQ(ans, solution.generateParenthesis(2));
	
}



TEST(Q22, T3)
{
	vector<string> ans = {
			  "((()))",
			  "(()())",
			  "(())()",
			  "()(())",
			  "()()()"
	};

	Solution solution;
	ASSERT_EQ(ans, solution.generateParenthesis(3));
	
}


