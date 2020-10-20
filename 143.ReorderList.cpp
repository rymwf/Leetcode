/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example 1:

Given 1->2->3->4, reorder it to 1->4->2->3.

Example 2:

Given 1->2->3->4->5, reorder it to 1->5->2->4->3.

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
    void reorderList(ListNode* head) {
        if(head==nullptr)return;
        vector<ListNode*> vec;
        vec.emplace_back(head);
        while(vec.back()->next!=nullptr){
            vec.emplace_back(vec.back()->next);
        }
        int l=0,r=vec.size()-1;
        while(l<r){
            vec[r]->next=vec[l]->next;
            vec[l]->next=vec[r];
            r--;
            l++;
        }
        if(l==r)vec[r]->next=nullptr;
        else vec[l]->next=nullptr;
    }
};
int main(){
    int arr[]={1,2,3,4,5};
    ListNode* head=buildList(arr,sizeof arr/sizeof arr[0]); 
    printList(head);
    Solution s;
    s.reorderList(head);
    printList(head);

}



