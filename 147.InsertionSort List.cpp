/*
Sort a linked list using insertion sort.


A graphical example of insertion sort. The partial sorted list (black) initially contains only the first element in the list.
With each iteration one element (red) is removed from the input data and inserted in-place into the sorted list
 

Algorithm of Insertion Sort:

    Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list.
    At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there.
    It repeats until no input elements remain.


Example 1:

Input: 4->2->1->3
Output: 1->2->3->4

Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5
*/
#include"common.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr)return head;
        ListNode* dummy=new ListNode();
        dummy->next=head;
        ListNode* cur=dummy->next;
        while(true){
            while(cur->next!=nullptr&&cur->next->val>=cur->val)cur=cur->next;
            if(cur->next==nullptr)break;
            ListNode *pre = dummy;
            while (pre->next->val <= cur->next->val)pre = pre->next;
            ListNode *temp = cur->next;
            cur->next = cur->next->next;
            temp->next = pre->next;
            pre->next = temp;
        }
        return dummy->next;
    }
};

int main(){
    int a[]={4,3,2,5,1,0};
    ListNode* b=buildList(a,sizeof a/sizeof a[0]);
    printList(b);
    Solution s;
    auto res=s.insertionSortList(b);
    printf("\n");
    printList(res);
}