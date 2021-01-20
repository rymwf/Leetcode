/*
Given an integer array nums, find three numbers whose product is maximum and return the maximum product.

 

Example 1:

Input: nums = [1,2,3]
Output: 6

Example 2:

Input: nums = [1,2,3,4]
Output: 24

Example 3:

Input: nums = [-1,-2,-3]
Output: -6

 

Constraints:

    3 <= nums.length <= 104
    -1000 <= nums[i] <= 1000
*/
#include "common.h"
class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {
        int a[3]{};
        int b[3]{};
        int c[3]{INT_MIN, INT_MIN, INT_MIN};
        int i;
        for (auto e : nums)
        {
            if (e > 0)
            {
                i = 3;
                while (--i >= 0 && a[i] < e)
                    ;
                i++;
                int j = 2;
                for (; j > i; --j)
                    a[j] = a[j - 1];
                if (i < 3)
                    a[j] = e;
            }
            else
            {
                i = 3;
                while (--i >= 0 && b[i] > e)
                    ;
                i++;
                int j = 2;
                for (; j > i; --j)
                    b[j] = b[j - 1];
                if (i < 3)
                    b[j] = e;

                i = 3;
                while (--i >= 0 && c[i] < e)
                    ;
                i++;
                j = 2;
                for (; j > i; --j)
                    c[j] = c[j - 1];
                if (i < 3)
                    c[j] = e;
            }
        }
        if (a[0] > 0)
        {
            int x = a[1] * a[2];
            int y = b[0] * b[1];
            return a[0] * max(x, y);
        }
        else
        {
            return c[0] * c[1] * c[2];
        }
    }
    int maximumProduct2(vector<int> &nums)
    {
        array<int, 3> a{};
        array<int, 3> b{};
        array<int, 3> c{INT_MIN, INT_MIN, INT_MIN};

        for (auto e : nums)
        {
            if (e > 0)
            {
                if (a[0] < e)
                {
                    a[0] = e;
                    sort(a.begin(), a.end());
                }
            }
            else
            {
                if (b[2] > e)
                {
                    b[2] = e;
                    sort(b.begin(), b.end());
                }
                if (c[0] < e)
                {
                    c[0] = e;
                    sort(c.begin(), c.end());
                }
            }
        }
        if (a[0] > 0)
        {
            int x = a[1] * a[2];
            int y = b[0] * b[1];
            return a[0] * max(x, y);
        }
        else
        {
            return c[0] * c[1] * c[2];
        }
    }
    int maximumProduct3(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int a = nums[len - 3] * nums[len - 2];
        return nums.back() * (nums.back() > 0 ? max(a, nums[0] * nums[1]) : a);
    }
    int maximumProduct4(vector<int> &nums)
    {
        int len = nums.size();
        vector<int> a;
        if (len < 5)
        {
            a.insert(a.end(), nums.begin(), nums.end());
        }
        else
        {
            a.insert(a.end(), nums.begin(), nums.begin() + 5);
        }
        sort(a.begin(), a.end());
        sort(a.rbegin(), a.rbegin() + 3);
        for (int i = 5; i < len; ++i)
        {
            if (nums[i] < a[1])
            {
                a[1] = nums[i];
                sort(a.begin(), a.begin() + 2);
            }
            else if (nums[i] > a.back())
            {
                a.back() = nums[i];
                sort(a.rbegin(), a.rbegin() + 3);
            }
        }
        sort(a.begin(),a.end());
        int lena = a.size();
        int b = a[lena - 3] * a[lena - 2];
        return a.back() * (a.back() > 0 ? max(b, a[0] * a[1]) : b);
    }
    int maximumProduct5(vector<int> &nums)
    {
        // 最小的和第二小的
        int min1 = INT_MAX, min2 = INT_MAX;
        // 最大的、第二大的和第三大的
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;

        for (int x : nums)
        {
            if (x < min1)
            {
                min2 = min1;
                min1 = x;
            }
            else if (x < min2)
            {
                min2 = x;
            }

            if (x > max1)
            {
                max3 = max2;
                max2 = max1;
                max1 = x;
            }
            else if (x > max2)
            {
                max3 = max2;
                max2 = x;
            }
            else if (x > max3)
            {
                max3 = x;
            }
        }

        return max(min1 * min2 * max1, max1 * max2 * max3);
    }
};
int main()
{
    //    vi a = {1, 2, 3, 4, 5, 6, 3, 2};
    //vi a = {-1, -2, -3, -4, 1, 2, 3, 4};
    vi a = {1, 2, 3};
    Solution s;
    s.maximumProduct4(a);
}
