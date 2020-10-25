/*
Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it. That is, for each nums[i] you have to count the number of valid j's such that j != i and nums[j] < nums[i].

Return the answer in an array.

 

Example 1:

Input: nums = [8,1,2,2,3]
Output: [4,0,1,1,3]
Explanation: 
For nums[0]=8 there exist four smaller numbers than it (1, 2, 2 and 3). 
For nums[1]=1 does not exist any smaller number than it.
For nums[2]=2 there exist one smaller number than it (1). 
For nums[3]=2 there exist one smaller number than it (1). 
For nums[4]=3 there exist three smaller numbers than it (1, 2 and 2).

Example 2:

Input: nums = [6,5,4,8]
Output: [2,1,0,3]

Example 3:

Input: nums = [7,7,7,7]
Output: [0,0,0,0]

 

Constraints:

    2 <= nums.length <= 500
    0 <= nums[i] <= 100
*/
#include "common.h"

class Solution
{
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums)
    {
        map<int, vector<int>> a;
        for (int i = nums.size() - 1; i >= 0; --i)
        {
            if (a.find(nums[i]) != a.end())
            {
                a[nums[i]][0]++;
            }
            else
            {
                a[nums[i]].emplace_back(1);
            }
            a[nums[i]].emplace_back(i);
        }
        int n = 0;
        vector<int> res(nums.size(), 0);
        for (auto it = a.begin(); it != a.end(); ++it)
        {
            for (int i = it->second.size() - 1; i >= 1; --i)
            {
                res[it->second[i]] = n;
            }
            n += it->second[0];
        }
        return res;
    }
};

int main()
{
}