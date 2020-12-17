/*
You are given two strings s and t.

String t is generated by random shuffling string s and then add one more letter at a random position.

Return the letter that was added to t.

 

Example 1:

Input: s = "abcd", t = "abcde"
Output: "e"
Explanation: 'e' is the letter that was added.

Example 2:

Input: s = "", t = "y"
Output: "y"

Example 3:

Input: s = "a", t = "aa"
Output: "a"

Example 4:

Input: s = "ae", t = "aea"
Output: "a"

 

Constraints:

    0 <= s.length <= 1000
    t.length == s.length + 1
    s and t consist of lower-case English letters.
*/
#include"common.h"
class Solution {
public:
    char findTheDifference(string s, string t) {
        int a[26]{};
        for(auto c:s)
            a[c-'a']++;
        for(auto c:t)
        {
            if(a[c-'a']==0)return c;
            a[c-'a']--;
        }
        return 0;
    }
    char findTheDifference2(string s, string t) {
        char a=0;
        int len=s.size();
        for (int i = 0; i < len; ++i)
        {
            a ^= s[i];
            a ^= t[i];
        }
        return a^t[len];
    }
};


