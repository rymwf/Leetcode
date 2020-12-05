/*
Given a string S, check if the letters can be rearranged so that two characters that are adjacent to each other are not the same.

If possible, output any possible result.  If not possible, return the empty string.

Example 1:

Input: S = "aab"
Output: "aba"

Example 2:

Input: S = "aaab"
Output: ""

Note:

    S will consist of lowercase letters and have length in range [1, 500].

*/
#include"common.h"

class Solution {
public:
    string reorganizeString(string S) {
        int temp[26];
        memset(temp,0,104);
        for(auto& c:S)
        {
            temp[c-'a']++;
        }
        int columnum=0,index=0;
        for(int i=0;i<26;++i){
            if(temp[i]>columnum){
                columnum=temp[i];
                index=i;
            }
        }
        int len=S.size();
        if((columnum<<1)-1>len)return "";
        swap(temp[0],temp[index]);
        string str;
        for(int i=0;i<26;++i){
            str.insert(str.end(),temp[i],i+'a');
        }
        string ret;
        int rownum=len/columnum+1;
        for(int i=0;i<columnum;++i){
            for(int j=0;j<rownum;++j){
                int index=j*columnum+i;
                if(index>=len)continue;
                ret+=str[index];
            }
        }
        char tempc=index+'a';
        for(auto& c:ret){
            if(c=='a')c=tempc;
            else if(c==tempc)c='a';
        }
        return ret;
    }
};

int main(){
    string a;
    cin>>a;
    Solution s;
    cout<<s.reorganizeString(a); 

}
