#include "common.h"

vector<vector<int>> res;
vector<int> temp;
bool func(vector<int> &candidates, int startIndex, int target)
{
    static int num = 0;
    num++;
    printf("===%d=== \n", num);
    printf("target %d \n", target);
    if (target == 0)
    {
        res.emplace_back(temp);
        return true;
    }
    else if (target < 0)
        return true;

    for (int i = startIndex; i < candidates.size(); ++i)
    {
        printf("%d %d \n", startIndex, i);
        if (i > startIndex && candidates[i] == candidates[i - 1])
            continue;
        temp.emplace_back(candidates[i]);
        if (func(candidates, i + 1, target - candidates[i]))
        {
            temp.pop_back();
            return false;
        };
        temp.pop_back();
    }
    return false;
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    func(candidates, 0, target);
    return res;
}

void main()
{
    vector<int> a{4, 4, 2, 1, 4, 2, 2, 1, 3};
    //    vector<int> a{1, 1, 2, 1, 2, 3};
    int b = 6;
    vector<vector<int>> r = combinationSum2(a, b);
    for (int i = 0; i < r.size(); ++i)
    {
        for (int j = 0; j < r[i].size(); ++j)
        {
            printf("%d ", r[i][j]);
        }
        printf("\n");
    }
}