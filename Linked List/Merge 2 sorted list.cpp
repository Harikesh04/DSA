#include<bits/stdc++.h>
using namespace std;


// ! Same with array problem 
// Problem: https://leetcode.com/problems/merge-two-sorted-lists/?envType=list&envId=o6d5chd7

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

// Recursive Approach:-

    // ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

    //     if(l1==NULL)return l2;
    //     if(l2==NULL)return l1;

    //     if(l1->val<=l2->val){
    //         l1->next=mergeTwoLists(l1->next,l2);
    //         return l1;
    //     }else{
    //        l2->next=mergeTwoLists(l2->next,l1);
    //         return l2;
    //     }
        



        
    // }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        if(l1==NULL)return l2;
        if(l2==NULL)return l1;

        ListNode* ans = new ListNode();
        ListNode* ptr = ans;

        while(l1!=NULL && l2!=NULL){
            if(l1->val<=l2->val){
                ptr->next = new ListNode(l1->val);
                ptr=ptr->next;
                 l1=l1->next;
                
            }else{
                 ptr->next = new ListNode(l2->val);
                ptr=ptr->next;
                 l2=l2->next;

            }

        }


        while(l1!=NULL){
            ptr->next = new ListNode(l1->val);
                ptr=ptr->next;
                l1=l1->next;

            
        }
        while(l2!=NULL){
            ptr->next = new ListNode(l2->val);
                ptr=ptr->next;
                 l2=l2->next;

        }


        return ans->next;



        
    }
};