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
        res.emplace_back(vector<int>());
        
        vector<int> ele;
        function<void(int)> func = [&](int index) {
            for (int i = index; i < nums.size(); ++i) {
                ele.emplace_back(nums[i]);
                res.emplace_back(ele);
                func(i+1);
                ele.pop_back();
            }
        };
        func(0);
        return res;
    }
};


void main() {
    vector<int> a{1,2,3};

    Solution s; 

    auto res=s.subsets(a);

    for (auto it = res.begin(); it != res.end(); ++it)
    {
        for (auto it2 = it->begin(); it2 != it->end(); ++it2)
        {
            printf("%d ",*it2);
        }
        printf("\n");
    }

}
