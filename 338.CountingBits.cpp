/*
 Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example 1:

Input: 2
Output: [0,1,1]

Example 2:

Input: 5
Output: [0,1,1,2,1,2]

Follow up:

    It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
    Space complexity should be O(n).
    Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
 */
#include "common.h"
class Solution
{
public:
	//could use dynamic programming
	vector<int> countBits(int num)
	{
		vector<int> ret(num + 1);
		auto bitcount = [](int a) {
			int count{};
			while (a > 0)
			{
				count += a & 1;
				a >>= 1;
			}
			return count;
		};
		while (num >= 0)
		{
			ret[num] = bitcount(num);
			--num;
		}
		return ret;
	}

	vector<int> countBits2(int num)
	{
		vector<int> ret(num + 1);
		for (int i = 1, j = 1, len = 1; len <= num;)
		{
			len = min(len << 1, num + 1);
			for (i = 0; j < len; ++i, ++j)
				ret[j] = ret[i] + 1;
		}
		return ret;
	}
};
