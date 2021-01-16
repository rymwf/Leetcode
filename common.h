
#pragma once
#include <string>
#include <array>
#include <climits>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <bitset>
#include <numeric>
#include <iostream>
#include <set>
#include <random>
#include <cstring>
#include <list>
#include <forward_list>
#include <chrono>

#define MYLOCAL 1
#define MEASURE_TIME_BEGIN                       \
    cout << __FILE__ << " " << __LINE__ <<": start measure time:"<< endl; \
    auto start = std::chrono::steady_clock::now();
#define MEASURE_TIME_END                                                                                                \
    auto dur = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start).count(); \
    std::cout << "elapsed time(ms):" << dur << std::endl;

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

//#define dbg(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl
#define dbg(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ") " << endl
#define dbgvec(arr)              \
    cout << #arr << ":" << endl; \
    for (auto &e : arr)          \
        cout << e << " ";        \
    cout << endl

#define dbgmap(arr)                                  \
    cout << #arr << ":" << endl;                     \
    for (auto &it : arr)                             \
        cout << it.first << " " << it.second << " "; \
    cout << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

using vs = vector<string>;
using vss = vector<vector<string>>;

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
    if (count < 1)
        return nullptr;
    ListNode *head, *p;
    p = new ListNode(arr[0]);
    head = p;
    for (int i = 1; i < count; i++)
    {
        p->next = new ListNode(arr[i]);
        p = p->next;
    }
    return head;
}
inline void printList(ListNode *head)
{
    ListNode *p = head;
    while (p)
    {
        printf("%d ", p->val);
        p = p->next;
    }
}

inline vector<int> buildNormalRandomVector(double mean, double stddev, int num)
{

    std::random_device rd{};
    std::mt19937 gen{rd()};

    // values near the mean are the most likely
    // standard deviation affects the dispersion of generated values from the mean
    std::normal_distribution<> d{mean, stddev};
    vector<int> ret(num);
    for (auto &i : ret)
        i = d(gen);
    return ret;
}
inline std::vector<int> buildUniformRandomVector(int start, int end, int num)
{

    std::random_device rd{};
    std::mt19937 gen{rd()};

    // values near the mean are the most likely
    // standard deviation affects the dispersion of generated values from the mean
    std::uniform_int_distribution<> d{start, end};
    std::vector<int> ret(num);
    for (auto &i : ret)
        i = d(gen);
    return ret;
}
#if 1
class UnionFindList{
public:
    struct equivNode
    {
        int equivClass;
        int size;
        int next;
    };
    UnionFindList(int n) : _classnum(n)
    {
        _nodes.resize(n + 1);
        for (int i = 0; i <= n; ++i)
        {
            _nodes[i] = {i, 1};
        }
    };
    void uniteEle(int elea, int eleb)
    {
        uniteClass(find(elea), find(eleb));
    }

    void uniteClass(int classa, int classb)
    {
        if (classa == classb)
            return;
        _classnum--;
        if (_nodes[classa].size > _nodes[classb].size)
            swap(classa, classb);
        int i = classa;
        while (_nodes[i].next)
        {
            _nodes[i].equivClass = classb;
            i = _nodes[i].next;
        }
        _nodes[i].equivClass = classb;
        //combine two  lists
        _nodes[classb].size += _nodes[classa].size;
        _nodes[i].next = _nodes[classb].next;
        _nodes[classb].next = classa;
    }

    int find(int ele){
        return _nodes[ele + 1].equivClass;
    }
    size_t getClassNum(){
        return _classnum;
    }

private:
    vector<equivNode> _nodes;
    size_t _classnum;
};
#endif

class UnionFindTree
{
    vector<int> _parent;
    size_t _classNum;

public:
    UnionFindTree(int n) : _parent(n), _classNum(n)
    {
    }
    int find(int ele)
    {
//        ele++;
        int root = ele;
        while (_parent[root] != 0)
            root = _parent[root];
        //path compaction
        while (_parent[ele] != 0)
        {
            int a = _parent[ele];
            _parent[ele] = root;
            ele = a;
        }
        return root;
    }
    void uniteEle(int elea, int eleb)
    {
        uniteCLass(find(elea), find(eleb));
    }
    void uniteCLass(int classa, int classb)
    {
        if (classa == classb)
            return;
        _classNum--;
        _parent[classb] = classa;
    }
    size_t getClassNum()
    {
        return _classNum;
    }
};

#if 0
class equivClassTree{
public:
    struct equivNode{
        bool isRoot{true};
        int parent{1}; //if root is true, stand for the height of the tree, otherwise the parent node
    };

    equivClassTree(int n) : _nodes(n + 1), _classNum(n)
    {
    }
    int find(int ele){
        ele++;
        int root=ele;
        while (!_nodes[root].isRoot)
            root = _nodes[root].parent;
        //path compaction
        while (!_nodes[root].isRoot)
        {
            int a = _nodes[ele].parent;
            _nodes[ele].parent = root;
            ele = a;
        }
        return root;
    }
    void uniteEle(int elea,int eleb) 
    {
        uniteRoot(find(elea), find(eleb));
    }
    /**
     * @brief use tree height 
     * 
     * @param classa 
     * @param classb 
     */
    void uniteRoot(int roota,int rootb)
    {
        if (roota == rootb)
            return;
        _classNum--;
        if (_nodes[roota].parent > _nodes[rootb].parent)
        {
            _nodes[rootb] = {false, roota};
        }
        else
        {
            _nodes[roota] = {false, rootb};
        }
    }
    size_t getClassNum(){
        return _classNum;
    }

private:
    vector<equivNode> _nodes;
    size_t _classNum;
};
#endif