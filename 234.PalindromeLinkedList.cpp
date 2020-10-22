/*
Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false

Example 2:

Input: 1->2->2->1
Output: true

Follow up:
Could you do it in O(n) time and O(1) space?

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
    bool isPalindrome(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return true;
        int n = 0;
        ListNode *p = head;
        while (p != nullptr)
        {
            n++;
            p = p->next;
        }
        int n2 = n / 2;
        p = nullptr;
        ListNode *p1 = head;
        ListNode *p2 = head->next;
        while (n2-- > 0)
        {
            p1->next = p;
            p = p1;
            p1 = p2;
            p2 = p2->next;
        }
        if (n % 2 == 1)
            p1 = p1->next;
        while (p)
        {
            if (p->val != p1->val)
                return false;
            p = p->next;
            p1 = p1->next;
        }
        return true;
    }
};

int main()
{
    int arr[] = {1, 2, 3, 4, 3, 3, 2, 1};
    ListNode *head = buildList(arr, sizeof arr / sizeof arr[0]);
    printList(head);
    Solution s;
    bool a = s.isPalindrome(head);
    printf("\n%d", a);
}