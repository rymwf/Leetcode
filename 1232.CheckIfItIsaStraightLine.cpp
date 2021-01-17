/*
You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.

 

 

Example 1:

Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
Output: true

Example 2:

Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
Output: false

 

Constraints:

    2 <= coordinates.length <= 1000
    coordinates[i].length == 2
    -10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
    coordinates contains no duplicate point.
*/
#include"common.h"
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int len = coordinates.size();
        int v[] = {coordinates[1][0] - coordinates[0][0], coordinates[1][1] - coordinates[0][1]};
        for (int i = 2; i < len; ++i)
        {
            int a[] = {coordinates[i][0] - coordinates[0][0], coordinates[i][1] - coordinates[0][1]};
            if (a[0] * v[1] - a[1] * v[0])
                return false;
        }
        return true;
    }
};

