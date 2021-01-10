/*
You are given a string s, and an array of pairs of indices in the string pairs where pairs[i] = [a, b] indicates 2 indices(0-indexed) of the string.

You can swap the characters at any pair of indices in the given pairs any number of times.

Return the lexicographically smallest string that s can be changed to after using the swaps.

 

Example 1:

Input: s = "dcab", pairs = [[0,3],[1,2]]
Output: "bacd"
Explaination: 
Swap s[0] and s[3], s = "bcad"
Swap s[1] and s[2], s = "bacd"

Example 2:

Input: s = "dcab", pairs = [[0,3],[1,2],[0,2]]
Output: "abcd"
Explaination: 
Swap s[0] and s[3], s = "bcad"
Swap s[0] and s[2], s = "acbd"
Swap s[1] and s[2], s = "abcd"

Example 3:

Input: s = "cba", pairs = [[0,1],[1,2]]
Output: "abc"
Explaination: 
Swap s[0] and s[1], s = "bca"
Swap s[1] and s[2], s = "bac"
Swap s[0] and s[1], s = "abc"

 

Constraints:

    1 <= s.length <= 10^5
    0 <= pairs.length <= 10^5
    0 <= pairs[i][0], pairs[i][1] < s.length
    s only contains lower case English letters.
*/
#include"common.h"

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int len = s.size();
        UnionFindTree ufd(len);
//        UnionFindList ufd(len);
        for(auto& p:pairs)
            ufd.uniteEle(p[0],p[1]);
//        unordered_map<int, priority_queue<char, vector<char>, greater<char>>> mymap;
        unordered_map<int, vector<char>> mymap;
        for(int i=0;i<len;++i)
        {
            mymap[ufd.find(i)].emplace_back(s[i]);
        }
        for(auto& ele:mymap)
            sort(ele.second.begin(), ele.second.end(), greater<char>());
        string ret;
        ret.resize(len);
        for(int i=0;i<len;++i)
        {
            auto &a = mymap[ufd.find(i)];
            ret[i] = a.back();
            a.pop_back();
        }
        return ret;
    }
};
int main(){
    string s = "dcab";
    vvi pairs = {{0, 3}, {1, 2}};

    Solution ss;
    ss.smallestStringWithSwaps(s, pairs);
}
