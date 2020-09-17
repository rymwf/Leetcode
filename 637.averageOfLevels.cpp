#include "common.h"

vector<double> averageOfLevels(TreeNode *root)
{
    if (root == NULL)
        return vector<double>();
    vector<double> res;
    std::stack<TreeNode *> *stk1 = new std::stack<TreeNode *>();
    std::stack<TreeNode *> *stk2 = new std::stack<TreeNode *>();
    stk1->emplace(root);
    while (!stk1->empty())
    {
        double sum = 0;
        int count = 0;
        while (!stk1->empty())
        {
            count++;
            sum += stk1->top()->val;
            if (stk1->top()->left != nullptr)
                stk2->emplace(stk1->top()->left);
            if (stk1->top()->right != nullptr)
                stk2->emplace(stk1->top()->right);
            stk1->pop();
        }
        res.emplace_back(sum / count);
        std::stack<TreeNode *> *tempStk = stk1;
        stk1 = stk2;
        stk2 = tempStk;
    }

    delete stk1;
    delete stk2;
    return res;
}

void main()
{
}
