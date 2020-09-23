/*
Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
 

For example:
Given BST [1,null,2,2],

   1
    \
     2
    /
   2
 

return [2].

Note: If a tree has more than one mode, you can return them in any order.

Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).

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
public:
    vector<int> findMode(TreeNode *root)
    {
        vector<int> res;
        int maxNum = 0;
        int num = 0;
        TreeNode *preNode = nullptr;
        static function<void(TreeNode *)> f = [&](TreeNode *node) {
            if (node == nullptr)
                return;
            f(node->left);
            if (preNode == nullptr)
            {
                num++;
                res.emplace_back(node->val);
                maxNum = num;
            }
            else
            {
                if (node->val == preNode->val)
                {
                    num++;
                    if (num > maxNum)
                    {
                        res.clear();
                        res.emplace_back(node->val);
                    }
                    else if (num == maxNum)
                    {
                        res.emplace_back(node->val);
                    }
                }
                else
                {
                    if (maxNum == 1)
                        res.emplace_back(node->val);
                    num = 1;
                }
            }
            preNode = node;
            maxNum = maxNum > num ? maxNum : num;
            f(node->right);
        };
        f(root);
        return res;
    }
};

int main()
{
    return 0;
}
