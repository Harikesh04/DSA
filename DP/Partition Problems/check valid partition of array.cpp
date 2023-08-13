#include <bits/stdc++.h>
using namespace std;


// Problem:https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/description/

// ! Approach: 
// Partition Dp approach giving tle due to of O(N^2 ) approach.



class Solution {
public:

int n =0;
vector<int>dp;




    // vector<vector<int>>dp;
    // bool solve(vector<int>& nums, int i, int j) {
    //     if (j - i + 1 == 2) {
    //         return nums[j] == nums[i];
    //     }



    //     if (j - i + 1 == 3) {
    //         // Two cases possible
    //         bool equalCase = true;
    //         bool incrementingCase = true;

    //         for (int k = i + 1; k <= j; k++) {
    //             if (nums[k] != nums[k - 1]) {
    //                 equalCase = false;
    //             }

    //             if (nums[k] - nums[k - 1] != 1) {
    //                 incrementingCase = false;
    //             }
    //         }

    //         return equalCase || incrementingCase;
    //     }

    //     if(dp[i][j]!=-1)return dp[i][j];

    //     bool res = false;
    //     for (int cut = i; cut < j; cut++) {
    //         bool ans = solve(nums, i, cut) && solve(nums, cut + 1, j);
    //         res = res || ans;
    //     }

    //     return dp[i][j]= res;
    // }

    // bool validPartition(vector<int>& nums) {
    //     dp.resize(nums.size()+1,vector<int>(nums.size()+1,-1));
    //     return solve(nums, 0, nums.size() - 1);
    // }


    bool solve(vector<int>&nums,int i){
        //bc
        if(i >= n)
            return true;


        if(dp[i]!=-1)return dp[i];



        bool result = false;
        
        if(i+1 < n && nums[i] == nums[i+1])
            result |= solve(nums, i+2);
        
        if(i+2 < n && nums[i] == nums[i+1] && nums[i+1] == nums[i+2])
            result |= solve(nums, i+3);
        
        if(i+2 < n && nums[i+1] - nums[i] == 1 && nums[i+2] - nums[i+1] == 1)
            result |= solve(nums, i+3);


        return dp[i]= result;

       
    }



     bool validPartition(vector<int>& nums) {
         n=nums.size();

         dp.resize(n+1,-1);

       
        return solve(nums, 0);
    }
};
