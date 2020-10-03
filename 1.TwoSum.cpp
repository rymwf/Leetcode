/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]

 

Constraints:

    2 <= nums.length <= 105
    -109 <= nums[i] <= 109
    -109 <= target <= 109
    Only one valid answer exists.

*/
#include "common.h"

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> res;
        if (nums.size() == 0)
            return res;
        vector<int> tempNums = nums;
        sort(tempNums.begin(), tempNums.end());
        int l = 0, r = tempNums.size() - 1;
        while (l <= r)
        {
            if (tempNums[l] + tempNums[r] == target)
                break;
            else if (tempNums[l] + tempNums[r] > target)
                r--;
            else if (tempNums[l] + tempNums[r] < target)
                l++;
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == tempNums[l])
            {
                l = i;
                break;
            }
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == tempNums[r] && i != l)
            {
                r = i;
                break;
            }
        }
        return vector<int>{l, r};
    }
    vector<int> twoSum2(vector<int> &nums, int target)
    {
        unordered_map<int, int> mymap;
        for (int i = 0; i < nums.size(); ++i)
        {
            int a = target - nums[i];
            if (mymap.find(a) != mymap.end())
                return vector<int>{mymap[a], i};
            mymap[nums[i]] = i;
        }
        return vector<int>();
    }
};

int main()
{
    //vector<int> a{3, 3};
    vector<int> a{2, 7, 11, 15};
    int t = 9;
    Solution s;
    vector<int> res = s.twoSum2(a, t);
    for (auto &i : res)
    {
        printf("%d\n", i);
    }
}
