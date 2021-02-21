/*
Given an array of integers nums and an integer limit, return the size of the longest non-empty subarray such that the absolute difference between any two elements of this subarray is less than or equal to limit.

 

Example 1:

Input: nums = [8,2,4,7], limit = 4
Output: 2 
Explanation: All subarrays are: 
[8] with maximum absolute diff |8-8| = 0 <= 4.
[8,2] with maximum absolute diff |8-2| = 6 > 4. 
[8,2,4] with maximum absolute diff |8-2| = 6 > 4.
[8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
[2] with maximum absolute diff |2-2| = 0 <= 4.
[2,4] with maximum absolute diff |2-4| = 2 <= 4.
[2,4,7] with maximum absolute diff |2-7| = 5 > 4.
[4] with maximum absolute diff |4-4| = 0 <= 4.
[4,7] with maximum absolute diff |4-7| = 3 <= 4.
[7] with maximum absolute diff |7-7| = 0 <= 4. 
Therefore, the size of the longest subarray is 2.

Example 2:

Input: nums = [10,1,2,4,7,2], limit = 5
Output: 4 
Explanation: The subarray [2,4,7,2] is the longest since the maximum absolute diff is |2-7| = 5 <= 5.

Example 3:

Input: nums = [4,2,2,2,4,4,2,2], limit = 0
Output: 3

 

Constraints:

    1 <= nums.length <= 10^5
    1 <= nums[i] <= 10^9
    0 <= limit <= 10^9

*/
#include"common.h"
class Solution {
public:
	int longestSubarray(vector<int> &nums, int limit)
	{
		multiset<pair<int, vector<int>::iterator>> myset;
		int ret{};
		auto it = nums.begin(), it2 = it;
		for (auto end = nums.end(); it != end; ++it)
		{
			myset.emplace(*it, it);
			ret = max(ret, static_cast<int>(it - it2));
			while (myset.rbegin()->first - myset.begin()->first > limit)
			{
				if (myset.rbegin()->second > myset.begin()->second)
				{
					if (myset.begin()->second >= it2)
						it2 = myset.begin()->second + 1;
					myset.erase(myset.begin());
				}
				else
				{
					if (myset.rbegin()->second >= it2)
						it2 = myset.rbegin()->second + 1;
					myset.erase(--myset.end());
				}
			}
		}
		return max(ret, static_cast<int>(it - it2));
	}
};
int main(){
	//vi a = {4, 2, 2, 2, 4, 2, 2};
	//vi a = {4, 8, 5, 1, 7, 9};
	//vi a = {8, 2, 4, 7};
	vi a = {2,2,2,4,4,2,5,5,5,5,5,2};
	Solution s;
	dbg(s.longestSubarray(a, 0));
}
