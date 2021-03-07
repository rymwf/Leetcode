/*
Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

A palindrome string is a string that reads the same backward as forward.

 

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]

Example 2:

Input: s = "a"
Output: [["a"]]

 

Constraints:

    1 <= s.length <= 16
    s contains only lowercase English letters.
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

	vector<vector<string>> partition(string s)
	{
		vector<vector<string>> ret;
		vector<string> a;
		for (auto c : s)
			a.emplace_back(string(1, c));
		ret.emplace_back(std::move(a));
		static function<void(int)> f = [&](int i) {
			for (int j = 0, len = ret.size(); j < len; ++j)
			{
				int left = i, right = ret[j].size();
				if (left >= right)
					continue;
				for (++left; left < right; ++left)
				{
					if (isPalindrome(ret[j].begin() + i, ret[j].begin() + left))
					{
						ret.emplace_back();
						ret.back().insert(ret.back().end(), ret[j].begin(), ret[j].begin() + i);
						string b;
						for (auto tt = ret[j].begin() + i, tt2 = ret[j].begin() + left; tt <= tt2; ++tt)
							b += *tt;
						ret.back().emplace_back(b);
						ret.back().insert(ret.back().end(), ret[j].begin() + left + 1, ret[j].end());
					}
				}
			}
		};
		for (int i = 0, l = s.size(); i < l; ++i)
			f(i);
		return ret;
	}
};
int main()
{

	//string a{"ababab"};
	string a{"abaabaaba"};
	Solution s;
	auto res = s.partition(a);
	for (auto &&e : res)
	{
		dbgvec(e);
	}
}