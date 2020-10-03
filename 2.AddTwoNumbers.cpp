/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]

Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]

 

Constraints:

    The number of nodes in each linked list is in the range [1, 100].
    0 <= Node.val <= 9
    It is guaranteed that the list represents a number that does not have leading zeros.
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *p1 = l1;
        int a = 0;
        bool flag = false;
        while (true)
        {
            int b = 0;
            if (l2 == nullptr || flag)
                b = p1->val + a;
            else
                b = p1->val + l2->val + a;
            p1->val = b % 10;
            a = b / 10;
            if (p1->next == nullptr)
            {
                if (l2 != nullptr && l2->next != nullptr)
                {
                    flag = true;
                    p1->next = l2->next;
                }
                else
                    break;
            }
            p1 = p1->next;
            if (l2 != nullptr)
                l2 = l2->next;
        }
        if (a > 0)
            p1->next = new ListNode(a);
        return l1;
    }
};
