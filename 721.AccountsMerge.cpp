/*
Given a list accounts, each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some email that is common to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.

Example 1:

Input: 
accounts = [["John", "johnsmith@mail.com", "john00@mail.com"], ["John", "johnnybravo@mail.com"], ["John", "johnsmith@mail.com", "john_newyork@mail.com"], ["Mary", "mary@mail.com"]]
Output: [["John", 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],  ["John", "johnnybravo@mail.com"], ["Mary", "mary@mail.com"]]
Explanation: 
The first and third John's are the same person as they have the common email "johnsmith@mail.com".
The second John and Mary are different people as none of their email addresses are used by other accounts.
We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'], 
['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.

Note:
The length of accounts will be in the range [1, 1000].
The length of accounts[i] will be in the range [1, 10].
The length of accounts[i][j] will be in the range [1, 30].
*/
#include "common.h"
class Solution
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        unordered_map<string, pair<string, int>> parents;
        auto find = [&](string str, int index) {
            if (parents.find(str) == parents.end())
            {
                parents[str] = {str, index};
                return str;
            }
            string root = str;
            while (parents[root].first != root)
                root = parents[root].first;

            while (parents[str].first != root)
            {
                string a = str;
                parents[str].first = root;
                str = a;
            }
            return root;
        };
        auto unite = [&](const string &str1, const string &str2, int index) {
            auto r1 = find(str1, index);
            auto r2 = find(str2, index);
            if (r1 == r2)
                return;
            parents[r2] = {r1, index};
        };
        for (int j = 0, len = accounts.size(); j < len; ++j)
        {
            int l = accounts[j].size();
            if (l < 2)
                continue;
            find(accounts[j][1], j);
            for (int i = 2; i < l; ++i)
            {
                unite(accounts[j][i - 1], accounts[j][i], j);
            }
        }
        for (auto it : parents)
            cout << it.first << " " << it.second.first << " " << it.second.second << endl;

        unordered_map<int, vector<string>> indexmap;
        for (auto it = parents.begin(); it != parents.end(); ++it)
        {
            string r = find(it->first, 0);
            indexmap[parents[r].second].emplace_back(it->first);
        }
        vector<vector<string>> ret;
        ret.reserve(indexmap.size());
        for (auto it = indexmap.begin(); it != indexmap.end(); ++it)
        {
            sort(it->second.begin(), it->second.end());
            ret.emplace_back(vector<string>{accounts[it->first][0]});
            ret.back().insert(ret.back().end(), it->second.begin(), it->second.end());
        }
        return ret;
    }
    vector<vector<string>> accountsMerge2(vector<vector<string>> &accounts)
    {
        unordered_map<size_t, pair<size_t, int>> parents;

        auto find = [&](size_t e, int index) {
            if (parents.find(e) == parents.end())
            {
                parents[e] = {e, index};
                return e;
            }
            auto root = e;
            while (parents[root].first != root)
                root = parents[root].first;

            while (parents[e].first != root)
            {
                auto a = e;
                parents[e].first = root;
                e = a;
            }
            return root;
        };
        auto unite = [&](size_t a, size_t b, int index) {
            auto r1 = find(a, index);
            auto r2 = find(b, index);
            if (r1 == r2)
                return;
            parents[r2] = {r1, index};
        };
        for (int j = 0, len = accounts.size(); j < len; ++j)
        {
            int l = accounts[j].size();
            if (l < 2)
                continue;
            auto a = hash<string>{}(accounts[j][1]);
            find(a, j);
            for (int i = 2; i < l; ++i)
            {
                auto b = hash<string>{}(accounts[j][i]);
                unite(a, b, j);
                a = b;
            }
        }

        vector<vector<string>> ret;
        unordered_map<int, set<string>> indexmap;
        for (int i = 0, len = accounts.size(); i < len; ++i)
        {
            if (accounts[i].size() > 1)
            {
                auto rootindex = parents[find(hash<string>{}(accounts[i][1]), 0)].second;
                indexmap[rootindex].insert(accounts[i].begin() + 1, accounts[i].end());
            }
        }
        ret.reserve(indexmap.size());
        for (auto it = indexmap.begin(); it != indexmap.end(); ++it)
        {
            ret.emplace_back(vector<string>{accounts[it->first][0]});
            ret.back().insert(ret.back().end(), it->second.begin(), it->second.end());
        }
        return ret;
    }

    //best
    vector<vector<string>> accountsMerge3(vector<vector<string>> &accounts)
    {
        int len = accounts.size();
        vector<int> parents(len);
        for (int i = 1; i < len; ++i)
            parents[i] = i;
        //        auto find = [&](int i) {
        //            auto root = i;
        //            while (parents[root] != root)
        //                root=parents[root];
        //            while (parents[i] != root)
        //            {
        //                auto a = parents[i];
        //                parents[i] = root;
        //                i = a;
        //            }
        //            return root;
        //        };
        static function<int(int)> find = [&](int i) {
            if (parents[i] != i)
                parents[i] = find(parents[i]);
            return parents[i];
        };
        auto unite = [&](int a, int b) {
            int r1 = find(a);
            int r2 = find(b);
            if (r1 == r2)
                return;
            parents[r2] = r1;
        };

        unordered_map<string, int> indexmap;
        for (int i = 0; i < len; ++i)
        {
            int l = accounts[i].size();
            for (int j = 1; j < l; ++j)
            {
                if (indexmap.find(accounts[i][j]) != indexmap.end())
                {
                    unite(i, indexmap[accounts[i][j]]);
                }
                indexmap[accounts[i][j]] = i;
            }
        }
        unordered_map<int, vector<string>> tempmap;
        for (auto it = indexmap.begin(); it != indexmap.end(); ++it)
            tempmap[find(it->second)].emplace_back(it->first);
        vector<vector<string>> ret;
        ret.reserve(tempmap.size());
        for (auto it : tempmap)
        {
            sort(it.second.begin(), it.second.end());
            ret.emplace_back(vector<string>{accounts[it.first][0]});
            ret.back().insert(ret.back().end(), it.second.begin(), it.second.end());
        }
        return ret;
    }
};
int main()
{

    //    vvs accounts = {{"John", "johnsmith@mail.com", "john00@mail.com"}, {"John", "johnnybravo@mail.com"}, {"John", "johnsmith@mail.com", "john_newyork@mail.com"}, {"Mary", "mary@mail.com"}};
    vvs accounts = {{"David", "David0@m.co", "David1@m.co"}, {"David", "David3@m.co", "David4@m.co"}, {"David", "David4@m.co", "David5@m.co"}, {"David", "David2@m.co", "David3@m.co"}, {"David", "David1@m.co", "David2@m.co"}};
    Solution s;
    auto res = s.accountsMerge3(accounts);
    for (auto &v : res)
    {
        cout << endl;
        for (auto &e : v)
            cout << e << " ";
    }
}
