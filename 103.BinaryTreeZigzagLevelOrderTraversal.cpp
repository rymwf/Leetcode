/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7

return its zigzag level order traversal as:

[
  [3],
  [20,9],
  [15,7]
]
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(!root)return ret;
        deque<TreeNode*> mydeque;        
        mydeque.emplace_back(root);
        bool flag=true;
        while(!mydeque.empty())
        {
            ret.emplace_back();
            int i=0,len=mydeque.size();
            for(;flag&&i<len;++i)
            {
                auto a=mydeque.front();
                ret.back().emplace_back(a->val);            
                mydeque.pop_front();
                if(a->left)mydeque.emplace_back(a->left);
                if(a->right)mydeque.emplace_back(a->right);
            }
            for(;!flag&&i<len;++i)
            {
                auto a=mydeque.back();
                ret.back().emplace_back(a->val);            
                mydeque.pop_back();
                if(a->right)mydeque.emplace_front(a->right);
                if(a->left)mydeque.emplace_front(a->left);
            }
            flag=!flag;
        }
        return ret;
    }
};
