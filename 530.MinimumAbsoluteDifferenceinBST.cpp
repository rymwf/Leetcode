/*
Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.

Example:

Input:

   1
    \
     3
    /
   2

Output:
1

Explanation:
The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).

 

Note:

    There are at least two nodes in this BST.
    This question is the same as 783: https://leetcode.com/problems/minimum-distance-between-bst-nodes/

*/

#include "common.h"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
    int res = INT_MAX;
    TreeNode *pre = nullptr;

public:
    int getMinimumDifference(TreeNode *root)
    {
        if (!root)
            return res;
        if (root->left != NULL)
            res = min(getMinimumDifference(root->left), res);
        if (res == 1)
            return res;
        if (pre)
            res = min(root->val - pre->val, res);
        pre = root;
        if (root->right != NULL)
            res = min(getMinimumDifference(root->right), res);
        return res;
    }
};
