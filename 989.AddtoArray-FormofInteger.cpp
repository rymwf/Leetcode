/*
For a non-negative integer X, the array-form of X is an array of its digits in left to right order.  For example, if X = 1231, then the array form is [1,2,3,1].

Given the array-form A of a non-negative integer X, return the array-form of the integer X+K.

 

Example 1:

Input: A = [1,2,0,0], K = 34
Output: [1,2,3,4]
Explanation: 1200 + 34 = 1234

Example 2:

Input: A = [2,7,4], K = 181
Output: [4,5,5]
Explanation: 274 + 181 = 455

Example 3:

Input: A = [2,1,5], K = 806
Output: [1,0,2,1]
Explanation: 215 + 806 = 1021

Example 4:

Input: A = [9,9,9,9,9,9,9,9,9,9], K = 1
Output: [1,0,0,0,0,0,0,0,0,0,0]
Explanation: 9999999999 + 1 = 10000000000

 

Note：

    1 <= A.length <= 10000
    0 <= A[i] <= 9
    0 <= K <= 10000
    If A.length > 1, then A[0] != 0
*/
#include"common.h"

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        auto len=A.size();
        vector<int> ret;
        ret.reserve(len+1);
        int incr = 0;
        vector<int> stk;
        int i = len - 1;
        for (; K > 0 || incr > 0; --i, K /= 10)
        {
            int a = K % 10 + incr;
            if (i >= 0)
                a += A[i];
            if (a >= 10)
            {
                incr = 1;
                a -= 10;
            }
            else
                incr = 0;
            stk.emplace_back(a);
        }
        ret.insert(ret.end(), A.begin(), A.begin() + max(i + 1, 0));
        ret.insert(ret.end(), stk.rbegin(), stk.rend());
        return ret;
    }
    vector<int> addToArrayForm2(vector<int> &A, int K)
    {
        reverse(A.begin(),A.end());
        int incr = 0;
        for (int i = 0,l = A.size(); i < l; ++i, K /= 10)
        {
            A[i] += K % 10 + incr;
            incr = A[i] >= 10;
            A[i] %= 10;
        }
        K += incr;
        while(K>0)
        {
            A.emplace_back(K % 10);
            K /= 10;
        }
        reverse(A.begin(),A.end());
        return A;
    }
    vector<int> addToArrayForm3(vector<int> &A, int K)
    {
        vector<int> ret;
        for (int i = A.size() - 1; i >= 0 || K > 0; --i, K /= 10)
        {
            if (i >= 0)
                K += A[i];
            ret.emplace_back(K % 10);
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};
int main(){
    vi A={9,9,9};
    int k=100;
    Solution s;
    auto res=s.addToArrayForm(A,k);
    dbgvec(res);
}




