#include "common.h"



//TODO: ²¢²é¼¯2
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        if (edges.size() <= 1)return vector<int>();
        int rootEdge=0;
        int preNode;
        unordered_set<int> myset;
        myset.emplace(0);
        while (myset.size()!=edges.size())
        {
        
        for (int i = 1; i < edges.size(); ++i) {
            if (myset.find(i) != myset.end())continue;
            if (edges[i][0] == preNode) {
                preNode = edges[i][1];
                myset.emplace(i);
            };
        }
        
        }



       
    }
};


void main() {

//    int a[][2]={{1, 2}, {2, 3}, {3, 4}, {4, 1}, {1, 5},};
 int a[][2]=   {{2, 1}, {3, 1}, {4, 2}, {1, 4}};
    vector<vector<int>>  b;
    int sizex = sizeof(a) / sizeof(a[0]);
    int sizey = 2;
    b.resize(sizex);
    vector<int> temp;
    for (int i = 0; i < sizex; ++i) {
        temp.clear();
        for (int j = 0; j < sizey; ++j) {
            temp.emplace_back(a[i][j]);
        }
        b[i] = temp;
    }
    Solution s;
    vector<int>res=s.findRedundantDirectedConnection(b);
    printf("%d %d",res[0],res[1]);
}