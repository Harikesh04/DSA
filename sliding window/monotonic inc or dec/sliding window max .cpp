#include<bits/stdc++.h>
using namespace std;

//Problem:https://leetcode.com/problems/sliding-window-maximum/description/


class Solution {
   
public:

// this ques uses a famous pattern of monotonic dequeu / queue

// step1: when new element comes make space for it (window space can't be greater then k)
// step2: when nums[i] comes no need to keep smaller element than that in the window (because we are never going to use it)
// step3: now push i in deque
// step4: when i>=k-1 then deq.front() is ans for that window


    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
         deque<int> deq;

        vector<int> result;

        // here we are storing index of elements in deque
        
        for(int i = 0; i<n; i++) {
            //remove the max elements from front which are out of window size
            while(!deq.empty() && deq.front() <= i-k)
                deq.pop_front();
            
            //we maintain the deque in descending order
            while(!deq.empty() && nums[i] > nums[deq.back()])
                deq.pop_back();
            
            deq.push_back(i);

            if(i >= k-1) //Only when the window size first gets equal or greater than k
                result.push_back(nums[deq.front()]); //front will have the max element (dequeue is maintained in descending order)
        }
        return result;
    }
};