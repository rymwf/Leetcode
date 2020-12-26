/*
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

Example 1:

Input: s = "egg", t = "add"
Output: true

Example 2:

Input: s = "foo", t = "bar"
Output: false

Example 3:

Input: s = "paper", t = "title"
Output: true

Note:
You may assume both s and t have the same length.
*/
#include"common.h"
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int len = s.size();
        if(len!=t.size())return false;
        int f[255];
        memset(f,0xff,sizeof f);
        bool a[255]{};
        for(int i=0;i<len;++i)
        {
            if(f[t[i]]==-1&&!a[s[i]]){
                f[t[i]]=s[i];
                a[s[i]]=true;
            }
            if(f[t[i]]!=s[i])return false;
        }
        return true;
    }
};

int main(){
}