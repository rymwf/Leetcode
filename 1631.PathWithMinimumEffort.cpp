/*
You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

 

Example 1:

Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 2
Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.

Example 2:

Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
Output: 1
Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].

Example 3:

Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
Output: 0
Explanation: This route does not require any effort.

 

Constraints:

    rows == heights.length
    columns == heights[i].length
    1 <= rows, columns <= 100
    1 <= heights[i][j] <= 106
*/
#include "common.h"

class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<array<int, 3>>> pre(m, vector<array<int, 3>>(n, {-1, -1, INT_MAX}));
        pre[0][0] = {0, 0, 0};
        queue<pair<int, int>> q;
        q.emplace(0, 0);
        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();
            if (x > 0)
            {
                int a = max(abs(heights[x - 1][y] - heights[x][y]), pre[x][y][2]);
                if (pre[x - 1][y][2] > a)
                {
                    pre[x - 1][y] = {x, y, a};
                    q.emplace(x - 1, y);
                }
            }
            if (x < m - 1)
            {
                int a = max(abs(heights[x + 1][y] - heights[x][y]), pre[x][y][2]);
                if (pre[x + 1][y][2] > a)
                {
                    pre[x + 1][y] = {x, y, a};
                    q.emplace(x + 1, y);
                }
            }
            if (y > 0)
            {
                int a = max(abs(heights[x][y - 1] - heights[x][y]), pre[x][y][2]);
                if (pre[x][y - 1][2] > a)
                {
                    pre[x][y - 1] = {x, y, a};
                    q.emplace(x, y - 1);
                }
            }
            if (y < n - 1)
            {
                int a = max(abs(heights[x][y + 1] - heights[x][y]), pre[x][y][2]);
                if (pre[x][y + 1][2] > a)
                {
                    pre[x][y + 1] = {x, y, a};
                    q.emplace(x, y + 1);
                }
            }
        }
        return pre[m - 1][n - 1][2];
    }
    int minimumEffortPath2(vector<vector<int>> &heights)
    {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> pre(m, vector<int>(n, INT_MAX));
        pre[0][0] = 0;
        queue<pair<int, int>> q;
        q.emplace(0, 0);
        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();
            if (x > 0)
            {
                int a = max(abs(heights[x - 1][y] - heights[x][y]), pre[x][y]);
                if (pre[x - 1][y] > a)
                {
                    pre[x - 1][y] = a;
                    q.emplace(x - 1, y);
                }
            }
            if (x < m - 1)
            {
                int a = max(abs(heights[x + 1][y] - heights[x][y]), pre[x][y]);
                if (pre[x + 1][y] > a)
                {
                    pre[x + 1][y] = a;
                    q.emplace(x + 1, y);
                }
            }
            if (y > 0)
            {
                int a = max(abs(heights[x][y - 1] - heights[x][y]), pre[x][y]);
                if (pre[x][y - 1] > a)
                {
                    pre[x][y - 1] = a;
                    q.emplace(x, y - 1);
                }
            }
            if (y < n - 1)
            {
                int a = max(abs(heights[x][y + 1] - heights[x][y]), pre[x][y]);
                if (pre[x][y + 1] > a)
                {
                    pre[x][y + 1] = a;
                    q.emplace(x, y + 1);
                }
            }
        }
        return pre[m - 1][n - 1];
    }
    int minimumEffortPath3(vector<vector<int>> &heights)
    {
        array<pair<int, int>, 4> dirs = {{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> pre(m, vector<int>(n, INT_MAX));
        vector<vector<bool>> visited(m, vector<bool>(n));
        pre[0][0] = 0;
        queue<pair<int, int>> q;
        q.emplace(0, 0);
        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();
            if (visited[x][y])
                continue;
            visited[x][y] = true;
            for (auto [a, b] : dirs)
            {
                int nx = x + a, ny = y + b;
                if (nx >= 0 && ny >= 0 && nx < m && ny < n)
                {
                    int c = max(abs(heights[nx][ny] - heights[x][y]), pre[x][y]);
                    if (c < pre[nx][ny])
                    {
                        pre[nx][ny] = c;
                        q.emplace(nx, ny);
                    }
                }
            }
        }
        return pre[m - 1][n - 1];
    }
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int m = heights.size();
        int n = heights[0].size();
        
        auto tupleCmp = [](const auto& e1, const auto& e2) {
            auto&& [x1, y1, d1] = e1;
            auto&& [x2, y2, d2] = e2;
            return d1 > d2;
        };
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(tupleCmp)> q(tupleCmp);
        q.emplace(0, 0, 0);

        vector<int> dist(m * n, INT_MAX);
        dist[0] = 0;
        vector<int> seen(m * n);

        while (!q.empty()) {
            auto [x, y, d] = q.top();
            q.pop();
            int id = x * n + y;
            if (seen[id]) {
                continue;
            }
            if (x == m - 1 && y == n - 1) {
                break;
            }
            seen[id] = 1;
            for (int i = 0; i < 4; ++i) {
                int nx = x + dirs[i][0];
                int ny = y + dirs[i][1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && max(d, abs(heights[x][y] - heights[nx][ny])) < dist[nx * n + ny]) {
                    dist[nx * n + ny] = max(d, abs(heights[x][y] - heights[nx][ny]));
                    q.emplace(nx, ny, dist[nx * n + ny]);
                }
            }
        }
        
        return dist[m * n - 1];
    }
};
int main()
{
    vvi heights = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};
    Solution s;
    auto res = s.minimumEffortPath(heights);
    dbg(res);
}