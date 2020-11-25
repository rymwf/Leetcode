/*
Given a complete binary tree, count the number of nodes.

Note:

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Example:

Input: 
    1
   / \
  2   3
 / \  /
4  5 6

Output: 6

*/
#include"common.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        int h=0;
        int res=0;
        static function<bool(TreeNode*,int,int)> f=[&h,&res](TreeNode* node,int curh,int rownum){
            if(!node){
                if(h==0)h=curh;
                if(curh==h)return false;
    	        res=(1<<(h-1))+rownum-1;
                return true;
            }
            printf("\n");
            printf("node:%d curh:%d, rownum:%d",node->val,curh,rownum);
            if(f(node->left,curh+1,rownum*2)||f(node->right,curh+1,rownum*2+1))
                return true;
            return false;
        };
        if(f(root,0,0))return res;
        else return (1<<h)-1;
    }
    int countNodes2(TreeNode* root) {
        int m=1;
        TreeNode* cur=root;
        while(cur){
            cur=cur->left;
            m<<=1;
        }
        int low=m>>1,high=m-1;
        while(low<high){
            int mask=m>>2;
            int mid=((high-low+1)>>1)+low;
            cur=root;
            while(cur&&mask>0){
                if(mask&mid)cur=cur->right;
                else cur=cur->left;
                mask>>=1;
            }
            if(cur)low=mid;
            else high=mid-1;
        }
        return low;
    }
};

int main(){
    int arr[]={1,2,3,4,5,6,7,8,9,10,11};
    //int arr[]={1};
    TreeNode* root=BuildBTLevelTraversal(arr,sizeof arr/sizeof arr[0]);
    printTree(root); 
    Solution s;
    int res=s.countNodes2(root);
    printf("\nres:%d",res);

}