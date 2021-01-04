/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

    You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
    After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)

Example:

Input: [1,2,3,0,2]
Output: 3 
Explanation: transactions = [buy, sell, cooldown, buy, sell]
*/
#include"common.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len < 2)
            return 0;
        vector<array<int, 2>> profit(len);
        profit[0][0] = 0;
        profit[0][1] = -prices[0];
        profit[1][0] = max(profit[0][0], profit[0][1] + prices[1]);
        profit[1][1] = max(profit[0][1], -prices[1]);
        for (int i = 1; i < len; ++i)
        {
            profit[i][0] = max(profit[i - 1][0], profit[i - 1][1] + prices[i]);
            profit[i][1] = max(profit[i - 1][1], profit[i - 2][0] - prices[i]);
        }
        return profit[len-1][0];
    }
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len < 2)
            return 0;
        int sold1, sold2, hold;
        sold2 = 0;
        hold = -prices[0];
        sold1 = max(sold2, hold + prices[1]);
        hold = max(sold2 - prices[1], hold);
        for (int i = 2; i < len; ++i)
        {
            int temp = sold2;
            sold2 = sold1;
            sold1 = max(sold1, hold + prices[i]);
            hold = max(hold, temp - prices[i]);
        }
        return sold1;
    }
};

