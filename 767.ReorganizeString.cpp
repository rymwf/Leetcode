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
        vector<vector<int>> temp(26,vector<int>(2,0));;
        for(auto& c:S)
        {
            temp[c-'a'][1]++;
        }
        for(int i=0;i<26;++i){
            temp[i][0]=i+'a';
        }
        sort(temp.begin(),temp.end(),[](vector<int>&a, vector<int>&b){
            return a[1]>b[1];
        });
        int columnum=temp[0][1];
        int len=S.size();
        if(columnum<<1>len)return "";
        string str;
        for(auto& ele:temp){
            str.insert(str.end(),ele[1],ele[0]);
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
        return ret;
    }
};

int main(){
    string a;
    cin>>a;
    Solution s;
    cout<<s.reorganizeString(a); 

}
