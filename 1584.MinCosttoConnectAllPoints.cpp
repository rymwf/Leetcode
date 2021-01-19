/*
You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.

 

Example 1:

Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
Output: 20
Explanation:

We can connect the points as shown above to get the minimum cost of 20.
Notice that there is a unique path between every pair of points.

Example 2:

Input: points = [[3,12],[-2,5],[-4,1]]
Output: 18

Example 3:

Input: points = [[0,0],[1,1],[1,0],[-1,1]]
Output: 4

Example 4:

Input: points = [[-1000000,-1000000],[1000000,1000000]]
Output: 4000000

Example 5:

Input: points = [[0,0]]
Output: 0

 

Constraints:

    1 <= points.length <= 1000
    -106 <= xi, yi <= 106
    All pairs (xi, yi) are distinct.
*/
#include "common.h"

class Solution
{
public:
    //kruskal
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        auto len = points.size();
        vector<tuple<int, int, int>> dists;
        dists.reserve(len * len / 2);
        for (size_t i = 0; i < len; ++i)
        {
            for (auto j = i + 1; j < len; ++j)
            {
                dists.emplace_back(abs(points[j][0] - points[i][0]) + abs(points[j][1] - points[i][1]), i, j);
            }
        }
        sort(dists.begin(), dists.end());
        auto count = points.size();
        vector<int> parents(count);
        for (size_t i = 1; i < count; i++)
        {
            parents[i] = i;
        }
        static function<int(int)> find = [&](int e) {
            if (parents[e] != e)
                parents[e] = find(parents[e]);
            return parents[e];
        };
        int ret = 0;
        size_t k = 1;
        for (auto &e : dists)
        {
            auto x = get<1>(e);
            auto y = get<2>(e);
            auto r1 = find(x);
            auto r2 = find(y);
            if (r1 != r2)
            {
                parents[r2] = r1;
                ret += get<0>(e);
                k++;
                if (k >= len)
                    break;
            }
        }
        return ret;
    }
    //prim
    int minCostConnectPoints2(vector<vector<int>> &points)
    {
        auto len = points.size();
        int ret = 0;
        vector<int> mindist(len, INT_MAX);
        int k = 0;
        for (size_t j = 1; j < len; j++)
        {
            int minindex = 0;
            for (size_t i = 1; i < len; i++)
            {
                if (mindist[i] == -1)
                    continue;
                mindist[i] = min(mindist[i], dist(points[i], points[k]));
                if (mindist[minindex] > mindist[i])
                {
                    minindex = i;
                }
            }
            ret += mindist[minindex];
            mindist[minindex] = -1;
            k = minindex;
        }
        return ret;
    }
    int dist(const vector<int> &a, const vector<int> &b)
    {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }
};

int main()
{

            vvi points = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
    //vvi points = {{2, -3}, {-17, -8}, {13, 8}, {-17, -15}};
//    vvi points ={{-1000000,-1000000},{1000000,1000000}}; 
    Solution s;
    auto res = s.minCostConnectPoints2(points);
    dbg(res);
}