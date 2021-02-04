/*
Given an array consisting of n integers, find the contiguous subarray of given length k that has the maximum average value. And you need to output the maximum average value.

Example 1:

Input: [1,12,-5,-6,50,3], k = 4
Output: 12.75
Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75

 

Note:

    1 <= k <= n <= 30,000.
    Elements of the given array will be in the range [-10,000, 10,000].
*/
#include"common.h"
class Solution {
public:
	double findMaxAverage(vector<int> &nums, int k)
	{
		auto maxsum = reduce(nums.begin(), nums.begin() + k);
		auto temp = maxsum;
		for (int l = 0, r = k, len = nums.size(); r < len; ++r, ++l)
		{
			temp += nums[r] - nums[l];
			maxsum = max(maxsum, temp);
		}
		return double(maxsum) / k;
	}
};

