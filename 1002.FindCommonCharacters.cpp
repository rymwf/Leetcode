/*
Given an array A of strings made only from lowercase letters, return a list of all characters that show up in all strings within the list (including duplicates).  For example, if a character occurs 3 times in all strings but not 4 times, you need to include that character three times in the final answer.

You may return the answer in any order.

 

Example 1:

Input: ["bella","label","roller"]
Output: ["e","l","l"]

Example 2:

Input: ["cool","lock","cook"]
Output: ["c","o"]

 

Note:

    1 <= A.length <= 100
    1 <= A[i].length <= 100
    A[i][j] is a lowercase letter

*/
#include"common.h"

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<string> res;
        if(A.size()==0)return res;
        unordered_map<char,std::pair<int,int>> map0;
        for(int i=0;i<A[0].size();++i){
            map0[A[0][i]].second++;
        }
        for(int i=1;i<A.size();++i){
            for (auto &&c : A[i])
            {
                if(map0.find(c)!=map0.end()){
                    map0[c].first++;
                }
            }
            for(auto it=map0.begin();it!=map0.end();){
                it->second.second=min(it->second.first,it->second.second);
                if (it->second.second == 0)
                {
                    char a = it->first;
                    it++;
                    map0.erase(a);
                    continue;
                }
                it->second.first=0;
                it++;
            }
        }

        for (auto it = map0.begin(); it != map0.end();it++)
            res.emplace_back(it->second.second,it->first);
        return res;
   }
};

int main(){
    vector<string> A{"bellaa","label","roller"};

    Solution s;
    s.commonChars(A);
}