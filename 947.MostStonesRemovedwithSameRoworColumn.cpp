/*
On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.

A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.

Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest possible number of stones that can be removed.

 

Example 1:

Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
Output: 5
Explanation: One way to remove 5 stones is as follows:
1. Remove stone [2,2] because it shares the same row as [2,1].
2. Remove stone [2,1] because it shares the same column as [0,1].
3. Remove stone [1,2] because it shares the same row as [1,0].
4. Remove stone [1,0] because it shares the same column as [0,0].
5. Remove stone [0,1] because it shares the same row as [0,0].
Stone [0,0] cannot be removed since it does not share a row/column with another stone still on the plane.

Example 2:

Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
Output: 3
Explanation: One way to make 3 moves is as follows:
1. Remove stone [2,2] because it shares the same row as [2,0].
2. Remove stone [2,0] because it shares the same column as [0,0].
3. Remove stone [0,2] because it shares the same row as [0,0].
Stones [0,0] and [1,1] cannot be removed since they do not share a row/column with another stone still on the plane.

Example 3:

Input: stones = [[0,0]]
Output: 0
Explanation: [0,0] is the only stone on the plane, so you cannot remove it.

 

Constraints:

    1 <= stones.length <= 1000
    0 <= xi, yi <= 104
    No two stones are at the same coordinate point.
*/
#include "common.h"
class Solution
{
public:
    int removeStones(vector<vector<int>> &stones)
    {
        int n = stones.size();
        int ret = 0;
        vector<int> parent(n);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
        auto find = [&](int e) {
            int root = e;
            while (parent[root] != root)
                root = parent[root];
            while (parent[e] != 0)
            {
                int a = parent[e];
                parent[e] = root;
                e = a;
            }
            return root;
        };
        auto unite = [&](int a, int b) {
            int r1 = find(a);
            int r2 = find(b);
            if (r1 == r2)
                return;
            parent[r2] = r1;
            ret++;
        };

        unordered_map<int, int> rt;
        unordered_map<int, int> ct;

        for (int i = 0; i < n; ++i)
        {
            rt[stones[i][0]] = i;
            ct[stones[i][1]] = i;
        }
        for (int i = 0; i < n; ++i)
        {
            unite(rt[stones[i][0]], i);
            unite(ct[stones[i][1]], i);
        }
        return ret;
    }
    int removeStones2(vector<vector<int>> &stones)
    {
        unordered_map<int, int> parent;
        int count = 0;
        auto find = [&](int e) {
            int root = e;
            if (parent.find(e) == parent.end())
                count++;
            while (parent[root] != 0)
                root = parent[root];
            while (parent[e] != 0)
            {
                int a = parent[e];
                parent[e] = root;
                e = a;
            }
            return root;
        };
        auto unite = [&](int a, int b) {
            int r1 = find(a);
            int r2 = find(b);
            if (r1 == r2)
            {
                return;
            }
            count--;
            parent[r2] = r1;
        };
        for (auto &v : stones)
        {
            unite(v[0] | 0x80000, v[1] | 0x800000);
        }
        return stones.size() - count;
    }
};
int main()
{
    vvi stones = {{0, 0}, {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 2}};
    //   vvi stones ={{0,1},{1,2},{1,3},{3,3},{2,3},{0,2}};
    //vvi stones = {{2, 1}, {1, 1}};
    Solution s;
    auto res = s.removeStones2(stones);
    dbg(res);
}
