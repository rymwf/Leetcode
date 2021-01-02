/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

Example:

Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5
*/
#include "common.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *cur2 = dummy;
        while (cur2->next != nullptr && cur2->next->val >= x)
            cur2 = cur2->next;
        head = cur2->next;
        if (!head)
        {
            head = dummy->next;
            delete dummy;
            return head;
        }
        ListNode *cur = cur2;
        while (cur->next != nullptr)
        {
            if (cur->next->val >= x)
            {
                cur2->next = cur->next;
                cur2 = cur2->next;
                cur->next = cur->next->next;
            }
            else
                cur = cur->next;
        }
        cur2->next = nullptr;
        cur->next = dummy->next;
        delete dummy;
        return head;
    }
    ListNode *partition2(ListNode *head, int x)
    {
        ListNode *small = new ListNode(0);
        ListNode *large = new ListNode(0);
        ListNode *cur = head;
        ListNode *smallcur = small;
        ListNode *largecur = large;
        while (cur)
        {
            if (cur->val >= x)
            {
                largecur->next = cur;
                largecur = largecur->next;
            }
            else
            {
                smallcur->next = cur;
                smallcur = smallcur->next;
            }
            cur = cur->next;
        }
        smallcur->next = large->next;
        largecur->next = nullptr;
        head = small->next;
        delete small;
        delete large;
        return head;
    }
};
int main()
{
    int a[] = {2, 3, 1};
    ListNode *head = buildList(a, sizeof a / sizeof a[0]);
    Solution s;
    s.partition2(head, 3);
}