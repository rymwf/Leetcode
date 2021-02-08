/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

Given an integer n, return the number of distinct solutions to the n-queens puzzle.

Example:

Input: 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown below.
[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/

//TODO: not done
#include "common.h"

class Solution
{
public:
	int totalNQueens(int n)
	{
		int ret = 0;
		vector<bool> col(n);
		vector<bool> dia0((n << 1) - 1);
		vector<bool> dia1((n << 1) - 1);

		static function<void(int, int)> f = [&](int x, int y) {
			if (col[y] || dia0[x + y] || dia1[n - 1 - x + y])
				return;
			if (x == n - 1)
			{
				ret++;
				return;
			}
			col[y] = true;
			dia0[x + y] = true;
			dia1[n - 1 - x + y] = true;
			for (int i = 0; i < n && x < n - 1; ++i)
				f(x + 1, i);
			col[y] = false;
			dia0[x + y] = false;
			dia1[n - 1 - x + y] = false;
		};
		for (int i = 0; i < n; ++i)
			f(0, i);
		return ret;
	}
};
int main()
{
}
