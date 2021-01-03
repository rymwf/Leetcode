/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.

Example 1:

Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price.

Example 2:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.

*/
#include "common.h"

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int len = prices.size();
        if (len < 2)
            return 0;
        int ret = 0;
        int bottom = prices[0], top = prices[0];
        for (int i = 1; i < len; ++i)
        {
            if (prices[i] > top)
                top = prices[i];
            else if (prices[i] < bottom)
            {
                ret = max(ret, top - bottom);
                top = bottom = prices[i];
            }
        }
        ret = max(ret, top - bottom);
        return ret;
    }
    int maxProfit2(vector<int> &prices)
    {
        int minprice = INT_MAX;
        int ret = 0;
        for (auto c : prices)
        {
            if (c <= minprice)
                minprice = c;
            else
                ret = max(ret, c - minprice);
        }
        return ret;
    }
    int maxProfit3(vector<int> &prices)
    {
        int len=prices.size();
        if (len < 2)
            return 0;
        vector<int> temp[2] = {vector<int>(len), vector<int>(len)};
        temp[0][0] = 0;     //do not hold stock: 0: do nothing ,1: sell today 
        temp[1][0] = prices[0]; //hold stock: 0: buy tody, 1: do nothing
        for(int i=1;i<len;++i)
        {
            temp[0][i] = max(temp[0][i - 1], prices[i] - temp[1][i - 1]);
            temp[1][i] = min(temp[1][i - 1], prices[i]);
        //    cout<<temp[0][i]<<" "<<temp[1][i]<<endl;
        }
        return temp[0][len - 1];
    }

};
int main(){
    vector<int> Input = {7, 1, 8, 0, 6, 4};
    Solution s;
    s.maxProfit3(Input);
}
