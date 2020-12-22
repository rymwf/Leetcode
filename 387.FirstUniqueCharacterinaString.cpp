/*
Given a string, find the first non-repeating character in it and return its index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode"
return 2.

 

Note: You may assume the string contains only lowercase English letters.
*/
#include"common.h"

class Solution {
public:
    int firstUniqChar(string s) {
        int a[26]{};
        int i=0,len=s.size();
        for(;i<len;++i)
            a[s[i]-'a']++;
        for(i=0;i<len;++i)
            if(a[s[i]-'a']==1)return i;
        return -1;
    }
};

