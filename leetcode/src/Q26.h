/*
 * Q26.h
 *
 *  Created on: 2020Äê5ÔÂ5ÈÕ
 *      Author: jbdu
 */

#ifndef Q26_H_
#define Q26_H_

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicatesSTL(vector<int>& nums) {
    	return (int) distance(nums.begin(), unique(nums.begin(), nums.end()));
    	return 0;
    }

    int removeDuplicates(vector<int>& nums) {

    	auto first = nums.begin();
    	auto last = nums.end();
    	auto cursor = first;
    	if (first == last)
    		return 0;

    	while(++first != last)
    	{

    	}

    	return 0;
    }


};



#endif /* Q26_H_ */
