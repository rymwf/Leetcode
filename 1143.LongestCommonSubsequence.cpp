/*
Given two strings text1 and text2, return the length of their longest common subsequence.

A subsequence of a string is a new string generated from the original string with some characters(can be none) deleted without changing the relative order of the remaining characters. (eg, "ace" is a subsequence of "abcde" while "aec" is not). A common subsequence of two strings is a subsequence that is common to both strings.

 

If there is no common subsequence, return 0.

 

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.

Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.

Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.

 

Constraints:

    1 <= text1.length <= 1000
    1 <= text2.length <= 1000
    The input strings consist of lowercase English characters only.
 */
#include "common.h"

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int len1=text1.size();
        int len2=text2.size();

        #if 0
        vector<vector<int>> temp(len1+1,vector<int>(len2+1,0));
        #else
        int temp[len1+1][len2+1];
        for(int i=0;i<=len1;++i){
            temp[i][0]=0;
        };
        for(int i=0;i<=len2;++i){
            temp[0][i]=0;
        };
        #endif

        for(int i=1;i<=len1;++i){
            for(int j=1;j<=len2;++j){
                if(text1[i-1]==text2[j-1]){
                    temp[i][j]=temp[i-1][j-1]+1;
                }else
                    temp[i][j] = max(temp[i - 1][j], temp[i][j - 1]);
            }
        }
        for(int i=1,len1=text1.size();i<=len1;++i){
            printf("\n");
            printf("%c ", text1[i-1]);
            for(int j = 1, len2 = text2.size(); j <= len2; ++j)
            {
                printf("%d ", temp[i][j]);
            }
        }
        return temp[len1][len2];
    }
};

int main(){
//    string a="abcdefabcdef";
//    string b="eaecfg";
//string a="ghbrgc";
//string b="hafcdqbgncrcbihkd";
string a="mhunuzqrkzsnidwbun";
string b="szuluspmhwpazoxijwbq";

//string a="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
//;string b="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
//;

    Solution s;
    printf("\n");
    printf("%d ",s.longestCommonSubsequence(a,b));
    
}