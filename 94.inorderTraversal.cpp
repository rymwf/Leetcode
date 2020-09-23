#include "common.h"

//TODO: ���Բ�������״̬��

vector<int> inorderTraversal(TreeNode* root)
{
	vector<int> res;
	struct Para
	{
		TreeNode* node;
		int status;
		Para(TreeNode* n, bool s) : node(n), status(s) {};
	};
	stack<Para> stk;
	Para a(root, 0);
	stk.push(a);

	while (!stk.empty())
	{
		Para* curPara = &stk.top();
		if (curPara->status == 0)
		{
			if (curPara->node->left != NULL) {
				stk.emplace(curPara->node->left, 0);
				curPara->status = 1;
				continue;
			}
			curPara->status = 1;
		}
		if (curPara->status == 1)
			res.emplace_back(curPara->node->val);
		if (curPara->status == 1)
		{
			if (curPara->node->right != NULL)
			{
				stk.emplace(curPara->node->right, 0);
				curPara->status = 2;
				continue;
			}
			curPara->status = 2;
		}
		if (curPara->status == 2)
			stk.pop();
	}
	return res;
}

int main()
{
	int a[] = { 1, 2, 3, 4, 5 };
	TreeNode* root = new TreeNode(a[0]);
	initTree(root, a, sizeof(a) / sizeof(a[0]));

	vector<int> r = inorderTraversal(root);
	printVector(r);
	return 0;
}
