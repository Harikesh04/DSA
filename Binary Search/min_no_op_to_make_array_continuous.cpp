#include<bits/stdc++.h>
using namespace std;

// Problem:https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/

// ! Approach:

// ? yha p apn each element ko min lenge aur nums[i]+n-1 se range nikalege [nums[i],nums[i]+n-1], fir loop chalenge agr ele is range m lie nii krega ya repeated hoga toh cnt ++ krenge , jo min ans aayega voi apna ans hoga





class Solution {
public:

// Brute force

// int minOperations(vector<int>& nums) {
//         int n = nums.size();
        
//         int result = INT_MAX;
        
//         for(int i = 0; i < n; i++) {
            
//             int left_range  = nums[i]; //L
//             int right_range = left_range + n - 1;
            
//             int mehnat = 0;
            
//             unordered_set<int> used;
            
//             for(int j = 0; j < n; j++) {
                
//                 if(nums[j] >= left_range && nums[j] <= right_range && used.find(nums[j]) == used.end()) {
//                     used.insert(nums[j]);
//                     continue;
//                 } else {
//                     mehnat++;
//                 }
                
//             }
            
//             result = min(result, mehnat);
            
//         }
        
//         return result;
//     }
int minOperations(vector<int>& nums) {
        int n = nums.size();
        
        set<int> st(begin(nums), end(nums));
        
        vector<int> temp(begin(st), end(st));
        
        int result = INT_MAX;
        
        for(int i = 0; i<temp.size(); i++) {
            
            int left_range  = temp[i];
            int right_range = left_range + n - 1;
            
            int j = upper_bound(begin(temp), end(temp), right_range) - begin(temp);
            // ! from this getting index of element just greater then  right_range 
            
            int in_range  = j - i;// total number of elements jo ki range m h
            int out_range = n - in_range; // jo bhi bache hue h voh out of range h
            
            result = min(result, out_range);// storing min result
            
        }
        
        return result;
    }
};