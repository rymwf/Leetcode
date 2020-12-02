/* 
Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.
Note:

    The length of num is less than 10002 and will be ≥ k.
    The given num does not contain any leading zero.

Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.

Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.

Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
*/
#include "common.h"

class Solution
{
public:
    //too slow
    string removeKdigits(string num, int k){
        if(num.size()<=k)return "0"; 
        string stk;
        stk.push_back(num[0]);
        for(int i=1,len=num.size();i<len&&k>=0;++i){
            while (k > 0 && !stk.empty() && stk.back() > num[i])
            {
                stk.pop_back();
                k--;
            }
            stk.push_back(num[i]);
        }
        int i=0,len=stk.size();
        for(;i<len;++i){
            if(stk[i]!='0')break;
        }
        if(i>=len)return "0";
        return stk.substr(i,len-i-k);
    }
};
int main()
{
//    string a = "5337";
    string a="112";
;    //string a = "102";
    //    string a = "612345;
    Solution s;
    printf("\n%s", s.removeKdigits(a,1).c_str());
}