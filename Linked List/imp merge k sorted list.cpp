#include<bits/stdc++.h>
using namespace std;


// Problem : https://leetcode.com/problems/merge-k-sorted-lists/?envType=list&envId=o6d5chd7
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

//STORY: here we know how to merge two sorted lists

//now we will recursively break so many lists into 2 parts and will merge them.

    ListNode* mergeTwoSortedLists(ListNode*  list1, ListNode* list2){
        // here we always get head 
        if(list1==NULL)return list2;
        if(list2==NULL)return list1;

        if(list1->val<=list2->val){//jiska first ele chota h usko res m rkhlo bakki recursion se merge krwa do.
            list1->next= mergeTwoSortedLists(list1->next,list2);
            return list1;

        }else{
            list2->next= mergeTwoSortedLists(list2->next,list1);
            return list2;
        }

        return NULL;
    }

    ListNode* partitionAndMerge(int start,int end ,vector<ListNode*>& lists){
        if(start==end)return lists[start];
        if(start>end)return NULL;

        int mid = (start + end)/2;

        ListNode* l1 = partitionAndMerge(start,mid,lists);
        ListNode* l2= partitionAndMerge(mid+1,end,lists);

        return mergeTwoSortedLists(l1,l2);

    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)return NULL;

        return partitionAndMerge(0,lists.size()-1,lists);

       
        
    }
};