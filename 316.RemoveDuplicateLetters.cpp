/*
Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

Note: This question is the same as 1081: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/

 

Example 1:

Input: s = "bcabc"
Output: "abc"

Example 2:

Input: s = "cbacdcbc"
Output: "acdb"

 

Constraints:

    1 <= s.length <= 104
    s consists of lowercase English letters.
*/
#include"common.h"

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int a[26];
        memset(a,0,104);
        for(auto& c:s)
            a[c-'a']++;
        string ret;
        for(int i=0,len=s.size();i<len;++i)
        {
            if (ret.find(s[i]) == string::npos)
            {
                while (!ret.empty() && ret.back() >= s[i] && a[ret.back() - 'a'] > 0)
                {
                    ret.pop_back();
                }
                ret += s[i];
            }
            a[s[i]-'a']--;
        }
        return ret;
    }
};
int main(){
    string s="edebbed";
    Solution ss;
    cout<<ss.removeDuplicateLetters(s); 
}
