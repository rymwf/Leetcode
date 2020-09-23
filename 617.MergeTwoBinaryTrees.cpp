/*
Given two binary trees and imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not.

You need to merge them into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of new tree.

Example 1:

Input: 
	Tree 1                     Tree 2                  
          1                         2                             
         / \                       / \                            
        3   2                     1   3                        
       /                           \   \                      
      5                             4   7                  
Output: 
Merged tree:
	     3
	    / \
	   4   5
	  / \   \ 
	 5   4   7
 

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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        static function<void(TreeNode*, TreeNode*, TreeNode*)> func = [](TreeNode* t1, TreeNode* t2, TreeNode* root){
            if (t1 != nullptr && t2 == nullptr) {
                root->val = t1->val;
				if (t1->left != nullptr) {
					root->left = new TreeNode(0);
					func(t1->left, nullptr, root->left);
				}
				if (t1->right != nullptr) {
					root->right = new TreeNode(0);
					func(t1->right, nullptr, root->right);
				}
			}
			if (t2 != nullptr && t1 == nullptr) {
                root->val = t2->val;
                if (t2->left != nullptr) {
					root->left = new TreeNode(0);
					func(nullptr,t2->left, root->left);
				}
				if (t2->right != nullptr) {
					root->right = new TreeNode(0);
					func( nullptr,t2->right, root->right);
				}
           }
            if (t1 != nullptr && t2 != nullptr) {
                root->val = t2->val + t1->val;
                if (t1->left != nullptr || t2->left != nullptr) {
					root->left = new TreeNode(0);
					func(t1->left, t2->left, root->left);
				}
				if (t1->right != nullptr || t2->right != nullptr) {
					root->right = new TreeNode(0);
					func(t1->right, t2->right, root->right);
				}
            }
            };
        TreeNode* root=nullptr;
        if (t1 != nullptr || t2 != nullptr) {
            root = new TreeNode(0);
            func(t1,t2,root);
        }
        return root;
    }

    TreeNode* mergeTrees2(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr)return t2;
        if (t2 == nullptr)return t1;
        t1->val += t2->val;
        t1->left=mergeTrees2(t1->left, t2->left);
        t1->right=mergeTrees2(t1->right, t2->right);
        return t1;
    }

};

void main() {
    int a1[] = {1,2,3,4,5};
    int a2[] = {1,2,3,4,5};

    TreeNode* t1 = new TreeNode(a1[0]);
    initTree(t1,a1,sizeof(a1)/sizeof(a1[0]));
    printTree(t1);
    TreeNode* t2 = new TreeNode(a2[0]);
    initTree(t2,a2,sizeof(a2)/sizeof(a2[0]));
    printTree(t2);
    Solution s;
    TreeNode* root=s.mergeTrees(t1,t2);
    printTree(root);
}



