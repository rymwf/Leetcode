/*
Given a linked list, swap every two adjacent nodes and return its head.

You may not modify the values in the list's nodes. Only nodes itself may be changed.

 

Example 1:

Input: head = [1,2,3,4]
Output: [2,1,4,3]

Example 2:

Input: head = []
Output: []

Example 3:

Input: head = [1]
Output: [1]

 

Constraints:

    The number of nodes in the list is in the range [0, 100].
    0 <= Node.val <= 100
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
    ListNode *swapPairs(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *p0 = new ListNode, *p1 = head;
        p0->next = head;
        head = head->next;
        while (p1 != nullptr && p1->next != nullptr)
        {
            p0->next = p1->next;
            p0 = p1;
            p1 = p1->next->next;
            p0->next->next = p0;
            p0->next = p1;
        }
        return head;
    }
};

int main()
{
    int arr[] = {1, 2, 3, 4};
    ListNode *head = buildList(arr, 4);
    printList(head);
    Solution s;
    s.swapPairs(head);
    printf("\n");
    printList(head);
}