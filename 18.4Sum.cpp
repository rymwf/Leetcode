/*
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Notice that the solution set must not contain duplicate quadruplets.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Example 2:

Input: nums = [], target = 0
Output: []

 

Constraints:

    0 <= nums.length <= 200
    -109 <= nums[i] <= 109
    -109 <= target <= 109
*/

#include "common.h"

class Solution
{
public:
    // too slow
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> res;
        if (nums.size() < 4)
            return res;
        map<int, int> mymap;
        int smallest = 0;
        int largest = 0;
        for (auto &i : nums)
        {
            mymap[i]++;
        }
        int i = 4;
        auto it = mymap.begin();
        while (i > 0 && it->first < 0)
        {
            int temp = it->second;
            while (temp-- > 0)
            {
                smallest += it->first;
                i--;
            }
            it++;
        }
        auto it2 = mymap.rbegin();
        i = 4;
        while (i > 0 && it2->first > 0)
        {
            int temp = it2->second;
            while (temp-- > 0)
            {
                largest += it2->first;
                i--;
            }
            it2--;
        }
        printf("smallest:%d, largest:%d\n", smallest, largest);
        if (target > largest || target < smallest)
            return res;
        vector<int> ele;
        static function<void(map<int, int>::iterator)> f = [&](map<int, int>::iterator it) {
            if (ele.size() == 3)
            {
                auto it2 = mymap.find(target);
                if (it2 != mymap.end() && it2->first >= it->first && it2->second > 0)
                {
                    ele.emplace_back(it2->first);
                    res.emplace_back(ele);
                    ele.pop_back();
                    return;
                }
                else
                    return;
            }
            if (it == mymap.end())
                return;
            if (it->second == 0)
                it++;
            for (auto it2 = it; it2 != mymap.end(); ++it2)
            {
                ele.emplace_back(it2->first);
                target -= it2->first;
                it2->second--;
                f(it2);
                ele.pop_back();
                it2->second++;
                target += it2->first;
            }
        };
        f(mymap.begin());
        return res;
    }
    //too slow
    vector<vector<int>> fourSum2(vector<int> &nums, int target)
    {
        vector<vector<int>> res;
        if (nums.size() < 4)
            return res;
        map<int, int> mymap;
        int a = INT_MAX; //smallest abs
        for (auto &i : nums)
        {
            a = abs(i) < abs(a) ? i : a;
            mymap[i]++;
        }
        map<int, int>::iterator itor1 = mymap.find(a);
        if(a<0)itor1++;
        map<int, int>::reverse_iterator itor2 = make_reverse_iterator(itor1);
        vector<int> ele;
        int t = 0;
        int i = 0;
        static function<void(map<int, int>::iterator, map<int, int>::reverse_iterator, bool, int)> f = [&](map<int, int>::iterator it1, map<int, int>::reverse_iterator it2, bool flag, int i) {
            if (i == 3)
            {
                auto it = mymap.find(target - t);
                if (it != mymap.end() && ((it1 != mymap.end() && it->first >= it1->first) || (it2 != mymap.rend() && it->first <= it2->first)) && it->second > 0)
                {
                    ele.emplace_back(it->first);
                    res.emplace_back(ele);
                    ele.pop_back();
                }
                return;
            }
            if (flag)
            {
                if(it1==mymap.end())return;
                if (it1->second == 0)
                    it1++;
                for (; it1 != mymap.end(); ++it1)
                {
                    ele.emplace_back(it1->first);
                    it1->second--;
                    i++;
                    t += it1->first;
                    f(it1,it2,t <= target, i);
                    t -= it1->first;
                    i--;
                    it1->second++;
                    ele.pop_back();
                }
            }
            else
            {
                if (it2 == mymap.rend())
                    return;
                if (it2->second == 0)
                    it2++;
                for (; it2 != mymap.rend(); ++it2)
                {
                    ele.emplace_back(it2->first);
                    it2->second--;
                    i++;
                    t += it2->first;
                    f(it1,it2,t <= target, i);
                    t -= it2->first;
                    i--;
                    it2->second++;
                    ele.pop_back();
                }
            }
        };
        f(itor1,itor2,t <= target, i);
        return res;
    }
};

int main()
{
    printf("============\n");
    //    vector<int> num{0,0,0,0,0};
    //vector<int> num{5, 0, -1, 5, 1};
    //vector<int> num{2,0,3,0,1,2,4}; //7
    vector<int> num{4,-9,-2,-2,-7,9,9,5,10,-10,4,5,2,-4,-2,4,-9,5}; //-13

    //vector<int> num{1, 0, -1, 0, -2, 2};
    //vector<int> num{};
    //vector<int> num{1, -2, -5, -4, -3, 3, 3, 5};
    //vector<int> num{-479, -472, -469, -461, -456, -420, -412, -403, -391, -377, -362, -361, -340, -336, -336, -323, -315, -301, -288, -272, -271, -246, -244, -227, -226, -225, -210, -194, -190, -187, -183, -176, -167, -143, -140, -123, -120, -74, -60, -40, -39, -37, -34, -33, -29, -26, -23, -18, -17, -11, -9, 6, 8, 20, 29, 35, 45, 48, 58, 65, 122, 124, 127, 129, 145, 164, 182, 198, 199, 206, 207, 217, 218, 226, 267, 274, 278, 278, 309, 322, 323, 327, 350, 361, 372, 376, 387, 391, 434, 449, 457, 465, 488};
    int target = -13;
    //int target = 0;
    //int target = 654;
    //    int target=1979;

    Solution s;
    auto res = s.fourSum2(num, target);
    for (auto &a : res)
    {
        for (auto &i : a)
        {
            printf("%d ", i);
        }
        printf("\n");
    }
}
