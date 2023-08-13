#include <bits/stdc++.h>
using namespace std;


// Problem:https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/description/


// ! Approach 




class Solution {
public:
    int n =0;
    vector<int>dp;
    int solve(vector<int>&arr,int k , int i){
        //bc
        if(i==n)return 0;

        int len=0;// it is imp to define len here as 0 because in beginning of every part form i to n the len is always 0

        // same with the mini and mx
        int maxi =INT_MIN;
         int mx=INT_MIN;

         if(dp[i]!=-1)return dp[i];
         

        for(int j=i;j<min(i+k,n);j++){

            len++;

             mx= max(mx,arr[j]);
              int ans = mx*len + solve(arr,k,j+1);

            maxi = max(ans,maxi);
           


        }

        return dp[i]= maxi;


        
    }


    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n=arr.size();

        dp.resize(n+1,-1);

        return solve(arr,k,0);
        
    }
};