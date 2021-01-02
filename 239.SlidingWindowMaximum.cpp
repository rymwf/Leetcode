/*
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

 

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

Example 2:

Input: nums = [1], k = 1
Output: [1]

Example 3:

Input: nums = [1,-1], k = 1
Output: [1,-1]

Example 4:

Input: nums = [9,11], k = 2
Output: [11]

Example 5:

Input: nums = [4,-2], k = 2
Output: [4]

 

Constraints:

    1 <= nums.length <= 105
    -104 <= nums[i] <= 104
    1 <= k <= nums.length
*/
#include "common.h"
class Solution
{
public:
    //too slow
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int len = nums.size();
        multiset<int> tempset;
        for (int i = 0; i < k; ++i)
            tempset.emplace(nums[i]);
        vector<int> ret{};
        for (int i = k; i < len; ++i)
        {
            ret.emplace_back(*tempset.rbegin());
            tempset.erase(tempset.find(nums[i - k]));
            tempset.emplace(nums[i]);
        }
        ret.emplace_back(*tempset.rbegin());
        return ret;
    }
    //
    vector<int> maxSlidingWindow2(vector<int> &nums, int k)
    {
        deque<int> dq;
        int len=nums.size();
        int n=len-k+1;
        vector<int> ret(n);
        dq.emplace_back(0);
        for(int i=1;i<k;++i)
        {
            if (nums[dq.back()] <= nums[i])
            {
                dq.clear();
                dq.emplace_back(i);
            }else{
                while(nums[dq.front()]<=nums[i])dq.pop_front();
                dq.emplace_front(i);
            }
        }
        ret[0]=nums[dq.back()];
        for(int i=k;i<len;++i)
        {
            while (!dq.empty()&&dq.back() <= i - k)
                dq.pop_back();
            if(dq.empty()|nums[dq.back()]<=nums[i]){
                dq.clear();
                dq.emplace_back(i);
            }else{
                while(nums[dq.front()]<=nums[i]||dq.front()<=i-k)dq.pop_front();
                dq.emplace_front(i);
            }
            ret[i-k+1]=nums[dq.back()];
        }
        return ret;
    }
};
int main()
{
    vector<int> nums = {1,-1};
    int k = 1;
    Solution s;
    auto res=s.maxSlidingWindow2(nums, k);
    for(auto c:res)
        cout<<c<<" ";
}
