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
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        int len = s.size();
        unordered_set<string> dict;
        vector<vector<int>> state(len + 1);
        unordered_set<int> wordlens;
        for (auto &str : wordDict)
        {
            dict.emplace(str);
            wordlens.emplace(str.size());
        }
        state[len] = {len};
        for (int i = len - 1; i >= 0; --i)
        {
            for (auto it = wordlens.begin(); it != wordlens.end(); ++it)
            {
                int l = i + *it;
                if (l > len)
                    continue;
                if (!state[l].empty())
                {
                    string substr = s.substr(i, *it);
                    if (dict.find(substr) != dict.end())
                    {
                        state[i].emplace_back(l);
        //                cout << i << ": " << l << endl;
                    }
                }
            }
        }
        vector<string> ret;
        if (!state[0].empty())
        {
            string tempstrs;
            helper(ret, s, state, tempstrs, 0);
        }
        return ret;
    }

    void helper(
        vector<string> &ret,
        string &s,
        vector<vector<int>> &state,
        string &tempstr,
        size_t index)
    {
        if (index == s.size())
        {
            ret.emplace_back(tempstr.substr(0, tempstr.size() - 1));
            return;
        }
        for (auto e : state[index])
        {
            int l = e - index;
            string substr = s.substr(index, l);
            tempstr += substr + " ";
            helper(ret, s, state, tempstr, e);
            tempstr.erase(tempstr.size() - l - 1, l + 1);
        }
    }
    vector<string> wordBreak2(string s, vector<string> &wordDict)
    {
        int len = s.size();
        unordered_set<string> dict;
        vector<vector<int>> state(len + 1);
        unordered_set<int> wordlens;
        for (auto &str : wordDict)
        {
            dict.emplace(str);
            wordlens.emplace(str.size());
        }
        state[len] = {len};
        for (int i = len - 1; i >= 0; --i)
        {
            for (auto it = wordlens.begin(); it != wordlens.end(); ++it)
            {
                int l = i + *it;
                if (l > len)
                    continue;
                if (!state[l].empty())
                {
                    string substr = s.substr(i, *it);
                    if (dict.find(substr) != dict.end())
                    {
                        state[i].emplace_back(l);
                    }
                }
            }
        }
        vector<string> ret;
        if (!state[0].empty())
        {
            string tempstr;
            static function<void(size_t)> helper2 = [&](size_t index) {
                if (index == len)
                {
                    ret.emplace_back(tempstr.substr(0, tempstr.size() - 1));
                    return;
                }
                for (auto e : state[index])
                {
                    int l = e - index;
                    string substr = s.substr(index, l);
                    tempstr += substr + " ";
                    helper2(e);
                    tempstr.erase(tempstr.size() - l - 1, l + 1);
                }
            };
            helper2(0);
        }
        return ret;
    }
};

int main()
{
    string s = "pineapplepenapple";
    vector<string> wordDict = {"apple", "pen", "applepen", "pine", "pineapple"};
    //string s = "catsanddog";
    //vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
    //string s = "catsandog";
    //vector<string> wordDict = {"cats", "dog", "sand", "and", "cat"};
    //    string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    //    vector<string> wordDict = {"a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa"};

    Solution S;
    auto res = S.wordBreak(s, wordDict);
    for (auto &i : res)
        cout << i << endl;
}
