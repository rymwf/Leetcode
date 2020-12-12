/*
A sequence of numbers is called a wiggle sequence if the differences between successive numbers strictly alternate between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence with fewer than two elements is trivially a wiggle sequence.

For example, [1,7,4,9,2,5] is a wiggle sequence because the differences (6,-3,5,-7,3) are alternately positive and negative. In contrast, [1,4,7,2,5] and [1,7,4,5,5] are not wiggle sequences, the first because its first two differences are positive and the second because its last difference is zero.

Given a sequence of integers, return the length of the longest subsequence that is a wiggle sequence. A subsequence is obtained by deleting some number of elements (eventually, also zero) from the original sequence, leaving the remaining elements in their original order.

Example 1:

Input: [1,7,4,9,2,5]
Output: 6
Explanation: The entire sequence is a wiggle sequence.

Example 2:

Input: [1,17,5,10,13,15,10,5,16,8]
Output: 7
Explanation: There are several subsequences that achieve this length. One is [1,17,10,13,10,16,8].

Example 3:

Input: [1,2,3,4,5,6,7,8,9]
Output: 2

Follow up:
Can you do it in O(n) time?

*/
#include"common.h"

class Solution {
public:
    //for debug 
    int wiggleMaxLength(vector<int>& nums) {
        int len=nums.size();
        if(len<=2)return len;
        vector<int> top;
        vector<int> bottom;
        int i=0;
        while(++i<len&&nums[i]==nums[0]);
        if(nums[i]>nums[0]){
            top.emplace_back(i);
            bottom.emplace_back(0);
        }else{
            top.emplace_back(0);
            bottom.emplace_back(i);
        }
        for(++i;i<len;++i)
        {
            int t=top.back();
            int b=bottom.back();
            if(t>b)
            {
                if(nums[i]>=nums[t])top.back()=i;
                else bottom.emplace_back(i);
            }else{
                if(nums[i]<=nums[b])bottom.back()=i;
                else top.emplace_back(i);
            }
        }
        printf("\ntop: ");
        for(auto i:top)
        {
            printf("%d ",i);
        }
        printf("\nbottom: ");
        for(auto i:bottom)
        {
            printf("%d ",i);
        }
        return top.size()+bottom.size();
    }
    int wiggleMaxLength2(vector<int>& nums) {
        int len = nums.size();
        if(len<=1)return len;
        int ret=1;
        int i=0;
        while(++i<len&&nums[i]==nums[0]);
        if(i==len)return ret;
        ret++;
        int t=0,b=0;
        if(nums[i]>nums[0])
        {
            t=i;
            b=0;
        }else{
            t=0;
            b=i;
        }
        for(++i;i<len;++i)
        {
            if(t>b){
                if(nums[i]>=nums[t])t=i;
                else{
                    b=i;
                    ret++;
                }
            }else{
                if(nums[i]<=nums[b])b=i;
                else{
                    t=i;
                    ret++;
                }
            }
        }
        return ret;
    }
    int wiggleMaxLength3(vector<int>& nums) {
        int up = 1;
        int down = 1;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i-1]) {
                up = down + 1;
            } 
            else if (nums[i] < nums[i-1]) {
                down = up + 1;
            }
        }

        return nums.size() == 0 ? 0: max(up, down);
    }
    

};
int main(){
    //vector<int> Input = {1, 7, 4, 9, 2, 5};
    vector<int> Input= {1,17,5,5,5,10,13,15,10,5,16,8};
    //vector<int> Input= {1,2,3,4,5,6,7,8,9};
    
    Solution s;
    auto res = s.wiggleMaxLength(Input);
    cout << endl
         << res;
}


