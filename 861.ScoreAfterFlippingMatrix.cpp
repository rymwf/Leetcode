/*
We have a two dimensional matrix A where each value is 0 or 1.

A move consists of choosing any row or column, and toggling each value in that row or column: changing all 0s to 1s, and all 1s to 0s.

After making any number of moves, every row of this matrix is interpreted as a binary number, and the score of the matrix is the sum of these numbers.

Return the highest possible score.

 

Example 1:

Input: [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
Output: 39
Explanation:
Toggled to [[1,1,1,1],[1,0,0,1],[1,1,1,1]].
0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39

 

Note:

    1 <= A.length <= 20
    1 <= A[0].length <= 20
    A[i][j] is 0 or 1.
*/
#include "common.h"

class Solution
{
public:
    int matrixScore(vector<vector<int>> &A)
    {
        int m = A.size();
        int n = A[0].size();
        vector<int> temp2=vector<int>(n,0);
        for (int i = 0; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                if (A[i][j])
                    temp2[j]++;
                if (A[i][0])
                {
                    A[i][j] = !A[i][j];
                    if (A[i][j])
                        temp2[j]++;
                    else
                        temp2[j]--;
                }
            }
        }

        int halfm = m / 2;
        for (int j = 1; j < n; ++j)
        {
            if (temp2[j] <= halfm)
            {
                for (int i = 0; i < m; ++i)
                {
                    A[i][j] = !A[i][j];
                }
            }
        }
        vector<int> res1(m, 0);

        for (int i = 0; i < m; ++i)
        {
            res1[i] |= (1 << (n - 1));
        }
        for (int i = 0; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                if (A[i][j])
                    res1[i] |= (A[i][j] << (n - j - 1));
            }
        }
        int ret = 0;
        for (int i = 0; i < m; ++i)
        {
            ret += res1[i];
        }
        return ret;
    }
};

int main()
{

    vector<vector<int>> a = {{0, 0, 1, 1}, {1, 0, 1, 0}, {1, 1, 0, 0}};
    Solution s;
    auto res = s.matrixScore(a);
    printf("\nres:%d", res);
}