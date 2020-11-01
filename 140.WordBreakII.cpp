/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.

Note:

    The same word in the dictionary may be reused multiple times in the segmentation.
    You may assume the dictionary does not contain duplicate words.

Example 1:

Input:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
Output:
[
  "cats and dog",
  "cat sand dog"
]

Example 2:

Input:
s = "pineapplepenapple"
wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
Output:
[
  "pine apple pen apple",
  "pineapple pen apple",
  "pine applepen apple"
]
Explanation: Note that you are allowed to reuse a dictionary word.

Example 3:

Input:
s = "catsandog"
wordDict = ["cats", "dog", "sand", "and", "cat"]
Output:
[]
*/
#include "common.h"
class Solution
{
public:
    //TODO: cannot pass last case  listed below
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        vector<string> ret;
        vector<vector<int>> flags(1, vector<int>(1, 0));
        unordered_set<string> myset;
        for (auto &i : wordDict)
            myset.emplace(i);
        for (int i = 0; i <= s.size(); ++i)
        {
            int l = flags.size();
            for (int j = 0; j < l; ++j)
            {
                if (myset.count(s.substr(flags[j].back(), i - flags[j].back())))
                {
                    flags.emplace_back(flags[j]);
                    flags.back().emplace_back(i);
                }
            }
        }
        for (int i = flags.size() - 1; i >= 0; --i)
        {
            if (flags[i].back() != s.size())
                break;
            std::string temp;
            for (int j = 1; j < flags[i].size(); ++j)
            {
                temp += s.substr(flags[i][j - 1], flags[i][j] - flags[i][j - 1]);
                temp += " ";
            }
            temp.erase(temp.size() - 1);
            ret.emplace_back(temp);
        }
        return ret;
    }
};

int main()
{
    //string s = "pineapplepenapple";
    //vector<string> wordDict = {"apple", "pen", "applepen", "pine", "pineapple"};
    //string s = "catsanddog";
    //vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
    //string s = "catsandog";
    //vector<string> wordDict = {"cats", "dog", "sand", "and", "cat"};
    string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    vector<string> wordDict = {"a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa"};

    Solution S;
    auto res = S.wordBreak(s, wordDict);
    for (auto &i : res)
        cout << i << endl;
}
