/*
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

    Each child must have at least one candy.
    Children with a higher rating get more candies than their neighbors.

What is the minimum candies you must give?

Example 1:

Input: [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.

Example 2:

Input: [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
             The third child gets 1 candy because it satisfies the above two conditions.
*/
#include"common.h"

class Solution {
public:
    int candy(vector<int>& ratings) {
        int len=ratings.size();
        int ret=1;
        int a=1;
        int status=0;
        int summit=1;
        for(int i=1;i<len;++i)
        {
            if (ratings[i] > ratings[i - 1])
            {
                if (status != 0)
                {
                    a = 1;
                    status=0;
                }
                a++;
                summit = a;
                ret += a;
            }
            else if (ratings[i] < ratings[i - 1])
            {
                if (status != 1)
                {
                    a = 0;
                    status=1;
                }
                a++;
                ret += a;
                if(a>=summit)ret++;
            }
            else
            {
                if (status != 2)
                {
                    a = 1;
                    summit = 1;
                    status=2;
                }
                ret += a;
            }
        }
        return ret;
    }
};

int main(){
    vector<int> a={1,2,2,3,4,6,2,1};
    Solution s;
    cout<<s.candy(a);
}

