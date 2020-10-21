/*
A string S of lowercase English letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

 

Example 1:

Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.

 

Note:

    S will have length in range [1, 500].
    S will consist of lowercase English letters ('a' to 'z') only.

*/
#include"common.h"
#include<cstring>
class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> res;
        if(S.size()==0)return res;
        array<array<int,2>,26> a{};
        memset(&a[0][0],-1,sizeof(a));
        for(int i=0;i<S.size();++i){
            int b=S[i]-'a';
            if(a[b][0]==-1)a[b][0]=i;
            else a[b][1]=i;
        }
        sort(a.begin(),a.end());
        int i=0;
        while(a[i][0]==-1)i++;
        int p0=a[i][0],p1=a[i][1];
        i++;
        for(;i<26;++i){
            if(a[i][0]>p1){
                if(p1!=-1)res.emplace_back(p1-p0+1);     
                else res.emplace_back(1);
                p0=a[i][0];
                p1=a[i][1];
            }else{
                p1=a[i][1]>p1?a[i][1]:p1;
            }
        }
        if (p1 != -1)
            res.emplace_back(p1 - p0 + 1);
        else
            res.emplace_back(1);
        return res;
    }
};

int main(){
    string str="bababcbacadefegdehijhklij";
    Solution s;
    s.partitionLabels(str);

}