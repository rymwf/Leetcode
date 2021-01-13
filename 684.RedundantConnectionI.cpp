/*
In this problem, a tree is an undirected graph that is connected and has no cycles.

The given input is a graph that started as a tree with N nodes (with distinct values 1, 2, ..., N), with one additional edge added. The added edge has two different vertices chosen from 1 to N, and was not an edge that already existed.

The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [u, v] with u < v, that represents an undirected edge connecting nodes u and v.

Return an edge that can be removed so that the resulting graph is a tree of N nodes. If there are multiple answers, return the answer that occurs last in the given 2D-array. The answer edge [u, v] should be in the same format, with u < v.

Example 1:
Input: [[1,2], [1,3], [2,3]]
Output: [2,3]
Explanation: The given undirected graph will be like this:
  1
 / \
2 - 3
Example 2:
Input: [[1,2], [2,3], [3,4], [1,4], [1,5]]
Output: [1,4]
Explanation: The given undirected graph will be like this:
5 - 1 - 2
    |   |
    4 - 3
Note:
The size of the input 2D-array will be between 3 and 1000.
Every integer represented in the 2D-array will be between 1 and N, where N is the size of the input array.

Update (2017-09-26):
We have overhauled the problem description + test cases and specified clearly the graph is an undirected graph. For the directed graph follow up please see Redundant Connection II). We apologize for any inconvenience caused.

*/
//TODO:
#include "common.h"
class Solution
{
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int maxvertex = 0;
        for (auto &v : edges)
            for (auto e : v)
                maxvertex = max(maxvertex, e);
        vector<vector<int>> graph(maxvertex + 1);
        for (auto &v : edges)
        {
            graph[v[0]].emplace_back(v[1]);
            graph[v[1]].emplace_back(v[0]);
        }
#ifdef MYLOCAL
        for (int i = 1; i <= maxvertex; ++i)
        {
            cout << endl
                 << i << ":";
            for (auto e : graph[i])
                cout << e << " ";
        }
#endif
        unordered_set<int> tempset;
        vector<int> visited(maxvertex + 1);
        int foundvertex = -1;

        bool flag = true;
        bool isinclude = false;
        static function<void(int, int)> f = [&](int v0, int v1) {
            if (visited[v1] && flag)
            {
                foundvertex = v1;
                flag = false;
                isinclude = true;
            }
            visited[v1] = true;
            for (auto e : graph[v1])
            {
                if (e != v0 && flag)
                    f(v1, e);
            }
            if (isinclude)
            {
                tempset.emplace(v1);
                isinclude = v0 != foundvertex;
            }
        };
        f(0, 1);
//        dbgvec(tempset);
        for (int i = edges.size() - 1; i >= 0; --i)
        {
            if (tempset.find(edges[i][0]) != tempset.end() &&
                tempset.find(edges[i][1]) != tempset.end())
                return edges[i];
        }
        vector<int> ret(2);
        return ret;
    }
};

int main()
{
    //    vvi a = {{1,2}, {2,3}, {3,4}, {1,4}, {1,5}};
    //vvi a ={{1,4},{3,4},{1,3},{1,2},{4,5}};
    vvi a{{16, 25}, {7, 9}, {3, 24}, {10, 20}, {15, 24}, {2, 8}, {19, 21}, {2, 15}, {13, 20}, {5, 21}, {7, 11}, {6, 23}, {7, 16}, {1, 8}, {17, 20}, {4, 19}, {11, 22}, {5, 11}, {1, 16}, {14, 20}, {1, 4}, {22, 23}, {12, 20}, {15, 18}, {12, 16}};
    Solution s;
    vector<int> res = s.findRedundantConnection(a);

    printf("\n%d %d", res[0], res[1]);
    return 0;
}
