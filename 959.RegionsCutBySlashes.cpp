/*
In a N x N grid composed of 1 x 1 squares, each 1 x 1 square consists of a /, \, or blank space.  These characters divide the square into contiguous regions.

(Note that backslash characters are escaped, so a \ is represented as "\\".)

Return the number of regions.

 

Example 1:

Input:
[
  " /",
  "/ "
]
Output: 2
Explanation: The 2x2 grid is as follows:

Example 2:

Input:
[
  " /",
  "  "
]
Output: 1
Explanation: The 2x2 grid is as follows:

Example 3:

Input:
[
  "\\/",
  "/\\"
]
Output: 4
Explanation: (Recall that because \ characters are escaped, "\\/" refers to \/, and "/\\" refers to /\.)
The 2x2 grid is as follows:

Example 4:

Input:
[
  "/\\",
  "\\/"
]
Output: 5
Explanation: (Recall that because \ characters are escaped, "/\\" refers to /\, and "\\/" refers to \/.)
The 2x2 grid is as follows:

Example 5:

Input:
[
  "//",
  "/ "
]
Output: 3
Explanation: The 2x2 grid is as follows:

 

Note:

    1 <= grid.length == grid[0].length <= 30
    grid[i][j] is either '/', '\', or ' '.
*/
#include "common.h"

class Solution
{
public:
    int regionsBySlashes(vector<string> &grid)
    {
        int m = grid.size();
        grid.emplace_back(string(m, ' ')); //slow
        int count = (m + 1) * (m + 1);
        std::vector<int> parents(count);
        std::iota(parents.begin(), parents.end(), 0);
        static function<int(int)> find = [&](int e) {
            if (parents[e] != e)
                parents[e] = find(parents[e]);
            return parents[e];
        };
        auto unite = [&](int a, int b) {
            a = find(a);
            b = find(b);
            if (a != b)
            {
                parents[b] = a;
                count--;
            }
        };
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                int a = i * (m + 1) + j;
                if (grid[i][j] == ' ')
                    unite(a, a + 1);
                int a2 = a + (grid[i][j] == '/');
                int b = a + (m + 1) + (grid[i + 1][j] == '\\');
                unite(a2, b);
            }
        }
        return count - 1;
    }
    int regionsBySlashes2(vector<string> &grid)
    {
        int m = grid.size();
        int count = m * (m + 1);
        std::vector<int> parents(count);
        std::iota(parents.begin(), parents.end(), 0);
        static function<int(int)> find = [&](int e) {
            if (parents[e] != e)
                parents[e] = find(parents[e]);
            return parents[e];
        };
        auto unite = [&](int a, int b) {
            a = find(a);
            b = find(b);
            if (a != b)
            {
                parents[b] = a;
                count--;
            }
        };
        for (int j = 0; j < m; ++j)
        {
            if (grid[0][j] == ' ')
                unite(j, j + 1);
        }
        for (int i = 1; i < m; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                int a = i * (m + 1) + j;
                if (grid[i][j] == ' ')
                    unite(a, a + 1);
                int a2 = a + (grid[i][j] == '\\');
                int b = a - (m + 1) + (grid[i - 1][j] == '/');
                unite(a2, b);
            }
        }
        return count;
    }
    //connect vertices
    int regionsBySlashes3(vector<string> &grid)
    {
        int m = grid.size();
        int n = m + 1;
        int count = n * n;
        std::vector<int> parents(count);
        for (int i = n - 1, r = count - n; i < r; ++i)
        {
            if ((i + 1) % n == 0)
            {
                i++;
            }
            else
                parents[i] = i;
        }
        static function<int(int)> find = [&](int e) {
            if (parents[e] != e)
                parents[e] = find(parents[e]);
            return parents[e];
        };
        auto unite = [&](int a, int b) {
            a = find(a);
            b = find(b);
            if (a != b)
            {
                parents[b] = a;
                return false;
            }
            return true;
        };
        int ret = 1;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                int a, b;
                if (grid[i][j] == '/')
                {
                    a = i * n + j + 1;
                    b = a + m;
                }
                else if (grid[i][j] == '\\')
                {
                    a = i * n + j;
                    b = a + n + 1;
                }
                else
                    continue;
                if (unite(a, b))
                    ret++;
            }
        }
        return ret;
    }
};
int main()
{
    //   vs grid = {
    //       "\\/",
    //       "/\\"};

    vs grid = {
        " /",
        "/ "};
    Solution s;
    auto res = s.regionsBySlashes3(grid);
    dbg(res);
}
