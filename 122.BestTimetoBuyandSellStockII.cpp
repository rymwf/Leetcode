/*
Say you have an array prices for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example 1:

Input: [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
             Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.

Example 2:

Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.

Example 3:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.

Constraints:

    1 <= prices.length <= 3 * 10 ^ 4
    0 <= prices[i] <= 10 ^ 4
*/
#include "common.h"

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int ret = 0;
        int i = 0;
        while (++i < prices.size())
        {
            while (i < prices.size() && prices[i] <= prices[i - 1])
                i++;
            if (i == prices.size())
                break;
            int pre = i - 1;
            while (i < prices.size() && prices[i] >= prices[i - 1])
                i++;
            ret += prices[i - 1] - prices[pre];
        }
        return ret;
    }
    int maxProfit2(vector<int> &prices)
    {
        int ret = 0;
        for (int i = 1; i < prices.size(); ++i)
        {
            ret += max(prices[i] - prices[i - 1], 0);
        }
        return ret;
    }
    //dynamic programming
    int maxProfit3(vector<int> &prices)
    {
        int len = prices.size();
        if (len < 2)
            return 0;
        
        //cash in hand
        vector<int> dp[2] = {vector<int>(len), vector<int>(len)};
        dp[0][0] = 0;
        dp[1][0] = -prices[0];
        for (int i = 1; i < len; ++i)
        {
            dp[0][i] = max(dp[0][i - 1], dp[1][i - 1] + prices[i]);
            dp[1][i] = max(dp[1][i - 1], dp[0][i - 1] - prices[i]);
        }
        return dp[0][len - 1];
    }
};
int main()
{
    vector<int> a = {1, 7, 1, 5, 3, 6, 4, 5};
    Solution s;
    auto res = s.maxProfit2(a);
    cout << res;
}
