/*
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Return 0 if the array contains less than 2 elements.

Example 1:

Input: [3,6,9,1]
Output: 3
Explanation: The sorted form of the array is [1,3,6,9], either
             (3,6) or (6,9) has the maximum difference 3.

Example 2:

Input: [10]
Output: 0
Explanation: The array contains less than 2 elements, therefore return 0.

Note:

    You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
    Try to solve it in linear time/space.
*/
#include"common.h"
#include "sort.h"
class Solution {
public:
    int maximumGap(vector<int> nums) {
        if(nums.size()<2)return 0;
//        sort(nums.begin(),nums.end());
        radixSort(nums,10);
        int maxgap=0;
        for(int i=1,len=nums.size();i<len;++i)
        {
            maxgap=max(maxgap,nums[i]-nums[i-1]);
        }
        return maxgap;
    }
};

int main(){
    //auto a = buildUniformRandomVector(0, 10, 10);
    vector<int> a={1,10000};
    for (auto i : a)
        printf("%d, ", i);
    Solution s;
    printf("\ntest:%d", s.maximumGap(a));

}
