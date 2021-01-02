/*
Given an integer array nums, return the number of range sums that lie in [lower, upper] inclusive.
Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j (i ≤ j), inclusive.

Note:
A naive algorithm of O(n2) is trivial. You MUST do better than that.

Example:

Input: nums = [-2,5,-1], lower = -2, upper = 2,
Output: 3 
Explanation: The three ranges are : [0,0], [2,2], [0,2] and their respective sums are: -2, -1, 2.

 

Constraints:

    0 <= nums.length <= 10^4
*/
#include "common.h"

class Solution {
public:
    //exceed time limit
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int len = nums.size();
        if (len == 0)
            return 0;
        int ret{};
        for (int i = 0; i < len; ++i)
        {
            long long temp{};
            for (int j = i; j < len; ++j)
            {
                temp += nums[j];
                if (temp <= upper && temp >= lower)
                    ret++;
            }
        }
        return ret;
    }

    //slow
    int countRangeSum2(vector<int>& nums, int lower, int upper) {
        int len = nums.size();
        if (len == 0)
            return 0;
        using ll=long long;
        vector<ll> temp(len + 1);
        temp[0]=0;
        multimap<ll, int> mymap;
        for (int i = 0; i < len; ++i)
        {
            temp[i + 1] = temp[i] + nums[i];
            mymap.emplace(temp[i + 1], i);
        }
        int ret{};
        for (int i = 0; i < len; ++i)
        {
            ll a = lower + temp[i];
            ll b = upper + temp[i];
            ////for (auto it = mymap.lower_bound(a); it != mymap.end() && it->first <= b; ++it)
            for (auto it = mymap.lower_bound(a), it0 = mymap.upper_bound(b); it != it0; ++it)
            {
                if (it->second >= i)
                    ret++;
            }
        }
        return ret;
    }
    int countRangeSum3(vector<int>& nums, int lower, int upper) {
 //       int len = nums.size();
 //       if (len == 0)
 //           return 0;
 //       using ll=long long;
 //       vector<ll> numsum(nums.begin(),nums.end());
 //       vector<pair<ll,int>> temp(nums.size());
 //       temp[0] = {nums[0], 0};
 //       for(int i=1;i<len;++i)
 //       {
 //           numsum[i] += numsum[i - 1];
 //           temp[i] = {numsum[i], i};
 //       }
 //       sort(temp.begin(),temp.end());
////        static auto findlowerbound=[&nums](int a){
////            
////        };

 //       return 0;    
    }
};

int main(){
    vector<int> nums = {0, -1, -2, -3, 0, 2};
    int lower = 3, upper = 5;
    Solution s;
    s.countRangeSum2(nums, lower, upper);
}