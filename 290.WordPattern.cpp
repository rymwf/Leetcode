/*
Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

 

Example 1:

Input: pattern = "abba", s = "dog cat cat dog"
Output: true

Example 2:

Input: pattern = "abba", s = "dog cat cat fish"
Output: false

Example 3:

Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false

Example 4:

Input: pattern = "abba", s = "dog dog dog dog"
Output: false

 

Constraints:

    1 <= pattern.length <= 300
    pattern contains only lower-case English letters.
    1 <= s.length <= 3000
    s contains only lower-case English letters and spaces ' '.
    s does not contain any leading or trailing spaces.
    All the words in s are separated by a single space.
*/
#include "common.h"

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        string mymap[26]{};
        unordered_map<string,int> mymap2;
        int len=pattern.size();
        int i=-1;
        auto token=strtok(&s[0]," ");
        while(token){
            ++i;
            if(i>=len)return false;
            int index=pattern[i]-'a';
            if(mymap2.find(token)!=mymap2.end())
            {
                if(mymap2[token]!=index)return false;
            }
            else mymap2[token]=index;

            if(mymap[index].empty())mymap[index]=token;
            else if(mymap[index]!=token)return false;

            token = strtok(NULL, " ");
        }
        if(i!=len-1)return false;
        return true;
    }
};
int main(){
string pattern = "abba", s = "dog cat cat dog";

Solution S;
cout<<S.wordPattern(pattern,s);

}