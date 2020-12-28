/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Notice that you may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.

Example 2:

Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.

 

Constraints:

    0 <= k <= 109
    0 <= prices.length <= 1000
    0 <= prices[i] <= 1000
*/
#include"common.h"

//could use dynamic programming
class Solution {
public:
//    template<class T>
//    int helper(T start,T end)
//    {
//        int ret = 0;
//        auto minit = start, maxit = start;
//        while (++start != end)
//        {
//            auto it = --start;
//            if (*start < *minit)
//            {
//                minit = start;
//                maxit = start;
//            }
//            else if(*start>*maxit)
//            {
//                maxit = start;
//                ret = max(ret, *start- *minit);
//            }
//        }
//        return ret;
//    }

    //if reverse is true, start>end
    int helper(int start,int end,vector<int>& prices,bool reverse,int& buy,int& sell)
    {
        int ret=0;
        if((reverse&&start<=end)||(!reverse&&start>=end))return ret;
        int minindex=start,maxindex=start;
        buy=sell=start;
        int step=reverse?-1:1;
        start+=step;
        while(start!=end)
        {
            if(prices[start]<prices[minindex]) 
            {
                minindex=start;
                maxindex=start;
            }else if(prices[start]>prices[maxindex])
            {
                maxindex=start;
                int a=prices[maxindex]-prices[minindex];
                if(a>ret)
                {
                    ret=a;
                    buy=minindex;
                    sell=maxindex;
                }
            }
            start+=step;
        }
        return ret;
    }
    int maxProfit(int k, vector<int>& prices) {
        int ret=0;
        int len0=prices.size();
        if(len0<1)return ret;
        struct A{
            int end;        //sell point
            int maxprofit;  //range preend-start
            int maxdeficit; //range start-end
        };
        map<int,A> mymap;   //key is buy point
        mymap[-1]=A{-1,0,0};
        mymap[len0-1]={len0-1,0,0};
        for(int i=0;i<k;++i)
        {
            int max0= 0;
            bool flag{};
            auto targetit=mymap.end();
            int minindex,maxindex;
            for(auto it=++mymap.begin();it!=mymap.end();++it)
            {
                cout<<it->first<<" "<<it->second.end<<endl;
                if(it->second.maxprofit==0)
                {
                    auto preit=it;
                    preit--;
                    it->second.maxprofit = helper(preit->second.end + 1, it->first + 1, prices, false, minindex, maxindex);
                }
                if(it->second.maxdeficit==0)
                {
                    it->second.maxdeficit = helper(it->second.end, it->first - 1, prices, true, minindex, maxindex);
                }

                if (it->second.maxprofit > max0)
                {
                    targetit=it;
                    max0 = it->second.maxprofit;
                    flag = false;
                }
                if (it->second.maxdeficit > max0)
                {
                    targetit=it;
                    max0 = it->second.maxdeficit;
                    flag = true;
                }
            }
            if(targetit==mymap.end())break;
            if(flag){
                int a = helper(targetit->first, targetit->second.end + 1, prices, false, minindex, maxindex);
                ret -= a;
                helper(targetit->second.end, targetit->first - 1, prices, true, minindex, maxindex);
                ret += prices[maxindex] - prices[targetit->first];
                ret += prices[targetit->second.end] - prices[minindex];
                mymap[minindex] = A{targetit->second.end, 0, 0};
                mymap[targetit->first].end = maxindex;
                mymap[targetit->first].maxdeficit = 0;
            }else
            {
                auto it=targetit;
                it--;
                helper(it->second.end + 1, targetit->first + 1, prices, false, minindex, maxindex);
                mymap[targetit->first].maxprofit=0;
                mymap[minindex]=A{maxindex,0,0};
                ret+=max0;
            }
        }
        return ret;
    }
};

int  main(){

    int k = 2;
    //vector<int> prices = {3, 2, 6, 5, 0, 3,10};
    vector<int> prices = {1,2,4,2,5,7,2,4,9,0};
    Solution s;
        s.maxProfit(k, prices);
    //cout << s.helper(0, prices.size(), prices, false)
    //     << endl
    //     << s.helper(prices.size() - 1, -1, prices, true);
}

