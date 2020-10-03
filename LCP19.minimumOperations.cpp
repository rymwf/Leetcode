/*
小扣出去秋游，途中收集了一些红叶和黄叶，他利用这些叶子初步整理了一份秋叶收藏集 leaves， 字符串 leaves 仅包含小写字符 r 和 y， 其中字符 r 表示一片红叶，字符 y 表示一片黄叶。
出于美观整齐的考虑，小扣想要将收藏集中树叶的排列调整成「红、黄、红」三部分。每部分树叶数量可以不相等，但均需大于等于 1。每次调整操作，小扣可以将一片红叶替换成黄叶或者将一片黄叶替换成红叶。请问小扣最少需要多少次调整操作才能将秋叶收藏集调整完毕。

示例 1：

    输入：leaves = "rrryyyrryyyrr"

    输出：2

    解释：调整两次，将中间的两片红叶替换成黄叶，得到 "rrryyyyyyyyrr"

示例 2：

    输入：leaves = "ryr"

    输出：0

    解释：已符合要求，不需要额外操作

提示：

    3 <= leaves.length <= 10^5
    leaves 中只包含字符 'r' 和字符 'y'
*/
#include "common.h"

class Solution
{
public:
    //TODO:dynamic programming
    int minimumOperations(string leaves)
    {
        int f[3] = {0};
        f[0] = leaves[0] == 'y';
        f[1] = f[2] = INT_MAX / 2;
        for (int i = 1; i < leaves.size(); ++i)
        {
            f[2] = min(f[1], f[2]) + int(leaves[i] == 'y');
            f[1] = min(f[0], f[1]) + int(leaves[i] == 'r');
            f[0] = f[0] + int(leaves[i] == 'y');
        }
        return f[2];
    }
    //this is exchange the position of leaves
    int minimumOperations2(string leaves)
    {
        int l = 0, r = leaves.size() - 1;
        int county[3] = {0}, countr[3] = {0};

        while (l <= r && leaves[l] == 'r')
        {
            l++;
            countr[0]++;
        }
        while (l <= r && leaves[l] == 'y')
        {
            l++;
            county[0]++;
        }
        while (r >= l && leaves[r] == 'r')
        {
            r--;
            countr[2]++;
        }

        while (r >= l && leaves[r] == 'y')
        {
            r--;
            county[2]++;
        }

        while (l <= r)
        {
            if (leaves[l] == 'r')
                countr[1]++;
            else if (leaves[l] == 'y')
                county[1]++;
            l++;
        }
        int a = county[0] + county[1];
        int b = county[1] + county[2];
        int c = county[0] + county[2];
        int d = countr[1];
        int res = min(min(min(a, b), c), d);

        if (countr[1] == 0)
        {
            if ((countr[0] & countr[2]) == 0)
                return 1;
            else
                return 0;
        }
        else if (countr[0] == 0)
        {
            return (res == b && res != d) ? res + 1 : res;
        }
        else if (countr[2] == 0)
        {
            return (res == a && res != d) ? res + 1 : res;
        }
        return res;
    }
};

int main()
{
    //result        0,      2,      2,  1,      1      1   1       2       2      3
    string leavas[] = {"ryr", "yrr", "rry", "yyrr", "rryy", "ryry", "yryr", "yyryr", "yyrryr", "yyrryy"}; //2
    for (auto &i : leavas[0])
    {
        auto a = i == 'y';
        printf("%x\n", a);
    }

    Solution s;
    for (string &l : leavas)
    {
        printf("==%s: ", l.c_str());
        int res = s.minimumOperations(l);
        printf("%d\n", res);
    }
    return 0;
}
