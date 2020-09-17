
#pragma once
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <functional>
#include<unordered_set>
using namespace std;
//Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
inline void initTree(TreeNode* node, int* arr, unsigned int num, int index = 0)
{
	if (2 * index + 1 < num)
	{
		node->left = new TreeNode(arr[2 * index + 1]);
		initTree(node->left, arr, num, 2 * index + 1);
	}
	if (2 * index + 2 < num)
	{
		node->right = new TreeNode(arr[2 * index + 2]);
		initTree(node->right, arr, num, 2 * index + 2);
	}
}
inline unsigned int getTreeHeight(TreeNode* root) {
    static function<void(TreeNode*,unsigned int&,unsigned int& )> func = [](TreeNode* node,unsigned int& res,unsigned int& h) {
        if (node == nullptr)return;
        h++;
        res = res > h?res:h;
        if (node->left != nullptr)func(node->left,res,h);
        if (node->right!= nullptr)func(node->right,res,h);
        h--;
    };
    unsigned int res = 0,temph=0;
    func(root,res,temph);
    return res;
}

inline void printTree(TreeNode* root)
{
	if (root == nullptr)
    {
        printf("NULL Tree");
        return;
    }

    //queue<TreeNode *> myQueue;
    //myQueue.emplace(root);
    //while (!myQueue.empty())
    //{
    //    unsigned int que_size = myQueue.size();
    //    for (int i = 0; i < que_size; ++i) {
    //        if (myQueue.front() == nullptr) {kk}
    //        if(myQueuemyQueue)printf("%d ",myQueue.front()->val);
    //        if (myQueue.front()->left != nullptr)myQueue.emplace(myQueue.front()->left);
    //        if (myQueue.front()->right!= nullptr)myQueue.emplace(myQueue.front()->right);
    //        myQueue.pop();
    //    }
    //    printf("\n");
    //}
}

inline void printVector(vector<int> r)
{
    for_each(r.begin(), r.end(), [](int a) {
        printf("%d\n", a);
    });
}
