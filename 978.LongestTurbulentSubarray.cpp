/*
Given an integer array arr, return the length of a maximum size turbulent subarray of arr.

A subarray is turbulent if the comparison sign flips between each adjacent pair of elements in the subarray.

More formally, a subarray [arr[i], arr[i + 1], ..., arr[j]] of arr is said to be turbulent if and only if:

    For i <= k < j:
        arr[k] > arr[k + 1] when k is odd, and
        arr[k] < arr[k + 1] when k is even.
    Or, for i <= k < j:
        arr[k] > arr[k + 1] when k is even, and
        arr[k] < arr[k + 1] when k is odd.

 

Example 1:

Input: arr = [9,4,2,10,7,8,8,1,9]
Output: 5
Explanation: arr[1] > arr[2] < arr[3] > arr[4] < arr[5]

Example 2:

Input: arr = [4,8,12,16]
Output: 2

Example 3:

Input: arr = [100]
Output: 1

 

Constraints:

    1 <= arr.length <= 4 * 104
    0 <= arr[i] <= 109
*/
#include "common.h"

class Solution
{
public:
	int maxTurbulenceSize(vector<int> &arr)
	{
		int len = arr.size();
		if (len < 2)
			return len;
		adjacent_difference(arr.begin(), arr.end(), arr.begin());
		dbgvec(arr);
		int ret = 0;
		int temp = 0;
		for (int i = 1; i < len; ++i)
		{
			if (arr[i] == 0)
				temp = 0;
			else if ((arr[i] ^ arr[i - 1]) >= 0)
				temp = 1;
			else
				++temp;
			ret = max(temp + 1, ret);
		}
		return ret;
	}
	int maxTurbulenceSize2(vector<int> &arr)
	{
		int ret = 1;
		int n = arr.size();
		int dp0 = 1, dp1 = 1;
		for (int i = 1; i < n; i++)
		{
			if (arr[i - 1] > arr[i])
			{
				dp0 = dp1 + 1;
				dp1 = 1;
			}
			else if (arr[i - 1] < arr[i])
			{
				dp1 = dp0 + 1;
				dp0 = 1;
			}
			else
			{
				dp0 = 1;
				dp1 = 1;
			}
			ret = max(ret, dp0);
			ret = max(ret, dp1);
		}
		return ret;
	}
};
int main()
{
	vi arr = {9, 4, 4, 2, 10, 7, 8, 8, 1, 9};
	Solution s;
	auto res = s.maxTurbulenceSize(arr);
	dbg(res);
}
