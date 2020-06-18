/*
 * Q22_Parenthesis.cpp
 *
 *  Created on: 2020Äê4ÔÂ17ÈÕ
 *      Author: jbdu
 */


#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>
using namespace std;
using namespace testing;

#include "Q22_Parenthesis.h"

TEST(Q22, T1)
{
	vector<string> ans = {
			  "()"
	};

	Solution solution;
	vector<string> rlt = solution.generateParenthesis(1);
	ASSERT_EQ(ans.size(), rlt.size());

	auto pAns = ans.begin();
	auto pRlt = rlt.begin();

	while(pAns != ans.end() && pRlt != rlt.end())
	{
		ASSERT_EQ(*pAns, *pRlt);
		pAns++;
		pRlt++;
	}

}


TEST(Q22, T2)
{
	/*vector<string> ans = {
			  "((()))",
			  "(()())",
			  "(())()",
			  "()(())",
			  "()()()"
	};

	Solution solution;
	vector<string> rlt = solution.generateParenthesis(3);
	ASSERT_EQ(ans.size(), rlt.size());

	auto pAns = ans.begin();
	auto pRlt = rlt.begin();

	while(pAns != ans.end() && pRlt != rlt.end())
	{
		ASSERT_EQ(*pAns, *pRlt);

		pAns++;
		pRlt++;
	}
	*/

}


