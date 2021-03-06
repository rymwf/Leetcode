/*
 Given a circular array (the next element of the last element is the first element of the array), print the Next Greater Number for every element. The Next Greater Number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, output -1 for this number.

Example 1:

Input: [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number; 
The second 1's next greater number needs to search circularly, which is also 2.

Note: The length of given array won't exceed 10000. 
 */
#include "common.h"

class Solution
{
public:
	vector<int> nextGreaterElements2(vector<int> &nums)
	{
		int len = nums.size();
		vector<int> ret(len, -1);
		stack<int> stk;
		for (int i = 0, n = (len << 1); i < n; ++i)
		{
			int k = i % len;
			while (!stk.empty() && nums[stk.top()] < nums[k])
			{
				ret[stk.top()] = nums[k];
				stk.pop();
			}
			stk.emplace(k);
		}
		return ret;
	}
};

int main()
{
	//vi a{1, 2, 3, 4, 5, 1, 2};
	vi a{1, 2, 2, 2, 5};
	//vi a{1, 1, 1};
	//vi a{1, 2, 1};
	Solution s;
	dbgvec(s.nextGreaterElements(a));
}
