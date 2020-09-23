/*
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

#include "common.h"

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> res;
		res.emplace_back();
		vector<int> ele;
		function<void(int)> func = [&](int index) {
			for (int i = index; i < nums.size(); ++i) {
				ele.emplace_back(nums[i]);
				res.emplace_back(ele);
				func(i + 1);
				ele.pop_back();
			}
		};
		func(0);
		return res;
	}

	vector<vector<int>> subsets2(vector<int>& nums) {
		vector<vector<int>> res;
		vector<int> ele;
		unsigned int a = 1 << nums.size();
		for (int i = 0; i < a; ++i) {
			ele.clear();
			for (int j = 0; j < nums.size(); ++j) {
				if (((i >> j) & 1) == 1)ele.emplace_back(nums[j]);
			}
			res.emplace_back(ele);
		}
		return res;
	}

	vector<vector<int>> subsets3(vector<int>& nums) {
		vector<vector<int>> res;
		vector<int> temp;
		for (int i = 0; i < nums.size(); ++i) {
			int len = res.size();
			res.emplace_back(vector<int>{nums[i]});
			for (int j = 0; j < len; ++j) {
				temp = res[j];
				temp.emplace_back(nums[i]);
				res.emplace_back(temp);
			}
		}
		res.emplace_back();
		return res;
	}
};


int main() {
	vector<int> a{1,2,3};

	Solution s; 

	auto res=s.subsets2(a);

	for (auto it = res.begin(); it != res.end(); ++it)
	{
	    for (auto it2 = it->begin(); it2 != it->end(); ++it2)
	    {
	        printf("%d ",*it2);
	    }
	    printf("\n");
	}

return 0;

}
