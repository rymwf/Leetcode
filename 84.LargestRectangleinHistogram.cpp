/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

 


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

 


The largest rectangle is shown in the shaded area, which has area = 10 unit.

 

Example:

Input: [2,1,5,6,2,3]
Output: 10
*/
#include"common.h"

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int len = heights.size();
        if(len==0)return 0;
        int ret=0;
        for(int i=1;i<len;++i)
        {
            int min0=heights[i];
            ret=max(min0,ret);
            if(i>0&&heights[i]<=heights[i-1])continue;
            int j=i+1;
            for (; j < len&&heights[j]!=0; ++j)
            {
                if(heights[j]>min0)continue;
                ret=max(ret,min0*(j-i));
                min0=min(min0,heights[j]);
            }
            ret = max(ret, min0 * (j - i + 1));
        }
        return ret;
    }
    int largestRectangleArea2(vector<int>& heights) {
        int len = heights.size();
        if(len==0)return 0;
        int ret=0;
        stack<int> stk;
        stk.emplace(-1);
        for(int i=0;i<len;++i)
        {
            while (stk.top() != -1 && heights[stk.top()] >= heights[i])
            {
                int a = stk.top();
                stk.pop();
                ret = max(ret, (i - stk.top() - 1) * heights[a]);
            }
            stk.emplace(i);
        }
        while(stk.top()!=-1)
        {
            int a=stk.top();
            stk.pop();
            ret=max(ret,(len-stk.top()-1)*heights[a]);
        }
        return ret;
    }
    int largestRectangleArea3(vector<int> &heights)
    {
        heights.push_back(0); //保证右边界为最后一个柱子时，方便计算
        stack<int> S;
        int maxarea(0);
        for (int i = 0; i < heights.size(); i++)
        {
            while (!S.empty() && heights[i] < heights[S.top()])
            {
                int curheight = S.top();
                S.pop();
                //判断一下如果栈顶柱子为空，则令栈顶元素为0
                int area = heights[curheight] * (!S.empty() ? (i - S.top() - 1) : i);
                maxarea = max(maxarea, area);
            }
            S.push(i);
        }
        return maxarea;
    }
};
int main(){
//vector<int> a={5,3,2,7,5,3,0,1,2,1,3};
//vector<int> a={4,0,3,2,5};
vector<int> a={2,1,1,2,3};
Solution s;
s.largestRectangleArea2(a);


}