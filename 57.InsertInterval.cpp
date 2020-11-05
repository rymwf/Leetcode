/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

 

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]

Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].

Example 3:

Input: intervals = [], newInterval = [5,7]
Output: [[5,7]]

Example 4:

Input: intervals = [[1,5]], newInterval = [2,3]
Output: [[1,5]]

Example 5:

Input: intervals = [[1,5]], newInterval = [2,7]
Output: [[1,7]]

 

Constraints:

    0 <= intervals.length <= 104
    intervals[i].length == 2
    0 <= intervals[i][0] <= intervals[i][1] <= 105
    intervals is sorted by intervals[i][0] in ascending order.
    newInterval.length == 2
    0 <= newInterval[0] <= newInterval[1] <= 105
*/
#include "common.h"
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int l=0;
        for(;l<intervals.size();++l){
            if(intervals[l][1]>=newInterval[0])break;
        }
        if(l==intervals.size()){
            intervals.emplace_back(newInterval);
            return intervals;
        }
        int r=l+1;
        for(;r<intervals.size();++r){
            if(intervals[r][0]>newInterval[1]){break;}
        }
        r--;
//        if(r==intervals.size())r--;
        if(l<r){
            intervals[l][1]=intervals[r][1];
            intervals.erase(intervals.begin()+l+1,intervals.begin()+r+1);
        } 
        if(newInterval[1]<intervals[l][0])
            intervals.insert(intervals.begin()+l,newInterval); 
        else if(newInterval[0]>intervals[l][1])
            intervals.insert(intervals.begin()+l+1,newInterval); 
        else {
            if(intervals[l][0]>newInterval[0])intervals[l][0]=newInterval[0];
            if(intervals[l][1]<newInterval[1])intervals[l][1]=newInterval[1];
        }
        return intervals;
    }
};
int main(){

    //vector<vector<int>> a={{3,5},{12,15}};
    vector<vector<int>> a={{1,2},{3,5},{6,7},{8,10},{12,16}};
    //vector<int> b={6,6};
    vector<int> b[] = {
        {1, 2},
        {1, 3},
        {1, 4},
        {3, 4},
        {4, 4},
        {4, 5},
        {4, 6},
        {5, 6},
        {5, 12},
        {6, 12},
        {6, 11},
        {7, 12},
        {7, 13},
        {7, 15},
        {7, 16},
        {12, 15},
        {15, 16},
        {16, 17},
        {1, 17},
        {4, 13},
        {4, 17},
        };
    for(auto&i:a){
        printf("[%d %d] ",i[0],i[1]);
    }
    Solution s;
    for(auto i:b)
//    auto i = vector<int>{4, 6};
    {
        auto  a2=a; 
        printf("\n[%d %d]\n", i[0], i[1]);
        auto res = s.insert(a2, i);

        for (auto &r : res)
        {
            printf("[%d %d] ", r[0], r[1]);
        }
    }
}