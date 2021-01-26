/*
Given a list of dominoes, dominoes[i] = [a, b] is equivalent to dominoes[j] = [c, d] if and only if either (a==c and b==d), or (a==d and b==c) - that is, one domino can be rotated to be equal to another domino.

Return the number of pairs (i, j) for which 0 <= i < j < dominoes.length, and dominoes[i] is equivalent to dominoes[j].

 

Example 1:

Input: dominoes = [[1,2],[2,1],[3,4],[5,6]]
Output: 1

 

Constraints:

    1 <= dominoes.length <= 40000
    1 <= dominoes[i][j] <= 9

*/
#include"common.h"

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>> &dominoes)
    {
        struct KeyHash
        {
            std::size_t operator()(const std::vector<int> &k) const
            {
                return std::hash<int>()(k[0]) ^ (std::hash<int>()(k[1]) << 1);
            }
        };
        unordered_map<vector<int>, int, KeyHash> tempmap;
        int count = 0;
        for (auto &domino : dominoes)
        {
            if (domino[0] > domino[1])
                swap(domino[0], domino[1]);
            count += tempmap[domino]++;
        }
        return count;
    }
    int numEquivDominoPairs2(vector<vector<int>>& dominoes) {
        unordered_map<int, int> tempmap;
        int count = 0;
        for (auto &domino : dominoes)
        {
            if (domino[0] > domino[1])
                swap(domino[0], domino[1]);
            count += tempmap[domino[0] * 10 + domino[1]]++;
        }
        return count;
    }
};



