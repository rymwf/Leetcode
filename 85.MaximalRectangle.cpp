/*

Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

 

Example 1:

Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.

Example 2:

Input: matrix = []
Output: 0

Example 3:

Input: matrix = [["0"]]
Output: 0

Example 4:

Input: matrix = [["1"]]
Output: 1

Example 5:

Input: matrix = [["0","0"]]
Output: 0

 

Constraints:

    rows == matrix.length
    cols == matrix.length
    0 <= row, cols <= 200
    matrix[i][j] is '0' or '1'.
*/
#include"common.h"
class Solution {
public:



    int maximalRectangle(vector<vector<char>>& matrix) {
        int row=matrix.size();
        if(row<=0)return 0;
        int col=matrix[0].size();
        int ret=0;
        int temp=0;
        for (int i = 0; i < col; ++i)
        {
            if(matrix[0][i]=='0'){
                temp=0;
                matrix[0][i]=0;
            }
            else{
                matrix[0][i]=1;
                temp++;
                ret = max(ret, temp);
            } 
        }
        for(int j=1;j<row;++j)
        {
            for(int i=0;i<col;++i)
            {
                matrix[j][i]=matrix[j][i]=='0'?0:1;
                if(matrix[j-1][i]!=0&&matrix[j][i]!=0){
                    matrix[j][i]+=matrix[j-1][i];
                }
            }

            stack<int> stk;
            stk.emplace(-1);
            for (int k = 0; k < col; ++k)
            {
                while (stk.top() != -1 && matrix[j][stk.top()] >= matrix[j][k])
                {
                    int a = stk.top();
                    stk.pop();
                    ret = max(ret, (k - stk.top() - 1) * matrix[j][a]);
                }
                stk.emplace(k);
            }
            while (stk.top() != -1)
            {
                int a = stk.top();
                stk.pop();
                ret = max(ret, (col - stk.top() - 1) * matrix[j][a]);
            }
        }
        return ret;
    }
};

int main()
{
    vector<vector<char>> a = {{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
    //vector<vector<char>> a = {{'0','1'},{'1','0'}};
   // vector<vector<char>> a ={{'1','1','0','1'},{'1','1','0','1'},{'1','1','1','1'}}; 
    //vector<vector<char>> a ={{'0','1','1','0','1'},{'1','1','0','1','0'},{'0','1','1','1','0'},{'1','1','1','1','0'},{'1','1','1','1','1'},{'0','0','0','0','0'}};
    Solution s;
    s.maximalRectangle(a);
}
