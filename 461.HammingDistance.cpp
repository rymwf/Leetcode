/*
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 ≤ x, y < 231.

Example:

Input: x = 1, y = 4

Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑

The above arrows point to positions where the corresponding bits are different.
*/
#include "common.h"

class Solution
{
public:
	int hammingDistance(int x, int y)
	{
		int ret = 0;
		x ^= y;
		while (x > 0)
		{
			ret += (x & 1);
			x >>= 1;
		}
		return ret;
	}
	int hammingDistance(int x, int y)
	{
		return bitset<32>(x ^ y).count();
	}
	int hammingDistance(int x, int y)
	{
		int z = x ^ y;
		z = (z & 0x55555555) + ((z >> 1) & 0x55555555);
		z = (z & 0x33333333) + ((z >> 2) & 0x33333333);
		z = (z & 0x0f0f0f0f) + ((z >> 4) & 0x0f0f0f0f);
		z = (z & 0x00ff00ff) + ((z >> 8) & 0x00ff00ff);
		z = (z & 0x0000ffff) + ((z >> 16) & 0x0000ffff);
		return (int)z;
	}
};