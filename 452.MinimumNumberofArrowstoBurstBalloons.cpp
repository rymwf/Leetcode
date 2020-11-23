/*
There are some spherical balloons spread in two-dimensional space. For each balloon, provided input is the start and end coordinates of the horizontal diameter. Since it's horizontal, y-coordinates don't matter, and hence the x-coordinates of start and end of the diameter suffice. The start is always smaller than the end.

An arrow can be shot up exactly vertically from different points along the x-axis. A balloon with xstart and xend bursts by an arrow shot at x if xstart ≤ x ≤ xend. There is no limit to the number of arrows that can be shot. An arrow once shot keeps traveling up infinitely.

Given an array points where points[i] = [xstart, xend], return the minimum number of arrows that must be shot to burst all balloons.

 

Example 1:

Input: points = [[10,16],[2,8],[1,6],[7,12]]
Output: 2
Explanation: One way is to shoot one arrow for example at x = 6 (bursting the balloons [2,8] and [1,6]) and another arrow at x = 11 (bursting the other two balloons).

Example 2:

Input: points = [[1,2],[3,4],[5,6],[7,8]]
Output: 4

Example 3:

Input: points = [[1,2],[2,3],[3,4],[4,5]]
Output: 2

Example 4:

Input: points = [[1,2]]
Output: 1

Example 5:

Input: points = [[2,3],[2,3]]
Output: 1

 

Constraints:

    0 <= points.length <= 104
    points[i].length == 2
    -231 <= xstart < xend <= 231 - 1
*/
#include"common.h"

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size()==0)return 0;
        sort(points.begin(),points.end());
        for (auto &ele : points)
            printf("[%d %d] ", ele[0], ele[1]);
        int ret=0;
        for(int i=1,len=points.size();i<len;++i){
            if(points[i][0]<=points[i-1][1]){
               if(points[i-1][1]<points[i][1])points[i][1]=points[i-1][1];
            }
            else
                ret++;
        }
        return ret + 1;
    }
};

int main(){
    //vector<vector<int>> a={{10,16},{2,8},{1,6},{7,12}};
//    vector<vector<int>> a={{1,2},{3,4},{5,6},{7,8}};
//    vector<vector<int>> a={{1,2},{2,3},{3,4},{4,5}};
    vector<vector<int>> a{{9,12},{1,10},{4,11},{8,12},{3,9},{6,9},{6,7}};
//    vector<vector<int>> a={{2,3},{2,3}};
    Solution s;
    int res = s.findMinArrowShots(a);
    printf("\n");
    for (auto &ele : a)
        printf("[%d %d] ", ele[0], ele[1]);
    printf("\n%d", res);
}
