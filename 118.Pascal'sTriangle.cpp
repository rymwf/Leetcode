/*
Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/
#include"common.h"

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        if(numRows==0)return ret;
        ret.emplace_back(vector<int>{1});
        for(int i=1;i<numRows;++i){
            ret.emplace_back(vector<int>{1});
            for(int j=1;j<i;++j){
                ret.back().emplace_back(ret[i-1][j-1]+ret[i-1][j]);
            }
            ret.back().emplace_back(1);
        }
        return ret;
    }
};

