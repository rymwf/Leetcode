/*
Given an array A of 0s and 1s, consider N_i: the i-th subarray from A[0] to A[i] interpreted as a binary number (from most-significant-bit to least-significant-bit.)

Return a list of booleans answer, where answer[i] is true if and only if N_i is divisible by 5.

Example 1:

Input: [0,1,1]
Output: [true,false,false]
Explanation: 
The input numbers in binary are 0, 01, 011; which are 0, 1, and 3 in base-10.  Only the first number is divisible by 5, so answer[0] is true.

Example 2:

Input: [1,1,1]
Output: [false,false,false]

Example 3:

Input: [0,1,1,1,1,1]
Output: [true,false,false,false,true,false]

Example 4:

Input: [1,1,1,0,1]
Output: [false,false,false,false,false]

 

Note:

    1 <= A.length <= 30000
    A[i] is 0 or 1
*/
#include"common.h"

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        int len = A.size();
        vector<bool> ret(len);
        int remainder = 0;
        for (int i = 0; i < len; ++i)
        {
            //            remainder <<= 1;
            //            remainder += A[i];
            //            remainder %= 5;
            remainder = ((remainder << 1) + A[i]) % 5;
            if (remainder == 0)
                ret[i] = true;
        }
        return ret;
    }
};