/*
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Given binary search tree:  root = [6,2,8,0,4,7,9,null,null,3,5]


 

Example 1:

Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.
Example 2:

Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
 

Constraints:

All of the nodes' values will be unique.
p and q are different and both values will exist in the BST.

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
    //TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode *lowestCommonAncestor(TreeNode *root, int p, int q)
    {
        if (root == nullptr)
            return nullptr;
        vector<TreeNode *> vec1, vec2;
        bool flag1 = true, flag2 = true;
        function<void(TreeNode *)> f = [&](TreeNode *node) {
            if (node == nullptr)
                return;
            if (flag1)
            {
                vec1.emplace_back(node);
                if (node->val == p)
                    flag1 = false;
            }
            if (flag2)
            {
                vec2.emplace_back(node);
                if (node->val == q)
                    flag2 = false;
            }
            f(node->left);
            f(node->right);
            if (flag1)
                vec1.pop_back();
            if (flag2)
                vec2.pop_back();

            return;
        };
        f(root);
        int a = vec1.size() > vec2.size() ? vec2.size() : vec1.size();
        int i = 0;
        for (; i < a; ++i)
        {
            if (vec2[i] != vec1[i])
                break;
        }
        return vec1[i - 1];
    }


    //TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* lowestCommonAncestor2(TreeNode* root, int p, int q) {
        TreeNode *curNode = root;
        while (true)
        {
            if (curNode->val > p && curNode->val > q)
            {
                curNode = curNode->left;
                continue;
            }
            if (curNode->val < p && curNode->val < q)
            {
                curNode = curNode->right;
                continue;
            }
            return curNode;
        }
    }

};

int main()
{
    int a[] = {6, 2, 8, 0, 4, 7, 9, INT_MAX, INT_MAX, 3, 5};
    TreeNode *root = BuildBTLevelTraversal(a, sizeof(a) / sizeof(a[0]));
    Solution s;
    TreeNode *res = s.lowestCommonAncestor2(root, 2, 4);
    printf("%d", res->val);
    return 0;
}