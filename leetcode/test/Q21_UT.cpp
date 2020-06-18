/*
 * Q21_UT.cpp
 *
 *  Created on: 2020Äê4ÔÂ17ÈÕ
 *      Author: jbdu
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>


#include "Q21_MergeTwoList.h"
#include <iostream>

using namespace std;

using namespace testing;

TEST(Q21, T1)
{

	Q21Solution solution;
	ListNode * pLN1 = solution.buildList({1, 2, 4});
	ListNode * pLN2 = solution.buildList({1, 3, 4});
	ListNode * pExp = solution.buildList({1, 1, 2, 3, 4, 4});
	ListNode * pAns = solution.mergeTwoLists(pLN1, pLN2);

	//ASSERT_NE(NULL, pAns);
	ASSERT_NE(nullptr, pAns);


	while((pExp = pExp->next) && (pAns = pAns->next))
	{
		ASSERT_EQ(pExp->val, pAns->val);
	}


}

TEST(Q21, T2)
{

	Q21Solution solution;
	ListNode * pLN1 = solution.buildList({});
	ListNode * pLN2 = solution.buildList({0});
	ListNode * pExp = solution.buildList({0});
	ListNode * pAns = solution.mergeTwoLists(pLN1, pLN2);

	//ASSERT_NE(NULL, pAns);
	ASSERT_NE(nullptr, pAns);


	while((pExp = pExp->next) && (pAns = pAns->next))
	{
		ASSERT_EQ(pExp->val, pAns->val);
	}


}





