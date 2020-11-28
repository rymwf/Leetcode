/*
Given an array nums, we call (i, j) an important reverse pair if i < j and nums[i] > 2*nums[j].

You need to return the number of important reverse pairs in the given array.

Example1:

Input: [1,3,2,3,1]
Output: 2

Example2:

Input: [2,4,3,5,1]
Output: 3

Note:

    The length of the given array will not exceed 50,000.
    All the numbers in the input array are in the range of 32-bit integer.
*/
#include "common.h"

class BIT
{
private:
    vector<int> tree;
    int n;

public:
    BIT(int _n) : n(_n), tree(_n + 1) {}

    static constexpr int lowbit(int x)
    {
        return x & (-x);
    }

    void update(int x, int d)
    {
        while (x <= n)
        {
            tree[x] += d;
            x += lowbit(x);
        }
    }

    int query(int x) const
    {
        int ans = 0;
        while (x)
        {
            ans += tree[x];
            x -= lowbit(x);
        }
        return ans;
    }
};

class Solution
{
public:
    //exceed time limit
    int reversePairs(vector<int> &nums)
    {
        int ret = 0;
        map<int, int> map0;
        for (int i = 0, len = nums.size(); i < len; ++i)
        {
            map0[nums[i]]++;
            long a = 2 * long(nums[i]);
            for (auto it = map0.rbegin(); it != map0.rend() && it->first > a; ++it)
            {
                ret += it->second;
                if (it->first == nums[i])
                    ret--;
            }
        }
        return ret;
    }
    int reversePairs2(vector<int> &nums)
    {
        int ret = 0;
        static function<void(int, int)> f = [&](int l, int r) {
            if (l >= r)
                return;
            int mid = (l + r) / 2;
            f(l, mid);
            f(mid + 1, r);
            int i = l, j = mid + 1;
            while (i <= mid && j <= r)
            {
                if (nums[i] > 2 * long(nums[j]))
                {
                    ret += r - j + 1;
                    i++;
                    continue;
                }
                j++;
            }
            vector<int> temp;
            temp.reserve(r - l + 1);
            i = l, j = mid + 1;
            while (i <= mid && j <= r)
            {
                if (nums[i] < nums[j])
                {
                    temp.emplace_back(nums[j]);
                    j++;
                }
                else
                {
                    temp.emplace_back(nums[i]);
                    i++;
                }
            }
            //TODO:use memycpy and memmove
            if (i > mid)
                while (j <= r)
                    temp.emplace_back(nums[j++]);
            if (j > r)
                while (i <= mid)
                    temp.emplace_back(nums[i++]);
            for (int i = l; i <= r; ++i)
                nums[i] = temp[i - l];
        };
        f(0, nums.size() - 1);
        return ret;
    }
    int reversePairs3(vector<int> &nums)
    {
        set<long long> allNumbers;
        for (int x : nums)
        {
            allNumbers.insert(x);
            allNumbers.insert((long long)x * 2);
        }
        // 利用哈希表进行离散化
        unordered_map<long long, int> values;
        int idx = 0;
        for (long long x : allNumbers)
        {
            values[x] = ++idx;
        }

        int ret = 0;
        BIT bit(values.size());
        for (int i = 0; i < nums.size(); i++)
        {
            int left = values[(long long)nums[i] * 2], right = values.size();
            ret += bit.query(right) - bit.query(left);
            bit.update(values[nums[i]], 1);
        }
        return ret;
    }
};
int main()
{
    vector<int> a = {2, 4, 3, 5, 1};
    //vector<int> a={-5,-5,-5};

    //    for(auto& i:a)
    //        printf("%d ",i);
    Solution s;
    cout << s.reversePairs2(a);
}
