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
            temp=0;
            for(int m=0;m<col;++m)
            {
                int min0=matrix[j][m];
                ret=max(ret,min0);
                if(m>0&&matrix[j][m]<=matrix[j][m-1])continue;;
                for(int n=m+1;n<col&&matrix[j][n]!=0;++n)
                {
                    if(matrix[j][n]<=min0){
                       min0=matrix[j][n]; 
                    }
                    ret = max(ret, min0 * (n - m + 1));
                }
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
