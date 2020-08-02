/*
 * Q53.h
 *
 *  Created on: 2020.7.11
 *      Author: david2du
 */

#ifndef _Q53_MAXIMUM_SUBARRAY_H_
#define _Q53_MAXIMUM_SUBARRAY_H_

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int maxSum = INT_MIN;

        unsigned int l = -1, r = -1;
        int sum = 0;
        while(r < nums.size())
        {
            if (sum < maxSum)
            {
                ++r;
                sum += nums[r];
                maxSum = max(sum, maxSum);
            }
            else
            {
                ++l;
                sum -= nums[l - 1];
            }
        }

        return maxSum;
    }
};

#endif