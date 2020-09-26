/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:

[
   [5,4,11,2],
   [5,8,4,5]
]
 
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include "common.h"
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> ele;
        static function<void(TreeNode*,int)> f=[&](TreeNode* node,int s){
            if(node==nullptr)return;
            s+=node->val;
            ele.emplace_back(node->val);
            if(node->left==nullptr&&node->right==nullptr&&sum==s){
                res.emplace_back(ele);
                ele.pop_back();
                return;
            }
            f(node->left,s);
            f(node->right,s);
            ele.pop_back();
        };
        f(root,0);
        return res;
    }


};

int main(){
    int a[]={5,4,8,11,INT_MAX,13,4,7,2,INT_MAX,INT_MAX,INT_MAX,INT_MAX,5,1};
    TreeNode* root=BuildBTLevelTraversal(a,sizeof(a)/sizeof(a[0]));
    printTree(root);


    return 0;
}


