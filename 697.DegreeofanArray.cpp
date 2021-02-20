/*
Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.

Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.

 

Example 1:

Input: nums = [1,2,2,3,1]
Output: 2
Explanation: 
The input array has a degree of 2 because both elements 1 and 2 appear twice.
Of the subarrays that have the same degree:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
The shortest length is 2. So return 2.

Example 2:

Input: nums = [1,2,2,3,1,4,2]
Output: 6
Explanation: 
The degree is 3 because the element 2 is repeated 3 times.
So [2,2,3,1,4,2] is the shortest subarray, therefore returning 6.

 

Constraints:

    nums.length will be between 1 and 50,000.
    nums[i] will be an integer between 0 and 49,999.
*/
#include "common.h"
class Solution
{
public:
	int findShortestSubArray(vector<int> &nums)
	{
		int deg{}, maxIndex{};
		array<array<int, 2>, 50'000> counts{};
		for (int i = 0, len = nums.size(); i < len; ++i)
		{
			int a = nums[i];
			if (counts[a][0]++)
			{
				if (a == maxIndex || counts[a][0] > counts[maxIndex][0] || (counts[a][0] == counts[maxIndex][0] && (i - counts[a][1] < deg)))
				{
					maxIndex = a;
					deg = i - counts[a][1];
				}
			}
			else
				counts[a][1] = i;
		}
		return deg + 1;
	}
	int findShortestSubArray2(vector<int> &nums)
	{
		array<tuple<int, vector<int>::iterator>, 50'000> counts;
		int deg{}, maxIndex{};
		for (auto it = nums.begin(), end = nums.end(); it != end; ++it)
		{
			auto &&[a, b] = counts[*it];
			if (a++)
			{
				if (*it == maxIndex || a > get<0>(counts[maxIndex]) || (a == get<0>(counts[maxIndex]) && (it - b < deg)))
				{
					maxIndex = *it;
					deg = it - b;
				}
			}
			else
				b = it;
		}
		return deg + 1;
	}
};

int main()
{
	//vector<int> b{1, 2, 2, 3, 1, 4, 2};
	vector<int> b{1, 1, 2, 2, 2, 1};
	Solution s;
	//auto res=s.findShortestSubArray(b);

	//dbg(res);
	tuple<int, int> a{2, 3};
	cout << get<1>(a);
	get<1>(a) = 5;
	;
	cout << get<1>(a);
}