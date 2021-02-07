/*
Given two strings text1 and text2, return the length of their longest common subsequence.

A subsequence of a string is a new string generated from the original string with some characters(can be none) deleted without changing the relative order of the remaining characters. (eg, "ace" is a subsequence of "abcde" while "aec" is not). A common subsequence of two strings is a subsequence that is common to both strings.

 

If there is no common subsequence, return 0.

 

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.

Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.

Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.

 

Constraints:

    1 <= text1.length <= 1000
    1 <= text2.length <= 1000
    The input strings consist of lowercase English characters only.
 */
#include "common.h"

class Solution
{
public:
	int longestCommonSubsequence(string text1, string text2)
	{
		int n1 = text1.size(), n2 = text2.size();
		vector<vector<int>> temp(n1 + 1, vector<int>(n2 + 1));
		for (int i = n1 - 1; i >= 0; --i)
		{
			for (int j = n2 - 1; j >= 0; --j)
			{
				if (text1[i] == text2[j])
					temp[i][j] += temp[i + 1][j + 1] + 1;
				else
					temp[i][j] = max(temp[i + 1][j], temp[i][j + 1]);
			}
		}
		return temp[0][0];
	}
	int longestCommonSubsequence2(string text1, string text2)
	{
		int n1 = text1.size(), n2 = text2.size();
		vector<int> temp(n2 + 1);
		for (int i = n1 - 1; i >= 0; --i)
		{
			int pre{};
			for (int j = n2 - 1; j >= 0; --j)
			{
				auto a = text1[i] == text2[j] ? pre + 1 : max(temp[j], temp[j + 1]);
				pre = temp[j];
				temp[j] = a;
			}
		}
		return temp[0];
	}
};

int main()
{
	string a = "bsbinm";
	string b = "jmbkv";

	//string a="ghbrgc";
	//string b="hafcdqbgncrcbihkd";
	//	string a = "mhunuzqrkzsnidwbun";
	//	string b = "szuluspmhwpazoxijwbq";
	//string a="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
	//;string b="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
	//;

	Solution s;
	printf("\n");
	printf("%d ", s.longestCommonSubsequence2(a, b));
}