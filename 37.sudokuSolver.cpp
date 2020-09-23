#include "common.h"

//TODO::�������ܶ��Ż�����������˳����Ż�������״̬���Ż��ȵ�

class Solution {

	bool func(vector<vector<char>>& board, int x, int y) {
		if (x == 9 || y == 9)return true;
		if (board[x][y] != '.') {
			return func(board, x + (y + 1) / 9, y + 1 - (y + 1) / 9 * 9);
		}
		for (char i = '1'; i <= '9'; ++i) {
			bool flag = true;
			//check row 
			for (int j = 0; flag && j < 9; ++j) {
				if (board[x][j] == i)flag = false;
			}
			//check column
			for (int j = 0; flag && j < 9; ++j) {
				if (board[j][y] == i)flag = false;
			}
			//check block
			{
				int a = x / 3 * 3;
				int b = y / 3 * 3;
				for (int j = a; flag && j < a + 3; ++j) {
					for (int k = b; flag && k < b + 3; ++k) {
						if (!(a == x && b == y) && board[j][k] == i)flag = false;
					}
				}

			}
			if (!flag)continue;
			//put i in board
			board[x][y] = i;
			if (func(board, x + (y + 1) / 9, y + 1 - (y + 1) / 9 * 9))return true;
			board[x][y] = '.';
			continue;
		}
		return false;
	}

public:
	void solveSudoku(vector<vector<char>>& board) {

		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				func(board, i, j);
			}
		}
	}
};



int main() {

	Solution s;

	char a[9][9] = {
	{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
	{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
	{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
	{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
	{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
	{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
	{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
	{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
	{'.', '.', '.', '.', '8', '.', '.', '7', '9'}
	};

	vector<vector<char>> b;
	b.reserve(9);
	vector<char> temp;
	temp.resize(9);
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			temp[j] = a[i][j];
		}
		b.emplace_back(temp);
	}
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			printf("%c ", b[i][j]);
		}
		printf("\n");
	}
	printf("======\n");
	s.solveSudoku(b);
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			printf("%c ", b[i][j]);
		}
		printf("\n");
	}
	return 0;
}