/*
Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.

Example:

Input: The root of a Binary Search Tree like this:
			  5
			/   \
		   2     13

Output: The root of a Greater Tree like this:
			 18
			/   \
		  20     13
Note: This question is the same as 1038: https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/
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
	TreeNode* convertBST(TreeNode* root) {
		if (root == nullptr)return root;
		stack<TreeNode*> stk;
		stk.emplace(root);
		int sum = 0;
		while (!stk.empty())
		{
			while (stk.top()->right != nullptr)stk.emplace(stk.top()->right);
			while (!stk.empty() && stk.top()->left == nullptr)
			{
				sum += stk.top()->val;
				stk.top()->val = sum;
				stk.pop();
			}
			if (stk.empty())break;
			TreeNode* curNode = stk.top();
			sum += curNode->val;
			curNode->val = sum;
			stk.pop();
			stk.emplace(curNode->left);
		}
		return root;
	}

	TreeNode* convertBST2(TreeNode* root) {
		int sum = 0;
		if (root != nullptr) {
			convertBST(root->right);
			sum += root->val;
			root->val = sum;
			convertBST(root->left);
		}
		return root;
	}
};

void main() {
	//int a[] = {1,2,3,4,5};
	int a[] = { 1,2,3,4,5,6,7,8 };
	TreeNode* root = new TreeNode(a[0]);
	initTree(root, a, sizeof(a) / sizeof(a[0]));
	printTree(root);
	Solution s;
	s.convertBST(root);
	printTree(root);
}

