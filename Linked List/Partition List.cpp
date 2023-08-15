#include<bits/stdc++.h>
using namespace std;


// Problem:https://leetcode.com/problems/partition-list/description/


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

// ! Approach:

// created 2 new list one for lessthanX and one for greater than or equal to X;
// ptr1 pointing to head of lessthanX and ptr2 pointing to head of greaterThanEqualList

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {


        ListNode* temp = head;
        ListNode* lessThanXList = new ListNode();// this is a list with one node with 0 value
        ListNode* ptr1 = lessThanXList;
        ListNode* greaterThanEqualList = new ListNode();// this is a list with one node with 0 value
        ListNode* ptr2 = greaterThanEqualList;


        // ? since we want to insert element after 0 that is why we adding new Node in next
       

        while(temp!=NULL){
            if(temp->val<x){
                ptr1->next = new ListNode(temp->val);
                ptr1=ptr1->next;
                


            }else{
                ptr2->next = new ListNode(temp->val);
                ptr2=ptr2->next;

            }

            temp=temp->next;

        }
          ptr1->next = greaterThanEqualList->next;

    return lessThanXList->next; // ? returning next is important because if we return lessThanXList then one initial empty value will also return  
        
    }

  
};