/*
The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.

Given n, calculate F(n).

 

Example 1:

Input: n = 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.

Example 2:

Input: n = 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.

Example 3:

Input: n = 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.

 

Constraints:

    0 <= n <= 30
*/
#include"common.h"

class Solution {
public:
    int fib(int n) {
        if (n == 0)
            return 0;
        int a = 0, b = 1;
        int temp;
//        for (int i = 1; i < n; ++i)
        while (n-- > 1)
        {
            temp = a + b;
            a = b;
            b = temp;
        }
        return b;
    }

   //column major
    template <class T>
    class matrix2x2
    {
        T _v[4]{1, 0, 0, 1};

    public:
        matrix2x2() = default;
        matrix2x2(T a, T b, T c, T d)
        {
            _v[0] = a;
            _v[1] = b;
            _v[2] = c;
            _v[3] = d;
        }
        matrix2x2 operator*(const matrix2x2& other){
            matrix2x2 res;
            res._v[0] = _v[0] * other._v[0] + _v[2] * other._v[1];
            res._v[1] = _v[1] * other._v[0] + _v[3] * other._v[1];
            res._v[2] = _v[0] * other._v[2] + _v[2] * other._v[3];
            res._v[3] = _v[1] * other._v[2] + _v[3] * other._v[3];
            return res;
        }
        matrix2x2 &operator*=(const matrix2x2 &other)
        {
            *this=(*this)*other;
            return *this;
        }
        T *operator[](size_t i)
        {
            return &_v[0] + i * 2;
        }
    };

    /**
    *  matrix power, coloum
    *   [f(n) f(n-1)]=[1 1;1 0][f(n-1) f(n-2)]; 
    *   [f(n) f(n-1)]=[1 1;1 0]^(n-1)[f(1) f(0)]
    */
    int fib2(int n) {
        if(n==0)return 0;
        else if(n==1)return 1;
        n--;
        vector<int> temp;
        int i = 0;
        while (n > 0)
        {
            if (n & 1)
                temp.emplace_back(i);
            n >>= 1;
            i++;
        }
        int k=temp.back();
        vector<matrix2x2<int>> matrixpower(k+1);
        matrixpower[0]={1,1,1,0};
        for(int i=1;i<=k;++i)
        {
            matrixpower[i]=matrixpower[i-1]*matrixpower[i-1];
        }
        matrix2x2<int> target = matrixpower[temp[0]];
        for(int i=1,l=temp.size();i<l;++i)
            target *= matrixpower[temp[i]];
        return target[0][0];
    }
    //same as fib2
    int fib3(int n) {
        if(n==0)return 0;
        else if(n==1)return 1;
        matrix2x2<int> target;
        matrix2x2<int> temp = {1, 1, 1, 0};
        n--;
        while (n > 0)
        {
            if (n & 1)
            {
                target = temp * target;
            }
            n >>= 1;
            temp *= temp;
        }
        return target[0][0];
    }
    int fib4(int n)
    {
        if(n>30) return 0; 
        int a[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040};
        return a[n];
    }
    /*
    other: the closed form of fibonacci numbers
    f(n)=(((1+sqrt(5))/2)^n-((1-sqrt(5))/2)^n)/sqrt(5)
    */
};
int main()
{
    Solution s;
    for(int i=0;i<=40;i++)
    {
        cout << s.fib3(i) << ",";
    }
}