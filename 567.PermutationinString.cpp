/*
Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

 

Example 1:

Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:

Input:s1= "ab" s2 = "eidboaoo"
Output: False

 

Constraints:

    The input strings only contain lower case letters.
    The length of both given strings is in range [1, 10,000].
*/
#include "common.h"
class Solution
{
public:
	bool checkInclusion(string s1, string s2)
	{
		int map1[26]{};
		for (auto c : s1)
			++map1[c - 'a'];
		int tempmap[26]{};
		bool flag = false;
		for (int l = 0, r = 0, len1 = s1.size() - 1, len2 = s2.size(); r < len2; ++r)
		{
			size_t c = s2[r] - 'a';
			if (map1[c] == 0)
			{
				if (flag)
				{
					memset(tempmap, 0, 104);
					flag = false;
				}
				l = r + 1;
			}
			else if (map1[c] > tempmap[c])
			{
				if (r - l == len1)
					return true;
				++tempmap[c];
				flag = true;
			}
			else
			{
				while (s2[l] != s2[r])
					--tempmap[s2[l++] - 'a'];
				++l;
				flag = true;
			}
		}
		return false;
	}
};
int main()
{
	string a = "ba", b = "eidacacco";
	Solution s;
	s.checkInclusion(a, b);
}
