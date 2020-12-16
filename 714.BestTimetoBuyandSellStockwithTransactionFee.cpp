/*
Your are given an array of integers prices, for which the i-th element is the price of a given stock on day i; and a non-negative integer fee representing a transaction fee.

You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction. You may not buy more than 1 share of a stock at a time (ie. you must sell the stock share before you buy again.)

Return the maximum profit you can make.

Example 1:

Input: prices = [1, 3, 2, 8, 4, 9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
Buying at prices[0] = 1
Selling at prices[3] = 8
Buying at prices[4] = 4
Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.

Note:
0 < prices.length <= 50000.
0 < prices[i] < 50000.
0 <= fee < 50000.
*/
#include"common.h"

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int l1=0,r1=0;
        int l2=0,r2=0;
        int ret=0;
        int len=prices.size();
        int i = 0;
        while(i<len)
        {
            while(++i<len&&prices[i]<prices[i-1]);
            l2=i-1;
            while(i<len&&prices[i]>=prices[i-1])i++;
            r2=i-1;
            if(prices[r1]-prices[l2]>fee){
                ret+=max(prices[r1]-prices[l1]-fee,0);
                l1=l2;
                r1=r2;
            }else{
                if(prices[r1]<=prices[r2]){
                    r1=r2;
                }
                if (prices[l1] > prices[l2])
                {
                    l1 = l2;
                    r1 = r2;
                }
            }
        }
        ret += max(prices[r2] - prices[l2] - fee, 0);
        return ret;
    }
};

int main()
{

//    vector<int> prices = {1, 3, 2, 8, 4, 9};
//vector<int> prices = {2, 1, 4, 4, 2, 3, 2, 5, 1, 2};
vector<int> prices = {2272,3910,1745,4132,102,4027,9,2166,929,408,3537,4606};
int fee = 4490;
Solution s;
cout << s.maxProfit(prices, fee);
}