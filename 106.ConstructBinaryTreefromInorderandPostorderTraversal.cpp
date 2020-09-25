/*
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.size() == 0)
            return nullptr;
        unordered_map<int,int> inmap;
        for(int i=0;i<inorder.size();++i){
            inmap[inorder[i]]=i;
        }
        int post1 = postorder.size() - 1;
        static function<void(TreeNode *, int, int, bool)> f = [&](TreeNode *root, int in1, int in2, bool flag) {
            if(in1>in2)return;
            post1--;
            int i = inmap[postorder[post1]];
            if (flag)
            {
                root->right = new TreeNode(postorder[post1]);
                f(root->right, i + 1, in2, true);
                f(root->right, in1, i - 1, false);
            }
            else
            {
                root->left = new TreeNode(postorder[post1]);
                f(root->left, i + 1, in2, true);
                f(root->left, in1, i - 1, false);
            }
        };

        TreeNode *root = new TreeNode(postorder.back());
        int i = inmap[postorder.back()];
        f(root, i+ 1, inorder.size() - 1,true); //right tree
        f(root, 0, i- 1,false);                  //left tree
        return root;
    }
};

int main(){
    vector<int> inorder{9,3,15,20,7};
    vector<int> postorder{9,15,7,20,3};
    Solution s;
    TreeNode* root=s.buildTree(inorder,postorder);
    printTree(root);


    return 0;
}




