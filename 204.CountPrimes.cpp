/*
Count the number of prime numbers less than a non-negative number, n.

 

Example 1:

Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

Example 2:

Input: n = 0
Output: 0

Example 3:

Input: n = 1
Output: 0

 

Constraints:

    0 <= n <= 5 * 106

*/
#include"common.h"

class Solution {
public:
    int countPrimes(int n) {
        if(n<=2)return 0;
        if(n<=3)return 1;
        int* res=new int[n>>1];
        res[0]=2;
        res[1]=3;
        int ret=2;
        int sqrtn=sqrt(n);
        for(int i=4;i<n;++i){
            int j=0;
            for(;j<ret&&res[j]<=sqrtn;++j){
                if(i%res[j]==0)break;
            }
            if(res[j]>sqrtn||j>=ret){
                res[ret]=i;
                ret++;
            }
        }
        delete[] res;
        return ret;
    }
};

int main(){
    int a;
    cout<<"typein number:";
    cin>>a;
    Solution s;
    cout<<s.countPrimes(a);
}