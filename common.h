
#pragma once
#include<string>
#include<array>
#include <climits>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include<map>
#include<bitset>
#include<numeric>
#include<iostream>
#include<set>
#include <random>
#include <cstring>

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)       \
    (byte & 0x80 ? '1' : '0'),     \
        (byte & 0x40 ? '1' : '0'), \
        (byte & 0x20 ? '1' : '0'), \
        (byte & 0x10 ? '1' : '0'), \
        (byte & 0x08 ? '1' : '0'), \
        (byte & 0x04 ? '1' : '0'), \
        (byte & 0x02 ? '1' : '0'), \
        (byte & 0x01 ? '1' : '0')

using namespace std;
//Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *BuildBTLevelTraversal(int *arr, int num)
{
    if (num == 0)
        return nullptr;
    static function<TreeNode *(int)> f = [&](int i) -> TreeNode * {
        if (i >= num || arr[i] == INT_MAX)
            return nullptr;
        TreeNode *node = new TreeNode(arr[i]);
        node->left = f(2 * i + 1);
        node->right = f(2 * i + 2);
        return node;
    };
    TreeNode *root = f(0);
    return root;
}

inline unsigned int getTreeHeight(TreeNode *root)
{
    static function<void(TreeNode *, unsigned int &, unsigned int &)> func = [](TreeNode *node, unsigned int &res, unsigned int &h) {
        if (node == nullptr)
            return;
        h++;
        res = res > h ? res : h;
        if (node->left != nullptr)
            func(node->left, res, h);
        if (node->right != nullptr)
            func(node->right, res, h);
        h--;
    };
    unsigned int res = 0, temph = 0;
    func(root, res, temph);
    return res;
}
//TODO: fix this
inline void printTree(TreeNode *root)
{
    if (root == nullptr)
    {
        printf("NULL Tree");
        return;
    }

    struct Para
    {
        TreeNode *node;
        int height;
        int index;
        Para(TreeNode *n, int h, int i) : node(n), height(h), index(i) {}
    };
    vector<vector<Para>> temp;
    queue<Para> myque;
    myque.emplace(root, 1, 1);
    int h = 0;
    while (!myque.empty())
    {
        h++;
        size_t l = myque.size();
        vector<Para> tempvec;
        for (size_t i = 0; i < l; ++i)
        {
            tempvec.emplace_back(myque.front());
            if (myque.front().node->left != nullptr)
                myque.emplace(myque.front().node->left, h + 1, myque.front().index * 2);
            if (myque.front().node->right != nullptr)
                myque.emplace(myque.front().node->right, h + 1, myque.front().index * 2 + 1);
            myque.pop();
        }
        temp.emplace_back(tempvec);
    }
    for_each(temp.begin(), temp.end(), [&h](vector<Para> &aa) {
        int interval = 1 << (h - aa[0].height);
        {
            int k = interval;
            while (k-- > 0)
                printf(" ");
        }
        int l = 1 << (aa[0].height - 1);
        for (size_t i = 0; i < aa.size(); ++i)
        {
            int j = l;
            while (aa[i].index != j)
            {
                int k = interval;
                while (k-- > 0)
                    printf(" ");
                j++;
                l++;
            }
            printf("%d", aa[i].node->val);
            int k = interval;
            while (k-- > 0)
                printf("  ");

            l++;
        }
        printf("\n");
    });
}

inline void printVector(vector<int> r)
{
    for_each(r.begin(), r.end(), [](int a) {
        printf("%d\n", a);
    });
}

//================================================================
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

inline ListNode *buildList(int *arr, int count)
{
    if(count<1)return nullptr;
    ListNode *head, *p;
    p=new ListNode(arr[0]);
    head = p;
    for (int i = 1; i < count; i++)
    {
        p->next = new ListNode(arr[i]);
        p=p->next;
    }
    return head;
}
inline void printList(ListNode *head)
{
    ListNode* p=head;
    while (p)
    {
        printf("%d ", p->val);
        p= p->next;
    }
}

inline vector<int> buildNormalRandomVector(double mean,double stddev,int num){

    std::random_device rd{};
    std::mt19937 gen{rd()};
 
    // values near the mean are the most likely
    // standard deviation affects the dispersion of generated values from the mean
    std::normal_distribution<> d{mean,stddev}; 
    vector<int> ret(num); 
    for(auto& i:ret)
        i=d(gen);
    return ret;
}
inline std::vector<int> buildUniformRandomVector(int start,int end,int num){

    std::random_device rd{};
    std::mt19937 gen{rd()};
 
    // values near the mean are the most likely
    // standard deviation affects the dispersion of generated values from the mean
    std::uniform_int_distribution<> d{start,end}; 
    std::vector<int> ret(num); 
    for(auto& i:ret)
        i=d(gen);
    return ret;
}