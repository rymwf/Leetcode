/*
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

Follow up: Could you write an algorithm with O(log n) runtime complexity?

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:

Input: nums = [], target = 0
Output: [-1,-1]

 

Constraints:

    0 <= nums.length <= 105
    -109 <= nums[i] <= 109
    nums is a non-decreasing array.
    -109 <= target <= 109
*/
#include"common.h"

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;  
        if(r<0)return vector<int>{-1,-1};
        int mid=(l+r)>>1;
        while(l<=r&&nums[mid]!=target){
           if(nums[mid]<target)l=mid+1; 
           else r=mid-1;
           mid=(l+r)>>1;
        }
        if(l>r)return vector<int>{-1,-1};
        int r1=mid;
        int p=(l+r1)>>1;
        while(l<r1){
            if(nums[p]==target)r1=p;
            else l=p+1;
            p=(l+r1)>>1;
        }
        l=mid;
        mid = ((r - l + 1) >> 1) + l;
        while(l<r){
            if(nums[mid]==target)l=mid;
            else r=mid-1;
            mid = ((r - l + 1) >> 1) + l;
        }
        return vector<int>{r1,l};
    }
};
int main(){
    vector<int>a={1};
    int t=1;
    Solution s;
    auto res=s.searchRange(a,t);
    printf("%d %d",res[0],res[1]);
}