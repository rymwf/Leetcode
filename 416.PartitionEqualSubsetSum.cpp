/*
Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].

Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.

Constraints:

    1 <= nums.length <= 200
    1 <= nums[i] <= 100
*/
#include "common.h"

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1)
            return false;
        sum /= 2;
        int l = nums.size();
        vector<bool> a(sum + 1, false);
        int k = 0;
        a[0] = true;
        for (auto &&i : nums)
        {
            for (int j = sum; j >= 0; --j)
            {
                if (j >= i)
                    a[j] = a[j - i] | a[j];
            }
            if (a[sum])
                return true;
        }
        return false;
    }
};
int main()
{
    //vector<int> a = {1, 2, 1, 2};
    vector<int> a = {3, 3, 3, 4, 5};
    //vector<int> a = {1,3,2,4, 3, 3, 3, 3, 5, 7};
    //vector<int> a = {100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,99,97};

    Solution s;
    bool res = s.canPartition(a);
    printf("%d", res);
}
