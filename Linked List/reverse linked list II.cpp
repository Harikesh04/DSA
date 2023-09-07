#include<bits/stdc++.h>
using namespace std;


//Problem: https://leetcode.com/problems/reverse-linked-list-ii/description/

// ! Approach : here we have to reverse a linked list from left to right and rest should be same.

// here we have created dummy node because we need to point on head , because head value could also be changes if left =1 . so to point left we created dummy node .

// prev : if will be node before left

// after that we will change the links of the linked list right-left times using diagram and our list will be reversed.



class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if(head==NULL || head->next==NULL){
            return head;
        }

        ListNode* dummy = new ListNode(-1);

        dummy->next = head;


        ListNode* prev = dummy;

        for(int i=1;i<left;i++){
            prev=prev->next;
        }

        ListNode* curr = prev->next;


       for(int i = 1; i<=right-left; i++) {
            
            ListNode* temp = prev->next; //0
            prev->next = curr->next; //1
            curr->next = curr->next->next; //2
            prev->next->next = temp; //3
            
        }
    
        return dummy->next;
        
    }
};