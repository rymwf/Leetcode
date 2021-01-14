/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3

 

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3

 

Follow up: Solve it both recursively and iteratively.
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
    bool isSymmetric(TreeNode *root)
    {
        return helper(root, root);
    }
    bool helper(TreeNode *node1, TreeNode *node2)
    {
        if (node1 == nullptr && node2 == nullptr)
            return true;
        return node1 &&
               node2 &&
               node1->val == node2->val &&
               helper(node1->left, node2->right) &&
               helper(node1->right, node2->left);
    }
};
