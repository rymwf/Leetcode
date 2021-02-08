/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

 

Example 1:

Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above

Example 2:

Input: n = 1
Output: [["Q"]]

 

Constraints:

    1 <= n <= 9
*/
#include "common.h"

class Solution
{
public:
	vector<vector<string>> solveNQueens(int n)
	{
		vector<vector<string>> ret;
		vector<string> temp(n, string(n, '.'));
		vector<vector<int>> mytable(n, vector<int>(n));

		static function<void(int, int)> f = [&](int x, int y) {
			if (mytable[x][y])
				return;
			temp[x][y] = 'Q';
			if (x == n - 1)
			{
				ret.emplace_back(temp);
				temp[x][y] = '.';
				return;
			}
			//
			for (int i = 0; i < n; ++i)
				mytable[i][y]++;
			int a = x + y;
			int p = min(n - 1, a);
			int q = a - p;
			for (; p >= 0 && q < n; --p, ++q)
				mytable[p][q]++;
			for (p = x, q = y; q < n && p < n; ++p, ++q)
				mytable[p][q]++;
			for (p = x, q = y; q >= 0 && p >= 0; --p, --q)
				mytable[p][q]++;

			//
			for (int i = 0; i < n && x < n - 1; ++i)
				f(x + 1, i);
			temp[x][y] = '.';
			//
			for (int i = 0; i < n; ++i)
				mytable[i][y]--;
			a = x + y;
			p = min(n - 1, a);
			q = a - p;
			for (; p >= 0 && q < n; --p, ++q)
				mytable[p][q]--;
			for (p = x, q = y; q < n && p < n; ++p, ++q)
				mytable[p][q]--;
			for (p = x, q = y; q >= 0 && p >= 0; --p, --q)
				mytable[p][q]--;
		};
		for (int i = 0; i < n; ++i)
			f(0, i);
		return ret;
	}
	vector<vector<string>> solveNQueens2(int n)
	{
		vector<vector<string>> ret;
		vector<string> temp(n, string(n, '.'));
		vector<bool> col(n);
		vector<bool> dia0((n << 1) - 1);
		vector<bool> dia1((n << 1) - 1);

		static function<void(int, int)> f = [&](int x, int y) {
			if (col[y] || dia0[x + y] || dia1[n - 1 - x + y])
				return;
			temp[x][y] = 'Q';
			if (x == n - 1)
			{
				ret.emplace_back(temp);
				temp[x][y] = '.';
				return;
			}
			col[y] = true;
			dia0[x + y] = true;
			dia1[n - 1 - x + y] = true;
			for (int i = 0; i < n && x < n - 1; ++i)
				f(x + 1, i);
			temp[x][y] = '.';
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
	Solution s;
	auto res = s.solveNQueens2(4);
	for (auto v : res)
	{
		dbgvec(v);
	}
}