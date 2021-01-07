/*
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

 

Example 1:

Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2

Example 2:

Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3

 

Constraints:

    1 <= n <= 200
    n == isConnected.length
    n == isConnected[i].length
    isConnected[i][j] is 1 or 0.
    isConnected[i][i] == 1
    isConnected[i][j] == isConnected[j][i]

*/
#include "common.h"

//TODO: try union tree
class Solution
{
public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        vector<bool> checked(n, false);

        int ret = 0;
        for (int i = 0; i < n; ++i)
        {
            if (!checked[i])
            {
                ret++;
                queue<int> cities;
                cities.emplace(i);
                while (!cities.empty())
                {
                    int len = cities.size();
                    for (int j = 0; j < len; ++j)
                    {
                        int a = cities.front();
                        cities.pop();
                        for (int k = 0; k < n; ++k)
                        {
                            if (isConnected[a][k] && !checked[k])
                            {
                                checked[k] = true;
                                cities.emplace(k);
                            }
                        }
                    }
                }
            }
        }
        return ret;
    }
    int findCircleNum2(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        vector<bool> checked(n, false);

        int ret = 0;
        static function<void(int)> f = [&](int index) {
            checked[index] = true;
            for (int i = 0; i < n; ++i)
            {
                if (isConnected[index][i] && !checked[i])
                    f(i);
            }
        };
        for (int i = 0; i < n; ++i)
        {
            if (!checked[i])
            {
                ret++;
                f(i);
            }
        }
        return ret;
    }
    //array
    int findCircleNum3(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        vector<int> equivClass(n);
        for (int i = 0; i < n; ++i)
        {
            equivClass[i] = i;
        }
        auto unite = [&](int classa, int classb) {
            for (auto &e : equivClass)
            {
                if (e == classb)
                    e = classa;
            }
        };
        auto find = [&](int index) {
            return equivClass[index];
        };
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (isConnected[i][j])
                    unite(equivClass[i], equivClass[j]);
            }
        }
        unordered_set<int> temp;
        for (int i = 0; i < n; ++i)
        {
            temp.emplace(find(i));
        }
        return temp.size();
    }

    int findCircleNum4(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        //equivClassList eq(n);
        equivClassTree eq(n);
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (isConnected[i][j])
                    eq.uniteEle(i, j);
            }
        }
        return eq.getClassNum();
    }
};
int main()
{
    vector<vector<int>> b = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
    vector<vector<int>> a = {
        {1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0},
        {1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1},
        {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1}};
    Solution s;
    s.findCircleNum4(b);
}
