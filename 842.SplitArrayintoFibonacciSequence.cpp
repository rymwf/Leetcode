/*
Given a string S of digits, such as S = "123456579", we can split it into a Fibonacci-like sequence [123, 456, 579].

Formally, a Fibonacci-like sequence is a list F of non-negative integers such that:

    0 <= F[i] <= 2^31 - 1, (that is, each integer fits a 32-bit signed integer type);
    F.length >= 3;
    and F[i] + F[i+1] = F[i+2] for all 0 <= i < F.length - 2.

Also, note that when splitting the string into pieces, each piece must not have extra leading zeroes, except if the piece is the number 0 itself.

Return any Fibonacci-like sequence split from S, or return [] if it cannot be done.

Example 1:

Input: "123456579"
Output: [123,456,579]

Example 2:

Input: "11235813"
Output: [1,1,2,3,5,8,13]

Example 3:

Input: "112358130"
Output: []
Explanation: The task is impossible.

Example 4:

Input: "0123"
Output: []
Explanation: Leading zeroes are not allowed, so "01", "2", "3" is not valid.

Example 5:

Input: "1101111"
Output: [110, 1, 111]
Explanation: The output [11, 0, 11, 11] would also be accepted.

Note:

    1 <= S.length <= 200
    S contains only digits.
*/
#include"common.h"
class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> ret;
        int len=S.size();

        static function<void(int, int, int)> f = [&](int a, int b, int p) {
            if(p>=len)return;
            long d = long(a) + b;
            if(d>INT_MAX){
                ret.clear();
                return;
            }
            int i=1;
            for(;i+p<=len;++i)
            {
                long c=atol(&S.substr(p,i)[0]);
                if(c>d){ret.clear();return;}
                else if(c==d){
                    ret.emplace_back(c);
                    f(b,c,i+p);
                    return;
                }
            }
            ret.clear();
        };

        //find first three number
        for(int i=1;i<=len;++i){
            if(S[0]=='0'&&i>1)break;
            long a=atol(&S.substr(0,i)[0]);
            if(a>INT_MAX||a<0)break;
            for(int j=1;i+j<=len;++j)
            {
                if(S[i]=='0'&&j>1)break;
                long b=atol(&S.substr(i,j)[0]);
                if(b>INT_MAX||b<0)break;
                long d = a + b;
                if(d>INT_MAX)break;
                for(int k=1;j+k<=len;++k)
                {
                    if(S[j]=='c'&&k>1)break;
                    long c = atol(&S.substr(i+j, k)[0]);
                    if(c>INT_MAX||c<0)break;
                    if(d==c){
                        ret.clear();
                        //check all string
                        ret.emplace_back(a);
                        ret.emplace_back(b);
                        ret.emplace_back(c);
                        f(b,c,i+j+k);
                        if(!ret.empty())return ret;
                        break;
                    }else if(d<c)break;
                }
            }
        }
        return ret;
    }
};

int main(){

//    string Input = "123456579";
    string Input = "214748364721474836422147483641";
//    string Input = "11235813";
//    string Input = "112358130";
//    string Input = "0123";
//    string Input = "1101111";

    Solution s;
    auto res = s.splitIntoFibonacci(Input);

    printf("\n");
    for(auto& i:res)
    {
        printf("%d ",i);
    }


}


