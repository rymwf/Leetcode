/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

 

Example 1:

Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.

Example 2:

Input: s = "a"
Output: 0

Example 3:

Input: s = "ab"
Output: 1

 

Constraints:

    1 <= s.length <= 2000
    s consists of lower-case English letters only.
*/
#include "common.h"
class Solution
{
public:
	template <class It>
	constexpr bool isPalindrome(It left, It right)
	{
		while (left < right)
		{
			if (*left != *right)
				return false;
			++left;
			--right;
		}
		return true;
	}

	int minCut(string s)
	{
		int len = s.size();
		vector<int> dp(len + 1, INT_MAX);
		dp[0] = 0;
		for (int i = 0; i < len; ++i)
			for (int j = i; j >= 0; --j)
				if (dp[j] < dp[i + 1] - 1 && isPalindrome(s.begin() + j, s.begin() + i))
					dp[i + 1] = min(dp[j] + 1, dp[i + 1]);
		return dp.back() - 1;
	}
	int minCut2(string s)
	{
		int len = s.size();
		vector<int> dp(len + 1);
		vector<vector<bool>> isParl(len, vector<bool>(len, false));
		for (int i = 0; i < len; ++i)
		{
			dp[i + 1] = i + 1;
			isParl[i][i] = true;
			for (int j = i; j >= 0; --j)
			{
				if (s[j] == s[i] && (i - j < 2 || isParl[j + 1][i - 1]))
				{
					isParl[j][i] = true;
					dp[i + 1] = min(dp[j] + 1, dp[i + 1]);
				}
			}
		}
		return dp.back() - 1;
	}
};