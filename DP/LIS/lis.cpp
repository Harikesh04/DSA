#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

// ! Approach

//Recurrence

// 1. think every thing in form of indexes , curr , since we can choose curr on basis of some previous index

// therefore currInd, prevInd

// 2. take(when prev is smaller or there is no previous)  or not take (always have option to not take)



int solve(int currInd, int prevInd, vector<int>&nums , vector<vector<int>>&dp){
    //bc

    if(currInd==nums.size())return 0;

 
if(dp[currInd][prevInd+1]!=-1)return dp[currInd][prevInd+1];
// here have taken prevInd +1 bcz to prevent runtime error due of -1 of the prevInd.
 
    


    int op1 = solve(currInd+1,prevInd,nums,dp);
    int op2 =0;

    if(prevInd==-1 || nums[prevInd]<nums[currInd]){
        op2 = solve(currInd+1,currInd,nums,dp)+1;

    }

    return dp[currInd][prevInd+1] = max(op1,op2);
    

}

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    int ans = solve(0,-1,nums,dp);
    return ans;



}

    // int lengthOfLIS(vector<int>& nums) {
        
        //state: dp[i]: length of longest increasing that ends at ith index

        //tc: O(N^2)

        // int n=nums.size();
        // vector<int>dp(n,1);
        // int ans=1;
        // dp[0]=1;
        

        // for(int i=1;i<n;i++){
        //     for(int j=0;j<=i;j++){
        //         if(nums[j]<nums[i]){
        //             dp[i]=max(dp[i],dp[j]+1);
                   
        //         }
        //     }
        //      ans=max(ans,dp[i]);

        // }

        // return ans;



        
};