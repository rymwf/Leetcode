/*
You are given an m x n binary grid, where each 1 represents a brick and 0 represents an empty space. A brick is stable if:

    It is directly connected to the top of the grid, or
    At least one other brick in its four adjacent cells is stable.

You are also given an array hits, which is a sequence of erasures we want to apply. Each time we want to erase the brick at the location hits[i] = (rowi, coli). The brick on that location (if it exists) will disappear. Some other bricks may no longer be stable because of that erasure and will fall. Once a brick falls, it is immediately erased from the grid (i.e., it does not land on other stable bricks).

Return an array result, where each result[i] is the number of bricks that will fall after the ith erasure is applied.

Note that an erasure may refer to a location with no brick, and if it does, no bricks drop.

 

Example 1:

Input: grid = [[1,0,0,0],[1,1,1,0]], hits = [[1,0]]
Output: [2]
Explanation: Starting with the grid:
[[1,0,0,0],
 [1,1,1,0]]
We erase the underlined brick at (1,0), resulting in the grid:
[[1,0,0,0],
 [0,1,1,0]]
The two underlined bricks are no longer stable as they are no longer connected to the top nor adjacent to another stable brick, so they will fall. The resulting grid is:
[[1,0,0,0],
 [0,0,0,0]]
Hence the result is [2].

Example 2:

Input: grid = [[1,0,0,0],[1,1,0,0]], hits = [[1,1],[1,0]]
Output: [0,0]
Explanation: Starting with the grid:
[[1,0,0,0],
 [1,1,0,0]]
We erase the underlined brick at (1,1), resulting in the grid:
[[1,0,0,0],
 [1,0,0,0]]
All remaining bricks are still stable, so no bricks fall. The grid remains the same:
[[1,0,0,0],
 [1,0,0,0]]
Next, we erase the underlined brick at (1,0), resulting in the grid:
[[1,0,0,0],
 [0,0,0,0]]
Once again, all remaining bricks are still stable, so no bricks fall.
Hence the result is [0,0].

 

Constraints:

    m == grid.length
    n == grid[i].length
    1 <= m, n <= 200
    grid[i][j] is 0 or 1.
    1 <= hits.length <= 4 * 104
    hits[i].length == 2
    0 <= xi <= m - 1
    0 <= yi <= n - 1
    All (xi, yi) are unique.
*/
#include "common.h"

//TODO: notdone
class Solution
{
public:
    vector<int> hitBricks(vector<vector<int>> &grid, vector<vector<int>> &hits)
    {
        int lenhit = hits.size();
        vector<int> ret(lenhit);
        int m = grid.size();
        if (m < 2)
            return ret;
        int n = grid[0].size();
        for (auto &v : hits)
        {
            grid[v[0]][v[1]] = 0;
        }
        struct UnionNode
        {
            int parent;
            int weight;
        };
        int len = m * n;
        vector<UnionNode> parents(len);
        for (int i = 0; i < len; ++i)
        {
            parents[i] = {i};
        }
        auto find = [&](int e) {
            int root = e;
            if (parents[e].weight == 0)
                parents[e].weight = 1;
            while (parents[root].parent != root)
                root = parents[root].parent;
            while (parents[e].parent != root)
            {
                int a = parents[e].parent;
                parents[e].parent = root;
                e = a;
            }
            return root;
        };
        auto unite = [&](int a, int b) {
            auto r1 = find(a);
            auto r2 = find(b);
            if (r1 == r2)
                return;
            parents[r2].parent = r1;
            parents[r1].weight += parents[r2].weight;
        };
        auto uniteroot=[&](int a,int b){
            parents[b].parent = a;
            parents[a].weight += parents[b].weight;
        };

        static function<void(int, int)> dfs = [&](int x, int y) {
            grid[x][y] = 0;

            if (x > 0 && grid[x - 1][y] == 1)
            {
                unite(x * n + y, (x - 1) * n + y);
                dfs(x - 1, y);
            }
            if (x + 1 < m && grid[x + 1][y] == 1)
            {
                unite(x * n + y, (x + 1) * n + y);
                dfs(x + 1, y);
            }
            if (y > 0 && grid[x][y - 1] == 1)
            {
                unite(x * n + y, x * n + y - 1);
                dfs(x, y - 1);
            }
            if (y + 1 < n && grid[x][y + 1] == 1)
            {
                unite(x * n + y, x * n + y + 1);
                dfs(x, y + 1);
            }
        };
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1)
                    dfs(i, j);
            }
        }
        for(int i=0;i<len;++i)
        {
            cout << i << ": " << parents[i].parent << " " << parents[i].weight << endl;
        }

        int root = -1;
        int k = 0;
        while (k < n && parents[k].weight == 0)
            k++;
        if (k < n)
        {
            root = k;
            for (k++; k < n; ++k)
            {
                if (parents[k].weight > 0)
                    uniteroot(root, k);
            }
        }

        dbg(root);
        for(int i=0;i<lenhit;++i)
        {

        }

        for(int i=lenhit-1;i>=0;--i)
        {
            int x=hits[i][0],y=hits[i][1];
            int r0 = find(x * n + y);
            int addweight = 0;
            bool flag=false;
            int a=(x-1)*n+y;
            if (x > 0 && parents[a].weight > 0)
            {
                int r1 = find(a);
                if (roots.find(r1) != roots.end())
                {
                    addweight -= parents[r1].weight;
                    flag = true;
                }
                uniteroot(r0, r1);
            }
            a=(x+1)*n+y;
            if (x + 1 < m && parents[a].weight > 0)
            {
                int r1 = find(a);
                if (roots.find(r1) != roots.end())
                    addweight -= parents[r1].weight;
                uniteroot(r0, r1);
            }
            a = x * n + y - 1;
            if (y > 0 && parents[a].weight > 0)
            {
                int r1 = find(a);
                if (roots.find(r1) != roots.end())
                    addweight -= parents[r1].weight;
                uniteroot(r0, r1);
            }
            a = x * n + y + 1;
            if (y + 1 < n && parents[a].weight > 0)
            {
                int r1 = find(a);
                if (roots.find(r1) != roots.end())
                    addweight -= parents[r1].weight;
                uniteroot(r0, r1);
            }
            addweight += parents[r0].weight;
            if (roots.find(parents[r0].parent) != roots.end())
                ret[i] = addweight;
        }
        return ret;
    }
};

int main()
{

    //vvi grid = {{1, 0, 1, 0}, {1, 1, 1, 0}, {0, 0, 1, 0}, {1, 0, 1, 1}}, hits = {{2, 2}};
    vvi grid = {{1, 0, 1, 0, 0}, {1, 1, 1, 0, 0}, {0, 0, 1, 0, 1}, {1, 0, 1, 1, 1}}, hits = {{2, 2}};
    for(auto& v:grid)
    {
        cout<<endl;
        for(auto i:v)
            cout<<i<<" ";
    }
    cout<<endl;

    Solution s;
    MEASURE_TIME_BEGIN
    auto res = s.hitBricks(grid, hits);
    MEASURE_TIME_END
    dbgvec(res);
}