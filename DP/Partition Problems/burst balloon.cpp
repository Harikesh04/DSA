#include <bits/stdc++.h>
using namespace std;


// Problem:https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/description/


// ! Approach 


// Since here order is important and we can do partition in left side and right side there for mcm confirm

// here if we try to implement mcm from top like from multiple ballon brust any one then it will not work because right subproblem will be dependent on left and viseversa.

// therefore we will begin from last that is when a single ballon left and go bottom -> up.





class Solution {
public:




    vector<vector<int>>dp;

    int solve(vector<int>&nums,int i, int j){
        // bc

        if(i>j)return 0;

        if(dp[i][j]!=-1)return dp[i][j];

        int maxi=INT_MIN;

        for(int burst=i;burst<=j;burst++){
            int coins = solve(nums,i,burst-1)+solve(nums,burst+1,j)+(nums[i-1]*nums[burst]*nums[j+1]);

            maxi=max(maxi,coins);

        }

        return  dp[i][j] =maxi;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        nums.insert(nums.begin(),1);

        nums.push_back(1);

        dp.resize(n+1,vector<int>(n+1,-1));


       int ans = solve(nums,1,n);

       return ans;
        
    }
};