/*
You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

 

Example 1:

Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
Output: 16
Explanation: The perimeter is the 16 yellow stripes in the image above.

Example 2:

Input: grid = [[1]]
Output: 4

Example 3:

Input: grid = [[1,0]]
Output: 4

 

Constraints:

    row == grid.length
    col == grid[i].length
    1 <= row, col <= 100
    grid[i][j] is 0 or 1.

*/
#include "common.h"
class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int res = 0;
        int h = grid.size();
        int w = grid[0].size();
        static function<void(int, int)> f = [&](int i, int j) {
            if (i < 0 || i >= h || j < 0 || j >= w || grid[i][j] == 0)
            {
                res++;
                return;
            }
            if (grid[i][j] == 1)
            {
                grid[i][j] = 2;
                f(i + 1, j);
                f(i - 1, j);
                f(i, j - 1);
                f(i, j + 1);
            }
        };
        for (int i = 0; i < h; ++i)
        {
            for (int j = 0; j < w; ++j)
            {
                if (grid[i][j] == 1)
                {
                    f(i, j);
                    break;
                }
            }
        }
        return res;
    }

    int islandPerimeter2(vector<vector<int>> &grid){
        int res=0;
        int h = grid.size();
        int w = grid[0].size();
        for (int i = 0; i < h; ++i)
        {
            for (int j = 0; j < w; ++j)
            {
                if (grid[i][j] == 1)
                {
                    if (i + 1 >= h || grid[i + 1][j] == 0)
                        res++;
                    if (i - 1 < 0 || grid[i - 1][j] == 0)
                        res++;
                    if (j + 1 >= w || grid[i][j + 1] == 0)
                        res++;
                    if (j - 1 < 0 || grid[i][j - 1] == 0)
                        res++;
                }
            }
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> a = {{0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}};
    Solution s;
    std::cout << s.islandPerimeter2(a) << "\n";
}
