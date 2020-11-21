/*
Given the head of a linked list, return the list after sorting it in ascending order.

Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?

 

Example 1:

Input: head = [4,2,1,3]
Output: [1,2,3,4]

Example 2:

Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]

Example 3:

Input: head = []
Output: []

 

Constraints:

    The number of nodes in the list is in the range [0, 5 * 104].
    -105 <= Node.val <= 105

*/
#include"common.h"

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
class Solution {
public:
//merge
    ListNode* sortList(ListNode* head) {
        if(head==nullptr||head->next==nullptr)return head;
        ListNode* fast=head->next,*slow=head;
        while(fast&&fast->next){
           fast=fast->next->next;
           slow=slow->next;
        }
        ListNode* head2=slow->next;
        slow->next=nullptr;
        ListNode* sorted1=sortList(head);
        ListNode* sorted2=sortList(head2);
        //merge two list
        ListNode* dummy=new ListNode();
        ListNode* ret=dummy;
        while(sorted1&&sorted2){
            if(sorted1->val<sorted2->val){
                ret->next=sorted1;
                sorted1=sorted1->next;
            }else{
                ret->next=sorted2;
                sorted2=sorted2->next;
            }
            ret=ret->next;
        }
        if(sorted1)ret->next=sorted1;
        else if(sorted2)ret->next=sorted2;
        ret=dummy->next;
        delete dummy;
        return ret;
    }
};
int main(){
    int arr[]={4,5,6,4,3,2,4,2,1,23,4,6,8,0,6,4,-23,2,-2,-2,-1,0};
//int arr[]={-1,5,3,4,0};
//    int arr[]={4,5,6,4,3,2};
//int arr[] = {4, 2, 1, 3};
ListNode *head = buildList(arr, sizeof arr / sizeof arr[0]);
Solution s;
ListNode *res = s.sortList(head);
printList(res);

}
