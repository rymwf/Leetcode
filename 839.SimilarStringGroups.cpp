/*
Two strings X and Y are similar if we can swap two letters (in different positions) of X, so that it equals Y. Also two strings X and Y are similar if they are equal.

For example, "tars" and "rats" are similar (swapping at positions 0 and 2), and "rats" and "arts" are similar, but "star" is not similar to "tars", "rats", or "arts".

Together, these form two connected groups by similarity: {"tars", "rats", "arts"} and {"star"}.  Notice that "tars" and "arts" are in the same group even though they are not similar.  Formally, each group is such that a word is in the group if and only if it is similar to at least one other word in the group.

We are given a list strs of strings where every string in strs is an anagram of every other string in strs. How many groups are there?

 

Example 1:

Input: strs = ["tars","rats","arts","star"]
Output: 2

Example 2:

Input: strs = ["omv","ovm"]
Output: 1

 

Constraints:

    1 <= strs.length <= 100
    1 <= strs[i].length <= 1000
    sum(strs[i].length) <= 2 * 104
    strs[i] consists of lowercase letters only.
    All words in strs have the same length and are anagrams of each other.
*/
#include "common.h"

class Solution
{
public:
    int numSimilarGroups(vector<string> &strs)
    {
        int len = strs.size();
        vector<int> s(len, -1);
        int groupCount = len;
        static function<int(int)> find = [&](int e) {
            return s[e] < 0 ? e : s[e] = find(s[e]);
        };
        auto unite = [&](int root1, int root2) {
            if (s[root1] < s[root2])
                swap(root1, root2);
            s[root1] += s[root2];
            s[root2] = root1;
            --groupCount;
        };
        auto check = [](const auto &str1, const auto &str2) {
            bool ret = false;
            int l = -1, i = 0;
            for (int len = str1.size(); i < len; ++i)
            {
                if (str1[i] != str2[i])
                {
                    if (ret == true)
                        return false;
                    else if (l == -1)
                        l = i;
                    else if (str1[l] != str2[i] || str1[i] != str2[l])
                        return false;
                    else
                        ret = true;
                }
            }
            return true;
        };
        for (int i = 0; i < len; ++i)
        {
            for (int j = i + 1; j < len; ++j)
            {
                if (check(strs[i], strs[j]))
                {
                    auto r1 = find(i);
                    auto r2 = find(j);
                    if (r1 != r2)
                        unite(r1, r2);
                }
            }
        }
        return groupCount;
    }
};
int main()
{
    //vs strs = {"tars", "rats", "arts", "star"};
    vs strs = {"abab", "baba", "abba"};
    Solution s;
    auto res = s.numSimilarGroups(strs);
    dbg(res);
}

/*
abcd
cabd

*/