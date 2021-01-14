/*
In this problem, a rooted tree is a directed graph such that, there is exactly one node (the root) for which all other nodes are descendants of this node, plus every node has exactly one parent, except for the root node which has no parents.

The given input is a directed graph that started as a rooted tree with N nodes (with distinct values 1, 2, ..., N), with one additional directed edge added. The added edge has two different vertices chosen from 1 to N, and was not an edge that already existed.

The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [u, v] that represents a directed edge connecting nodes u and v, where u is a parent of child v.

Return an edge that can be removed so that the resulting graph is a rooted tree of N nodes. If there are multiple answers, return the answer that occurs last in the given 2D-array.

Example 1:
Input: [[1,2], [1,3], [2,3]]
Output: [2,3]
Explanation: The given directed graph will be like this:
  1
 / \
v   v
2-->3
Example 2:
Input: [[1,2], [2,3], [3,4], [4,1], [1,5]]
Output: [4,1]
Explanation: The given directed graph will be like this:
5 <- 1 -> 2
     ^    |
     |    v
     4 <- 3
Note:
The size of the input 2D-array will be between 3 and 1000.
Every integer represented in the 2D-array will be between 1 and N, where N is the size of the input array.
*/

#include "common.h"

class Solution
{
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges)
    {
        int len = edges.size();
        vector<int> parent(len + 1);
        auto findroot = [&](int e) {
            int root = e;
            while (parent[root] != 0)
                root = parent[root];
            while (parent[e] != 0 && parent[parent[e]] != root)
            {
                e = parent[e];
                parent[parent[e]] = root;
            }
            return root;
        };
        auto unite = [&](int a, int b) {
            parent[b] = a;
        };
        int vertexindegree2 = 0;
        int looproot = 0;
        vector<int> lastloopedge;
        vector<int> redEdge[2];
        for (auto &v : edges)
        {
            int a = findroot(v[0]);
            int b = findroot(v[1]);
            if (b != v[1])
            {
                //indegree 2
                if (a == b)
                {
                    //v[1] is not root,
                    return v;
                }
                else
                {
                    vertexindegree2 = v[1];
                    if (looproot == a)
                        return v;
                    redEdge[0] = vector<int>{parent[v[1]], v[1]};
                    redEdge[1] = v;
                }
            }
            else
            {
                if (a == b)
                {
                    //v[1] is root
                    //loop
                    looproot = a;
                    lastloopedge = v;
                }
                else
                {
                    //v[1] is free vertex
                    unite(v[0], v[1]);
                }
            }
            if (vertexindegree2 && looproot)
                break;
        }
        if (vertexindegree2)
        {
            if (findroot(redEdge[0][0]) == looproot)
                return redEdge[0];
            return redEdge[1];
        }
        else if (looproot)
        {
            return lastloopedge;
        }
        return vector<int>();
    }
};

int main()
{

//    vector<vector<int>> a = {
//        {1, 2},
//        {2, 3},
//        {3, 4},
//        {4, 1},
//        {5, 2},
//    };
    vvi a={{3,4},{4,1},{1,2},{2,3},{5,1}};
    Solution s;
    vector<int> res = s.findRedundantDirectedConnection(a);
    printf("%d %d", res[0], res[1]);
    return 0;
}