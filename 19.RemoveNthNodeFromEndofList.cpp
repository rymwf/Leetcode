/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.

Follow up: Could you do this in one pass?

 

Example 1:

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:

Input: head = [1], n = 1
Output: []

Example 3:

Input: head = [1,2], n = 1
Output: [1]

 

Constraints:

    The number of nodes in the list is sz.
    1 <= sz <= 30
    0 <= Node.val <= 100
    1 <= n <= sz
*/
#include "common.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head == nullptr || n == 0)
            return head;
        ListNode *p0 = head, *p1 = head;
        while (n-- > 0)
            p1 = p1->next;
        if (p1 == nullptr)
            return head->next;
        p1 = p1->next;
        while (p1 != nullptr)
        {
            p1 = p1->next;
            p0 = p0->next;
        }
        p0->next = p0->next->next;
        return head;
    }
};
