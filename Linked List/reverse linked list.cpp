
#include<bits/stdc++.h>
using namespace std;

//Problem : https://leetcode.com/problems/reverse-linked-list/?envType=list&envId=o6d5chd7

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
    ListNode* reverseList(ListNode* head) {

        ListNode *prev =  NULL , *curr = head;

       

        while(curr != NULL){
           ListNode  *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr= next;

        }

        return prev;


        
    }
};