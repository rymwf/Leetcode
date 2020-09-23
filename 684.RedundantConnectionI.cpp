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
//TODO: ���鼯
#include "common.h"
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        stack<int> stk;
        unordered_set<int> myset;
        while (myset.size()!=edges.size()*2)
        {
            
        for (int i = 0; i < edges.size(); ++i) {
            if (myset.find(i) != myset.end())continue;
            
            if (myset.find(edges[i][0]) != myset.end() &&
                myset.find(edges[i][1]) != myset.end())
                stk.emplace(i);
            else
            {
                myset.emplace(edges[i][0]);
                myset.emplace(edges[i][1]);
            }
        
        }
        }
        if (stk.empty())return vector<int>();
        return edges[stk.top()];
    }
};

int main() {
    int a[][2]=   {{2, 1}, {3, 4}, {4, 2}, {1, 4}};
    vector<vector<int>>  b;
    int sizex = sizeof(a) / sizeof(a[0]);
    int sizey = 2;
    b.resize(sizex);
    vector<int> temp;
    for (int i = 0; i < sizex; ++i) {
        temp.clear();
        for (int j = 0; j < sizey; ++j) {
            temp.emplace_back(a[i][j]);
        }
        b[i] = temp;
    }

    Solution s;
    vector<int>res=s.findRedundantConnection(b);
    printf("%d %d",res[0],res[1]);
    return 0;
}


