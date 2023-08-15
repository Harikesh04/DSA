#include<bits/stdc++.h>
using namespace std;

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
    ListNode *detectCycle(ListNode *head) {

        //naive:
        // unordered_set<ListNode*>st;
        // ListNode* cur = head;

        // while(cur!=NULL){
        //     if(st.count(cur)){
        //         return cur;
        //     }else{
        //         st.insert(cur);
        //         cur=cur->next;
        //     }

        // }

        // return NULL;


        //Optimised:

        ListNode *curr=head,*slow=head,*fast=head;

        if(head==NULL)return NULL;

        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;

            if(slow==fast){//meeting point
                while(curr!=fast){
                    curr=curr->next;
                    fast=fast->next;
                }

                return curr;// we can also return fast

            }
        }

        return NULL;
        
    }
};