/*
You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable.

You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.

Return the answers to all queries. If a single answer cannot be determined, return -1.0.

Note: The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.

 

Example 1:

Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
Explanation: 
Given: a / b = 2.0, b / c = 3.0
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
return: [6.0, 0.5, -1.0, 1.0, -1.0 ]

Example 2:

Input: equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
Output: [3.75000,0.40000,5.00000,0.20000]

Example 3:

Input: equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
Output: [0.50000,2.00000,-1.00000,-1.00000]

 

Constraints:

    1 <= equations.length <= 20
    equations[i].length == 2
    1 <= Ai.length, Bi.length <= 5
    values.length == equations.length
    0.0 < values[i] <= 20.0
    1 <= queries.length <= 20
    queries[i].length == 2
    1 <= Cj.length, Dj.length <= 5
    Ai, Bi, Cj, Dj consist of lower case English letters and digits.

*/
#include "common.h"

class Solution
{
public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        unordered_map<string, vector<int>> mymap;
        unordered_map<string, bool> varstatus; //0: unknown, 1: passed, 2:failed
        int len = equations.size();
        for (int i = 0; i < len; ++i)
        {
            mymap[equations[i][0]].emplace_back(i);
            mymap[equations[i][1]].emplace_back(i + len);
            varstatus[equations[i][0]] = false;
            varstatus[equations[i][1]] = false;
        }
#if 1
        for (auto it = mymap.begin(); it != mymap.end(); ++it)
        {
            cout << endl
                 << it->first << ": ";
            for (auto c : it->second)
            {
                cout << c << " ";
            }
        }
#endif

        static function<bool(int, const string &, vector<int> &)> helper = [&](int id, const string &targetstr, vector<int> &path) {
            path.emplace_back(id);
            string str = id < len ? equations[id][1] : equations[id - len][0];
            if (str == targetstr)
                return true;

            if (!varstatus[str])
            {
                varstatus[str] = true;
                for (auto e : mymap[str])
                {
                    if (helper(e, targetstr, path))
                        return true;
                }
            }
            path.pop_back();
            return false; //failed
        };

        vector<double> ret;
        vector<int> path;
        for (int i = 0, l = queries.size(); i < l; ++i)
        {
            string a = queries[i][0], b = queries[i][1];
            if (mymap.find(a) == mymap.end() || mymap.find(b) == mymap.end())
            {
                ret.emplace_back(-1);
                continue;
            }
            if (a == b)
            {
                ret.emplace_back(1);
                continue;
            }
            //reset
            path.clear();
            for (auto &it : varstatus)
                it.second = false;
            varstatus[a] = true;
            for (auto id : mymap[a])
            {
                if (helper(id, b, path))
                {
                    cout << endl
                         << "path:" << path[0] << " ";
                    //parse path
                    bool reverse = false;
                    double res = path[0] < len ? values[path[0]] : values[path[0] - len];
                    for (int j = 1, l = path.size(); j < l; ++j)
                    {
                        cout << path[j] << " ";
                        reverse = ((path[j] < len) ^ (path[j - 1] < len)) ^ reverse;
                        if (reverse)
                        {
                            res /= path[j] < len ? values[path[j]] : values[path[j] - len];
                        }
                        else
                        {
                            res *= path[j] < len ? values[path[j]] : values[path[j] - len];
                        }
                    }
                    ret.emplace_back(path[0] < len ? res : 1. / res);
                    //add new
                    //int tt = path.back();
                    //if (path.size() > 1)
                    //    mymap[a].emplace_back(tt < len ? tt + len : tt - len);
                    break;
                }
            }
            if (path.empty())
                //failed
                ret.emplace_back(-1);
        }
        return ret;
    }
};

int main()
{

    //vector<vector<string>> equations = {{"a", "b"}, {"b", "c"}}, queries = {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};
    //vector<double> values = {2.0, 3.0};
    //    Output: {6.00000,0.50000,-1.00000,1.00000,-1.00000}
    //    vector<vector<string>> equations = {{"a", "b"}, {"b", "c"}, {"bc", "cd"}}, queries = {{"a", "c"}, {"c", "c"}, {"bc", "cd"}, {"cd", "bc"}};
    //    vector<double> values = {1.5, 2.5, 5.0};
    //Output: [3.75000,0.40000,5.00000,0.20000]
    vector<vector<string>> equations = {{"x1", "x2"}, {"x2", "x3"}, {"x1", "x4"}, {"x2", "x5"}}, queries = {{"x2", "x4"}};
    vector<double> values = {3.0, 0.5, 3.4, 5.6};

    Solution s;
    auto res = s.calcEquation(equations, values, queries);
    cout << endl;
    for (auto e : res)
        cout << e << " ";
}