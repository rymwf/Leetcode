/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:

Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
*/
#include "common.h"
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        unordered_map<int, int> temp_map;
        vector<int> ele;
        for_each(nums.begin(), nums.end(), [&temp_map](int a) {
            temp_map[a]++;
        });

        function<void()> func = [&]() {
            if (ele.size() == nums.size()) {
                res.emplace_back(ele);
                return;
            }
            for (auto it = temp_map.begin(); it != temp_map.end(); ++it) {
                if (it->second > 0) {
                    ele.emplace_back(it->first);
                    it->second--;
                    func();
                    it->second++;
                    ele.pop_back();
                }
            }
        };
        func();
        return res;
    }
};


int main() {

    vector<int> a{1,1,1,1,1,2,2,2,2};
    
    Solution s;
    auto res=s.permuteUnique(a);
    for (auto it = res.begin(); it != res.end(); ++it) {
        for (auto it2 = it->begin(); it2 != it->end(); ++it2)
        {
            printf("%d ",*it2);
        }
        printf("\n");
    }
return 0;
}
