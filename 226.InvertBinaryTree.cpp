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
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == nullptr)
            return root;
        auto func_swap = [](TreeNode *node) {
            TreeNode *tempNode = node->left;
            node->left = node->right;
            node->right = tempNode;
        };
        stack<TreeNode *> stk;
        stk.emplace(root);
        while (!stk.empty())
        {
            TreeNode *curNode = stk.top();
            func_swap(curNode);
            stk.pop();
            if (curNode->left != nullptr)
                stk.emplace(curNode->left);
            if (curNode->right != nullptr)
                stk.emplace(curNode->right);
        }
        return root;
    }
};

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    TreeNode *root = new TreeNode(a[0]);
    initTree(root, a, sizeof(a) / sizeof(a[0]));
    int height = getTreeHeight(root);
    //printTree(root);
    Solution s;
    s.invertTree(root);
    //printTree(root);
    return 0;
}
