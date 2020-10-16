/*
Given an array of integers A sorted in non-decreasing order, return an array of the squares of each number, also in sorted non-decreasing order.

 

Example 1:

Input: [-4,-1,0,3,10]
Output: [0,1,9,16,100]

Example 2:

Input: [-7,-3,2,3,11]
Output: [4,9,9,49,121]

 

Note:

    1 <= A.length <= 10000
    -10000 <= A[i] <= 10000
    A is sorted in non-decreasing order.
*/

#include "common.h"
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &A)
    {
        for (auto &i : A)
        {
            i *= i;
        }
        sort(A.begin(), A.end());
    }
    vector<int> sortedSquares(vector<int> &A)
    {
        int i = 0;
        for (; i < A.size() - 1; ++i)
        {
            if (abs(A[i + 1]) > abs(A[i]))
                break;
        }
        int l = i - 1, r = i + 1;
        vector<int> res;
        while (l >= 0 && r < A.size())
        {
            if (abs(A[l]) > abs(A[r]))
            {
                res.emplace_back(A[l] * A[l]);
                l--;
            }
            else
            {
                res.emplace_back(A[r] * A[r]);
                r++;
            }
        }
        if (l <= 0)
        {
            for (int i = r; i < A.size(); ++i)
                res.emplace_back(A[i] * A[i]);
        }
        if (r >= A.size())
        {
            for (int i = 0; i <= l; ++i)
                res.emplace_back(A[i] * A[i]);
        }
        return res;
    }

    vector<int> sortedSquares(vector<int> &A)
    {
        vector<int> res(A.size());
        int l = 0, r = A.size() - 1, i = r;
        while (l <= r)
        {
            if (abs(A[l]) > abs(A[r]))
            {
                res[i] = A[l] * A[l];
                l++;
            }
            else
            {
                res[i] = A[r] * A[r];
                r--;
            t}
            i--;
        }
        return res;
    }
};
