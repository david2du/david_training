

#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Q15Solution {
public:

	vector<vector<int>> threeSum1(vector<int> &nums) {
		set<vector<int>> ansSet;
		vector<vector<int>> ans;

		sort(nums.begin(), nums.end());

		for (auto p1 = nums.begin(); p1 != nums.end(); p1++) {
			for (auto p2 = p1 + 1; p2 != nums.end(); p2++) {
				auto p3 = p2 + 1;
				if (p2 != nums.end() && (p3) != nums.end()) {
					auto lb = lower_bound(p3, nums.end(), -(*p1 + *p2));
					auto ub = upper_bound(p3, nums.end(), -(*p1 + *p2));

					if (lb != ub) {
						vector<int> iv = { *p1, *p2, *lb };
						if (ansSet.count(iv) == 0) {
							ans.push_back( { *p1, *p2, *lb });
							ansSet.insert(iv);

						}

					}

				}

			}
		}

		return ans;
	}

	vector<vector<int>> threeSum2(vector<int> &nums) {

		vector<vector<int>> ans;
		if (nums.size() < 3)
			return ans;

		sort(nums.begin(), nums.end());

		for (auto p1 = nums.begin(); p1 != nums.end(); p1++) {
			for (auto p2 = p1 + 1; p2 != nums.end(); p2++) {
				auto p3 = p2 + 1;
				if (p2 != nums.end() && (p3) != nums.end()) {
					auto lb = lower_bound(p3, nums.end(), -(*p1 + *p2));
					auto ub = upper_bound(p3, nums.end(), -(*p1 + *p2));

					if (lb != ub) {
						vector<int> iv = { *p1, *p2, *lb };
						ans.push_back(iv);

					}

				}

			}
		}

		sort(ans.begin(), ans.end());
		ans.erase(unique(ans.begin(), ans.end()), ans.end());

		return ans;
	}

	vector<vector<int>> threeSum(vector<int> &num) {
		vector<vector<int>> result;

		if (num.size() < 3)
			return result;

		sort(num.begin(), num.end());
		const int target = 0;
		auto last = num.end();

		for (auto a = num.begin(); a < prev(last, 2); ++a) {

			auto b = next(a);
			auto c = prev(last);

			if(*a > target)
				break;

			while (b < c) {
				if (*a + *b + *c < target) {
					b = upper_bound(b, c, *b);

				} else if (*a + *b + *c > target) {
					c = prev(lower_bound(b, c, *c)) ;

				} else {
					result.push_back( { *a, *b, *c });
					auto t1 = b, t2 = c;
					b  = upper_bound(t1, t2 , *t1);
					c = prev(lower_bound(t1, t2, *t2));
				}
			}
		}

		sort(result.begin(), result.end());
		result.erase(unique(result.begin(), result.end()), result.end());

		return result;
	}

};

