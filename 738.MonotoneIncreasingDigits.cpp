/*
Given a non-negative integer N, find the largest number that is less than or equal to N with monotone increasing digits.

(Recall that an integer has monotone increasing digits if and only if each pair of adjacent digits x and y satisfy x <= y.)

Example 1:

Input: N = 10
Output: 9

Example 2:

Input: N = 1234
Output: 1234

Example 3:

Input: N = 332
Output: 299

Note: N is an integer in the range [0, 10^9]. 
*/
#include"common.h"
#include<string>

class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string a=to_string(N);
        int len=a.size();
        int i=0;
        while(++i<len&&a[i]>=a[i-1]);
        while(--i>0&&a[i]==a[i-1]);
        if(i<len-1)a[i]-=1;
        while(++i<len)a[i]='9';
        return atoi(&a[0]);
    }

};

int main(){
    int a;
    cout<<"input:";
    cin>>a;
    Solution s;
    cout<<s.monotoneIncreasingDigits2(a);

}