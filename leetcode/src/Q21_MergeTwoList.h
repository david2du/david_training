/*
 * Q21_MergeTwoList.h
 *
 *  Created on: 2020Äê4ÔÂ17ÈÕ
 *      Author: jbdu
 */

#ifndef Q21_MERGETWOLIST_H_
#define Q21_MERGETWOLIST_H_

#include <vector>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
};

class Q21Solution {
public:
	ListNode* buildList(vector<int> iva)
	{
		ListNode * pHead = nullptr ;
		ListNode * pPre = nullptr;

		for(auto ia: iva)
		{
			ListNode * pNew = new ListNode(ia);
			if(pHead == nullptr)
			{
				pHead = pNew;
				pPre = pHead;
			}
			else
			{
				pPre->next = pNew;
				pPre = pNew;
			}
		}


		return pHead;

	}

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

    	ListNode *pHead = nullptr;
    	ListNode *pPre = pHead;
    	ListNode * pTgt = nullptr;

    	while(l1 != nullptr && l2 !=nullptr)
    	{
    		if(l1->val <= l2->val)
    		{
    			pTgt = l1;
    			l1 = l1->next;
       		}
    		else
    		{
    			pTgt = l2;
    			l2 = l2->next;

    		}

    		if(pHead == nullptr)
    		{
    			pHead = new ListNode(pTgt->val);
    			pPre=pHead;
    		}
    		else
    		{
    			pPre->next = new ListNode(pTgt->val);
    			pPre = pPre->next;
    		}
    	}

    	// remaining data.
    	ListNode *pRem = nullptr ;
    	if (l1 != nullptr)
    		pRem = l1;
    	if (l2 != nullptr)
    		pRem = l2;

    	while(pRem != nullptr)
    	{
    		ListNode * pN = new ListNode(pRem->val);
    		pRem = pRem->next;

    		if(pHead == nullptr)
    		{
    			pHead = pN;
    			pPre = pHead;
    		}
    		else
    		{
    			pPre->next = pN;
    			pPre = pN;
    		}


    	}



    	return pHead;

    }
};



#endif /* Q21_MERGETWOLIST_H_ */
