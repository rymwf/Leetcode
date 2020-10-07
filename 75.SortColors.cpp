/*
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Follow up:

    Could you solve this problem without using the library's sort function?
    Could you come up with a one-pass algorithm using only O(1) constant space?

 

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]

Example 3:

Input: nums = [0]
Output: [0]

Example 4:

Input: nums = [1]
Output: [1]

 

Constraints:

    n == nums.length
    1 <= n <= 300
    nums[i] is 0, 1, or 2.
*/
#include "common.h"

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int a[3]{0};
        for (auto &i : nums)
        {
            a[i]++;
        }
        int b = 0;
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < a[i]; ++j)
            {
                nums[b + j] = i;
            }
            b += a[i];
        }
    }
    //single traverse??
    //a little slow
    void sortColors2(vector<int> &nums)
    {
        int p0 = 0, p1 = 0, p2 = nums.size() - 1;
        while (p1 <= p2)
        {
            while (p2 > 0 && nums[p2] == 2)
                p2--;
            if (p1 > p2)
                break;
            if (nums[p1] == 2)
            {
                swap(nums[p1], nums[p2]);
                if (nums[p1] == 0)
                {
                    swap(nums[p0], nums[p1]);
                    p0++;
                }
                p2--;
            }
            else if (nums[p1] == 0)
            {
                swap(nums[p0], nums[p1]);
                p0++;
            }
            p1++;
        }
    }
};

int main()
{

    vector<int> a = {1, 1, 0, 0, 2, 2, 1, 0, 2};
    //vector<int> a={2,0,1};
    //vector<int> a={2};
    //vector<int> a={1,2,0,0};
    for (auto &i : a)
    {
        printf("%d ", i);
    }
    printf("\n");
    Solution s;
    s.sortColors2(a);
    for (auto &i : a)
    {
        printf("%d ", i);
    }
}
