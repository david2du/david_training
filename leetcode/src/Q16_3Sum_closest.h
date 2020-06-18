/*
 * Q16_3Sum_closest.h
 *
 *  Created on: 2020Äê4ÔÂ15ÈÕ
 *      Author: jbdu
 */
#include <vector>
using namespace std;





class Q16Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
    	int sum;
    	int result;
        int minGAP = INT_MAX;
    	sort(nums.begin(), nums.end());

    	for (auto p1 = nums.begin(); p1 != prev(nums.end() ,2 ) ; p1++)
    	{
    		auto p2 = next(p1);
    		auto p3 = prev(nums.end());


    		while (p2 < p3)
    		{
    			sum = *p1 + *p2 + *p3;
    			int GAP = abs(sum - target);
    			if (GAP <= minGAP)
    			{
    			    minGAP = GAP;
    			    result = sum ;
    			}
    			/*if(sum < target)
    				p2++;
    			else
    				p3--;*/
    			if(sum < target)
    				p2 = upper_bound(p2, p3, *p2);
    			else
    				p3 = prev(lower_bound(p2, p3, *p3));

    		}
    	}
    	return result;
    }
};


