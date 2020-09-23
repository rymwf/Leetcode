/*
Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
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
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int res(0);
        if (root == nullptr)return res;
        static function<void(TreeNode*,int)> func = [&res](TreeNode* node,int flag) {
            if (flag == 1 && node->left == nullptr && node->right == nullptr) {
                res += node->val;
                return;
            }
            if (node->left != nullptr)func(node->left,1);
            if (node->right!= nullptr)func(node->right,2);
        };
        func(root,0);
        return res;
    }

    int sumOfLeftLeaves2(TreeNode* root) {
        int res(0);
        if (root == nullptr)return res;
        stack<TreeNode*> stk;
        stk.emplace(root);
        while (!stk.empty())
        {
            TreeNode* curNode = stk.top();
            stk.pop();
            if (curNode->right != nullptr)stk.emplace(curNode->right);
            if (curNode->left != nullptr) {
                if (curNode->left->left == nullptr &&curNode->left->right == nullptr)res += curNode->left->val;
                else stk.emplace(curNode->left);
            }
        }
        return res;
    }

};

int main() {

    int a[] = {1,2,3,4,5,6};
    TreeNode* root = new TreeNode(a[0]);
    initTree(root,a,sizeof(a)/sizeof(a[0]));
    Solution s;
    int r = s.sumOfLeftLeaves2(root);
    printf("%d",r);
    return 0;
}