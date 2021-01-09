/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.

Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.

Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.

Example 4:

Input: prices = [1]
Output: 0

 

Constraints:

    1 <= prices.length <= 105
    0 <= prices[i] <= 105

*/
#include "common.h"

class Solution
{
public:
    int maxprofitonce(vector<int> &prices, int begin, int end)
    {
        int ret = 0;
        int bottom = prices[begin], top = prices[begin];
        for (int i = begin; i < end; ++i)
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

    //exceed time limit
    int maxProfit(vector<int> &prices)
    {
        int len = prices.size();
        //find all buy point
        vector<int> buypoints;
        int i = 0;
        while (i < len)
        {
            while (++i < len && prices[i] <= prices[i - 1])
                ;
            if (i != len)
                buypoints.emplace_back(i - 1);
            while (++i < len && prices[i] >= prices[i - 1])
                ;
        }
        int ret = 0;
        int l = buypoints.size();
        if (l == 1)
            ret = maxprofitonce(prices, 0, len);
        for (i = 1; i < l; i++)
        {
            ret = max(ret, maxprofitonce(prices, buypoints[0], buypoints[i]) + maxprofitonce(prices, buypoints[i], len - 1));
        }
        return ret;
    }
    int maxProfit2(vector<int> &prices)
    {
        int len=prices.size();
        if (len < 2)
            return 0;
        int k=2;
        int l = 2 * k + 1;
        vector<vector<int>> dp(len, vector<int>(l));
        dp[0][0] = 0;
        for (int i = 1; i < l;)
        {
            dp[0][i++] = -prices[0];
            dp[0][i++] = 0;
        }
        for (int i = 1; i < len; ++i)
        {
            dp[i][0] = dp[i-1][0];
            for (int j = 1; j < l; j++)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] - prices[i]);
                cout<<dp[i][j]<<" ";
                j++;
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + prices[i]);
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return dp[len - 1][l - 1];
    }
    int maxProfit3(vector<int> &prices)
    {
        int len = prices.size();
        if (len < 2)
            return 0;
#if 0
        constexpr int k = 2;
        vector<array<int, 2 * k>> profit(len);
        profit[0][0] = 0;
        profit[0][1] = -prices[0];
        profit[0][2] = 0;
        profit[0][3] = -prices[0];
        profit[0][4] = 0;
        for (int i = 1; i < len; ++i)
        {
            profit[i][0] = 0;
            profit[i][1] = max(profit[i - 1][1], -prices[i]);
            profit[i][2] = max(profit[i - 1][2], profit[i - 1][1] + prices[i]);
            profit[i][3] = max(profit[i - 1][3], profit[i - 1][2] - prices[i]);
            profit[i][4] = max(profit[i - 1][4], profit[i - 1][3] + prices[i]);
        }
        return profit[len - 1][4];
#else
        int profit[4]{-prices[0], 0, -prices[0], 0};
        for (int i = 1; i < len; ++i)
        {
            profit[3] = max(profit[3], profit[2] + prices[i]);
            profit[2] = max(profit[2], profit[1] - prices[i]);
            profit[1] = max(profit[1], profit[0] + prices[i]);
            profit[0] = max(profit[0], -prices[i]);
        }
        return profit[3];
#endif
    }
    int maxProfit4(vector<int> &prices)
    {
        int profit[4]{INT_MIN, 0, INT_MIN, 0};
        for (auto e : prices)
        {
            profit[3] = max(profit[3], profit[2] + e);
            profit[2] = max(profit[2], profit[1] - e);
            profit[1] = max(profit[1], profit[0] + e);
            profit[0] = max(profit[0], -e);
        }
        return profit[3];
    }
    int maxProfit5(vector<int> &prices)
    {
        constexpr int k = 2;
        int buy[k + 1];
        for (int i = 0; i <= k; ++i)
            buy[i] = INT_MIN;
        int sell[k + 1]{};
        for (auto e : prices)
        {
            for (int i = k; i > 0; --i)
            {
                sell[i] = max(sell[i], buy[i] + e);
                buy[i] = max(buy[i], sell[i - 1] - e);
            }
        }
        return sell[k];
    }
};
int main()
{
    int b[4];
    cout<<sizeof b;

    vector<int> a = {3, 3, 5, 3, 4, 2, 8, 0, 6, 4};
    Solution s;
    cout<<s.maxProfit5(a);
}
