/*
Given a string s that consists of only uppercase English letters, you can perform at most k operations on that string.

In one operation, you can choose any character of the string and change it to any other uppercase English character.

Find the length of the longest sub-string containing all repeating letters you can get after performing the above operations.

Note:
Both the string's length and k will not exceed 104.

Example 1:

Input:
s = "ABAB", k = 2

Output:
4

Explanation:
Replace the two 'A's with two 'B's or vice versa.

 

Example 2:

Input:
s = "AABABBA", k = 1

Output:
4

Explanation:
Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.

*/
#include "common.h"
class Solution
{
public:
	int characterReplacement(string s, int k)
	{
		int lens = s.size();
		if (lens == 0)
			return 0;
		vector<int> temp[26];
		temp[s[0] - 'A'].emplace_back(0);
		for (int i = 1; i < lens; ++i)
		{
			if (s[i] != s[i - 1])
			{
				temp[s[i - 1] - 'A'].emplace_back(i);
				temp[s[i] - 'A'].emplace_back(i);
			}
		}
		int maxLen = 0;
		for (int i = 0; i < 26; ++i)
		{
			int k2 = k;
			int l = 0, r = 2, len = temp[i].size();
			if (len == 0)
				continue;
			for (; r < len; r += 2)
			{
				int interval = temp[i][r] - temp[i][r - 1];
				while (k2 < interval && l < r)
				{
					maxLen = max(maxLen, temp[i][r - 1] - temp[i][l] + k2);
					l += 2;
					k2 += temp[i][l] - temp[i][l - 1];
				}
				if (k2 >= interval)
					k2 -= interval;
			}
			if (r == len)
				maxLen = max(maxLen, temp[i][r - 1] - temp[i][l] + k2);
			else
				maxLen = max(maxLen, lens - temp[i][l] + k2);
		}
		return min(maxLen, lens);
	}
	int characterReplacement2(string s, int k)
	{
		vector<int> num(26);
		int n = s.length();
		int maxn = 0;
		int left = 0, right = 0;
		while (right < n)
		{
			num[s[right] - 'A']++;
			maxn = max(maxn, num[s[right] - 'A']);
			if (right - left + 1 - maxn > k)
			{
				num[s[left] - 'A']--;
				left++;
			}
			right++;
		}
		return right - left;
	}
};

int main()
{
	string s = "AABABBAAAABABAAAABBBBBAA";
	int k = 10;
	Solution S;
	auto res = S.characterReplacement(s, k);
	dbg(res);
}