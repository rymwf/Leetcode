/*
Given an integer array arr. You have to sort the integers in the array in ascending order by the number of 1's in their binary representation and in case of two or more integers have the same number of 1's you have to sort them in ascending order.

Return the sorted array.

 

Example 1:

Input: arr = [0,1,2,3,4,5,6,7,8]
Output: [0,1,2,4,8,3,5,6,7]
Explantion: [0] is the only integer with 0 bits.
[1,2,4,8] all have 1 bit.
[3,5,6] have 2 bits.
[7] has 3 bits.
The sorted array by bits is [0,1,2,4,8,3,5,6,7]

Example 2:

Input: arr = [1024,512,256,128,64,32,16,8,4,2,1]
Output: [1,2,4,8,16,32,64,128,256,512,1024]
Explantion: All integers have 1 bit in the binary representation, you should just sort them in ascending order.

Example 3:

Input: arr = [10000,10000]
Output: [10000,10000]

Example 4:

Input: arr = [2,3,5,7,11,13,17,19]
Output: [2,3,5,17,7,11,13,19]

Example 5:

Input: arr = [10,100,1000,10000]
Output: [10,100,10000,1000]

 

Constraints:

    1 <= arr.length <= 500
    0 <= arr[i] <= 10^4
*/
#include "common.h"
class Solution
{
public:
    vector<int> sortByBits(vector<int> &arr)
    {
        vector<vector<int>> temp(31, vector<int>());
        for (auto &a : arr)
        {
            int bitnum = 0;
            for (int i = 0; i < 31; ++i)
            {
                if ((a >> i) & 1 == 1)
                    bitnum++;
            }
            temp[bitnum].emplace_back(a);
        }
        vector<int> ret;
        ret.reserve(arr.size());
        for (auto &i : temp)
        {
            std::sort(i.begin(), i.end());
            for (auto &j : i)
                ret.emplace_back(j);
        }
        return ret;
    }
    vector<int> sortByBits2(vector<int> &arr)
    {
        auto bitcount = [](int a) {
            int bitnum = 0;
            for (int i = 0; i < 31; ++i)
            {
                if ((a >> i) & 1 == 1)
                    bitnum++;
            }
            return bitnum;
        };
        sort(arr.begin(), arr.end(), [&](int x, int y) {
#ifdef __GNUC__
            //only available in GCC
            int m = __builtin_popcount(x), n = __builtin_popcount(y);
#else
            int m=bitcount(x),n=bitcount(y);
#endif
            return m == n ? x < y : m < n;
        });

        return arr;
    }
};
int main()
{
    //    vector<int> a={0,1,2,3,4,5,6,7,8};
    vector<int> a = {1024, 512, 256, 2, 3, 4, 5, 6, 128, 64, 32, 16, 8, 4, 2, 1};
    //    vector<int> a={10000,10000};
    //    vector<int> a={2,3,5,7,11,13,17,19};
    //    vector<int> a={10,100,1000,10000};

    Solution s;
    auto res = s.sortByBits2(a);
    for (auto &i : res)
    {
        std::cout << i << " ";
    }
}
