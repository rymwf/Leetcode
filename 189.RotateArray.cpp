/*
Given an array, rotate the array to the right by k steps, where k is non-negative.

Follow up:

    Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
    Could you do it in-place with O(1) extra space?

 

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]

 

Constraints:

    1 <= nums.length <= 2 * 104
    -231 <= nums[i] <= 231 - 1
    0 <= k <= 105

*/
#include "common.h"
class Solution
{
public:
    //exceed time limit
    void rotate(vector<int> &nums, int k)
    {
        int len = nums.size();
        k = k % len;
        if (k == 0)
            return;
        int step = -1, start = len - 1, end = 0;
        if (k > (len >> 1))
        {
            step = 1;
            k = len - k;
            start = 0;
            end = len - 1;
        }
        for (int i = 0; i < k; ++i)
        {
            int s = start, e = end;
            int a = nums[start];
            while (s != e)
            {
                nums[s] = nums[s + step];
                s += step;
            }
            nums[s] = a;
        }
    }
    void rotate2(vector<int> &nums, int k)
    {
        static function<void(int, int, int)> f = [&](int l, int r, int kk) {
            //int len = nums.size();
            int len = r - l + 1;
            kk = kk % len;
            if (kk == 0)
                return;

            int dir = -1, start = r, end = r - len / kk * kk;
            if (kk > (len >> 1))
            {
                dir = 1;
                kk = len - kk;
                start = l;
                end = l + len / kk * kk;
            }
            auto step = dir * kk;
            for (int i = 0; i < kk; ++i)
            {
                auto s = start + dir * i, e = end + dir * i;
                if (e < l || e > r)
                    e -= step;
                auto a = nums[s];
                while (s != e)
                {
                    nums[s] = nums[s + step];
                    s += step;
                }
                nums[s] = a;
                cout << endl;
                for (auto ele : nums)
                    cout << ele << " ";
            }
            //
            if (dir > 0)
            {
                f(r + 1 - kk, r, len % kk);
            }
            else
            {
                f(l, l + kk - 1, kk - len % kk);
            }
        };
        f(0, nums.size() - 1, k);
    }
    void rotate3(vector<int> &nums, int k)
    {
        int len = nums.size();
        k = k % len;
        if (k == 0)
            return;
        // find greatest comon divisor
        // int m = len, kk = k;
        // while (kk)
        // {
        //     int temp = kk;
        //     kk = m % kk;
        //     m = temp;
        // }
        int m = gcd(len, k);
        for (int i = 0; i < m; ++i)
        {
            int pre, next = i;
            int a = nums[i];
            do
            {
                pre = next;
                next = pre - k;
                if (next < 0)
                    next += len;
                nums[pre] = nums[next];
            } while (next != i);
            nums[pre] = a;
        }
    }
    void rotate4(vector<int> &nums, int k)
    {
        int len = nums.size();
        k = k % len;
        if (k == 0)
            return;
        auto reversearray = [](vector<int> &nums, int l, int r) {
            while (l < r)
                swap(nums[l++], nums[r--]);
        };
        reversearray(nums, 0, len - 1);
        reversearray(nums, 0, k - 1);
        reversearray(nums, k, len - 1);
    }
};

int main()
{

    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int k;
    cout << "input k:";
    cin >> k;
    Solution s;
    s.rotate3(nums, k);
    cout << endl;
    for (auto e : nums)
        cout << e << " ";
}
