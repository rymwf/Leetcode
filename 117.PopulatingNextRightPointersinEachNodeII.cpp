/**
Given a binary tree

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}

Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

 

Follow up:

    You may only use constant extra space.
    Recursive approach is fine, you may assume implicit stack space does not count as extra space for this problem.

 

Example 1:

Input: root = [1,2,3,4,5,null,7]
Output: [1,#,2,3,#,4,5,7,#]
Explanation: Given the above binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.

 

Constraints:

    The number of nodes in the given tree is less than 6000.
    -100 <= node.val <= 100

 */
#include "common.h"

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (root == nullptr)
            return nullptr;
        std::queue<Node *> que1;
        que1.emplace(root);
        while (!que1.empty())
        {
            int len = que1.size();
            while (len-- > 0)
            {
                Node *curNode = que1.front();
                que1.pop();
                if (len == 0)
                    curNode->next = nullptr;
                else
                    curNode->next = que1.front();
                if (curNode->left != nullptr)
                    que1.emplace(curNode->left);
                if (curNode->right != nullptr)
                    que1.emplace(curNode->right);
            }
        }
        return root;
    }

    Node *connect2(Node *root)
    {
        if (root == nullptr)
            return nullptr;
        Node *node0 = nullptr;
        //find right size left most node
        Node *node1 = root->next;
        while (node1 != nullptr)
        {
            if (node1->left != nullptr)
            {
                node0 = node1->left;
                break;
            }
            else if (node1->right != nullptr)
            {
                node0 = node1->right;
                break;
            }
            node1 = node1->next;
        }
        //connect
        if (root->right != nullptr)
        {
            root->right->next = node0;
            if (root->left != nullptr)
                root->left->next = root->right;
        }
        else
        {
            if (root->left != nullptr)
                root->left->next = node0;
        }
        connect(root->right);
        connect(root->left);
        return root;
    }
};

int main()
{
    return 0;
}
