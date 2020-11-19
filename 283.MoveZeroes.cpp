/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]

Note:

    You must do this in-place without making a copy of the array.
    Minimize the total number of operations.
*/
#include "common.h"

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        size_t p = 0;
        for(size_t i=0;i<nums.size();++i){
            if(nums[i]!=0){
                nums[p]=nums[i];
                p++;
            } 
        }
        for(;p<nums.size();++p)
            nums[p]=0;
    }
};
int main(){
    vector<int> a={0,1,0,3,4,5};
    for(auto &i:a)
        printf("%d ",i);
    Solution s;
    s.moveZeroes(a);
    printf("\n");
    for(auto &i:a)
        printf("%d ",i);



}
