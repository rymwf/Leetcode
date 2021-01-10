/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

    The same word in the dictionary may be reused multiple times in the segmentation.
    You may assume the dictionary does not contain duplicate words.

Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.

Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false
*/
#include "common.h"
class Solution
{
public:
    //exceed time limit
    bool wordBreak(string s, vector<string> &wordDict)
    {
        bool a[128]{};
        for (auto c : s)
            a[c] = true;
        unordered_set<char> temp;
        unordered_set<string> dict;
        set<int> wordlens;
        for (auto &str : wordDict)
        {
            for (auto c : str)
                temp.emplace(c);
            dict.emplace(str);
            wordlens.emplace(str.size());
        }
        for (int i = 0; i < 128; ++i)
        {
            if (a[i] && temp.find(i) == temp.end())
                return false;
        }
        return helper(s, dict, wordlens, 0);
    }
    bool helper(
        const string &s,
        const unordered_set<string> &dict,
        const set<int> &wordlens,
        size_t index)
    {
        dbg(index);
        if (index == s.size())
            return true;
        for (auto it = wordlens.rbegin(); it != wordlens.rend(); ++it)
        {
            if (static_cast<size_t>(index + *it) > s.size() + 1)
                continue;
            string substr = s.substr(index, *it);
            dbg(substr);
            if (dict.find(substr) != dict.end())
            {
                if (helper(s, dict, wordlens, *it + index))
                    return true;
            }
        }
        return false;
    }
    bool wordBreak2(string s, vector<string> &wordDict)
    {
        int len = s.size();
        unordered_set<string> dict;
        vector<bool> state(len + 1);
        set<int> wordlens;
        for (auto &str : wordDict)
        {
            dict.emplace(str);
            wordlens.emplace(str.size());
        }
        state[0] = true;
        for (int i = 1; i <= len; ++i)
        {
            for (auto it = wordlens.begin(); it != wordlens.end(); ++it)
            {
                int l = i - *it;
                if (l < 0)
                    break;
                if (state[l])
                {
                    string substr = s.substr(l, *it);
                    if (dict.find(substr) != dict.end())
                    {
                        state[i] = true;
                        break;
                    }
                }
            }
            cout << i << " " << state[i] << endl;
        }
        return state[len];
    }
};
int main()
{
    string s = "catsandog";
    vector<string> wordDict = {"cats", "dog", "sand", "and", "cat"};
    //    string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    //    vector<string> wordDict = {"a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa"};
    //    string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    //    vs wordDict = {"aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa", "ba"};
    Solution ss;
    auto res = ss.wordBreak2(s, wordDict);
    dbg(res);
}
