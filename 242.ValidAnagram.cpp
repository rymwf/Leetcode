/*
Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true

Example 2:

Input: s = "rat", t = "car"
Output: false

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?

*/
#include "common.h"

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if(s.size()!=t.size())return false;
        unordered_map<char,int> map_s;
        unordered_map<char,int> map_t;
        for(auto& c:s)
            map_s[c]++;
        for(auto& c:t)
            map_t[c]++;
        if(map_s.size()!=map_t.size())return false;
        for (auto &ele : map_t)
            if(map_s.find(ele.first)==map_s.end()||map_s[ele.first]!=ele.second)return false;
        return true;
    }
    bool isAnagram2(string s, string t){
        if(s.size()!=t.size())return false;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        for(int i=t.size()-1;i>=0;--i)
            if(t[i]!=s[i])return false;
        return true;
    }
    bool isAnagram3(string s, string t){
        if(s.size()!=t.size())return false;
        int a[26]={0},b[26]={0}; 
        for(auto& c:s)
            a[c-'a']++;
        for(auto& c:t)
            b[c-'a']++;
        for(int i=0;i<26;++i)
            if(a[i]!=b[i])return false;
        return true;
    }


};

int main(){

    string a="ab";
    string b="ba";
    Solution s;
    printf("%d",s.isAnagram3(a,b));
}