/*
On an N x N grid, each square grid[i][j] represents the elevation at that point (i,j).

Now rain starts to fall. At time t, the depth of the water everywhere is t. You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. You can swim infinite distance in zero time. Of course, you must stay within the boundaries of the grid during your swim.

You start at the top left square (0, 0). What is the least time until you can reach the bottom right square (N-1, N-1)?

Example 1:

Input: [[0,2],[1,3]]
Output: 3
Explanation:
At time 0, you are in grid location (0, 0).
You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than t = 0.

You cannot reach point (1, 1) until time 3.
When the depth of water is 3, we can swim anywhere inside the grid.

Example 2:

Input: [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
Output: 16
Explanation:
 0  1  2  3  4
24 23 22 21  5
12 13 14 15 16
11 17 18 19 20
10  9  8  7  6

The final route is marked in bold.
We need to wait until time 16 so that (0, 0) and (4, 4) are connected.

Note:

    2 <= N <= 50.
    grid[i][j] is a permutation of [0, ..., N*N - 1].

*/
#include "common.h"
class Solution
{
public:
    int swimInWater(vector<vector<int>> &grid)
    {
        static constexpr array<array<int, 2>, 4> dirs{{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        queue<pair<int, int>> q;
        auto tupleCmp = [](const auto &lhs, const auto &rhs) {
            auto &&[a1, b1, c1] = lhs;
            auto &&[a2, b2, c2] = rhs;
            return c1 > c2;
        };

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(tupleCmp)> pq(tupleCmp);
        pq.emplace(0, 0, grid[0][0]);
        //while (!pq.empty())
        //for (int i = 0, l = m * n; i < l; ++i)
        for (;;)
        {
            dbg(pq.size());
            auto [nextx, nexty, t] = pq.top();
            pq.pop();
            dbg(t);
            if ((nextx == m - 1) && (nexty == n - 1))
                return t;
            q.emplace(nextx, nexty);
            visited[nextx][nexty] = true;
            while (!q.empty())
            {
                auto [x, y] = q.front();
                q.pop();
                for (auto [a, b] : dirs)
                {
                    int nx = x + a, ny = y + b;
                    if (nx >= 0 && ny >= 0 && nx < m && ny < n && !visited[nx][ny])
                    {
                        visited[nx][ny] = true;
                        if (grid[nx][ny] <= t)
                        {
                            if ((nx == m - 1) && (ny == n - 1))
                                return max(t, grid[nx][ny]);
                            q.emplace(nx, ny);
                        }
                        else
                        {
                            pq.emplace(nx, ny, grid[nx][ny]);
                        }
                    }
                }
            }
        }
        return 0;
    }
};
int main()
{
    //    vvi a = {{3, 2}, {0, 1}};
    //  vvi a = {{0, 1, 2, 3, 4}, {24, 23, 22, 21, 5}, {12, 13, 14, 15, 16}, {11, 17, 18, 19, 20}, {10, 9, 8, 7, 6}};
    //    vvi a = {
    //        {10, 12, 4, 6},
    //        {9, 11, 3, 5},
    //        {1, 7, 13, 8},
    //        {2, 0, 15, 14}};
    vvi a = {{26, 99, 80, 1, 89, 86, 54, 90, 47, 87}, {9, 59, 61, 49, 14, 55, 77, 3, 83, 79}, {42, 22, 15, 5, 95, 38, 74, 12, 92, 71}, {58, 40, 64, 62, 24, 85, 30, 6, 96, 52}, {10, 70, 57, 19, 44, 27, 98, 16, 25, 65}, {13, 0, 76, 32, 29, 45, 28, 69, 53, 41}, {18, 8, 21, 67, 46, 36, 56, 50, 51, 72}, {39, 78, 48, 63, 68, 91, 34, 4, 11, 31}, {97, 23, 60, 17, 66, 37, 43, 33, 84, 35}, {75, 88, 82, 20, 7, 73, 2, 94, 93, 81}};

    Solution s;
    auto res = s.swimInWater(a);
    dbg(res);
}
