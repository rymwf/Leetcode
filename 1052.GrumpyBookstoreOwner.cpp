/*
Today, the bookstore owner has a store open for customers.length minutes.  Every minute, some number of customers (customers[i]) enter the store, and all those customers leave after the end of that minute.

On some minutes, the bookstore owner is grumpy.  If the bookstore owner is grumpy on the i-th minute, grumpy[i] = 1, otherwise grumpy[i] = 0.  When the bookstore owner is grumpy, the customers of that minute are not satisfied, otherwise they are satisfied.

The bookstore owner knows a secret technique to keep themselves not grumpy for X minutes straight, but can only use it once.

Return the maximum number of customers that can be satisfied throughout the day.

 

Example 1:

Input: customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], X = 3
Output: 16
Explanation: The bookstore owner keeps themselves not grumpy for the last 3 minutes. 
The maximum number of customers that can be satisfied = 1 + 1 + 1 + 1 + 7 + 5 = 16.

 

Note:

    1 <= X <= customers.length == grumpy.length <= 20000
    0 <= customers[i] <= 1000
    0 <= grumpy[i] <= 1
*/
#include "common.h"
class Solution
{
public:
	int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int X)
	{
		int ret{}, maxadd{}, temp{};
		for (int l = 0, r = 0, len = customers.size(); r < len; ++r)
		{
			if (r - l >= X)
			{
				temp -= grumpy[l] ? customers[l] : 0;
				++l;
			}
			if (grumpy[r])
			{
				temp += customers[r];
				maxadd = max(temp, maxadd);
			}
			else
				ret += customers[r];
		}
		return ret + maxadd;
	}
	int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int X)
	{
		int ret{}, maxadd{}, temp{};
		int l = 0, r = 0, len = customers.size();
		for (; r < X; ++r)
		{
			temp += grumpy[r] * customers[r];
			ret += !grumpy[r] * customers[r];
		}
		maxadd = temp;
		for (; r < len; ++r, ++l)
		{
			temp -= grumpy[l] * customers[l];
			temp += grumpy[r] * customers[r];
			ret += !grumpy[r] * customers[r];
			maxadd = max(temp, maxadd);
		}
		return ret + maxadd;
	}
};
