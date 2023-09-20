#include<bits/stdc++.h>
using namespace std;


// #problem:https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/description/

// ? will give tle due to O(n^2)
// class Solution {
// public:

//     vector<vector<int>>dp;
//     int solve(int i , int j , int x,vector<int>&nums){
//         //bc

//         if(x==0)return 0;

//          if (i <= j && nums[i] > x && nums[j] > x) {
//             return -1;
//         }


//         if (i < 0 || j < 0 || i >= nums.size() || j >= nums.size()) {
//             return -1;
//         }

//         if(dp[i][j]!=-1)return dp[i][j];


//         // do option h

//        int op1 = (i < nums.size()) ? solve(i + 1, j, x - nums[i], nums) : -1;
//         int op2 = (j >= 0) ? solve(i, j - 1, x - nums[j], nums) : -1;

//         // Check if both options are invalid
//         if (op1 == -1 && op2 == -1) {
//             return dp[i][j]= -1;
//         } else if (op1 == -1) {
//             return dp[i][j]= op2 + 1;
//         } else if (op2 == -1) {
//             return dp[i][j]= op1 + 1;
//         } else {
//             return dp[i][j]= min(op1, op2) + 1;
//         }
//     }
//     int minOperations(vector<int>& nums, int x) {

//         int sum = 0;

//         for(auto it: nums){
//             sum+=it;
//         }

//         if(sum<x)return -1;

//         dp.resize(nums.size(),vector<int>(nums.size(),-1));

//         int ans = solve(0,nums.size()-1,x,nums);

//         return ans;
        
//     }
// };


// ? Approach: yha p apn nikal rhe h ki max length of subarray of size sum-k
// ? kyuki apna asli answer n-(calculated length) hi h
// ? kyuki right and left k delete krte krte bich m voh subarray hi bachegi
// ? aur ye approach automatically hi optimistic h O(N);
class Solution{

    public:

     int minOperations(vector<int>& nums, int x) {
         int sum=0,n=nums.size();

         for(auto &it: nums){
             sum+=it;
         }

         if(sum<x)return -1;

         
         if(sum==x)return nums.size();

        int target = sum-x;

        // now we want the length of longest subarray having sum = target

        int res =0;

        int head=0,tail=0;

        int cur_sum=0;

        for(head;head<n;head++){

            cur_sum+=nums[head];

            // agr condition break ho tb

            while(cur_sum>target){
                cur_sum-=nums[tail];
                tail++;
            }

            if(cur_sum==target){
                res=max(res,head-tail+1);
            }

        }

        if(res==0)return -1;




        return nums.size()-res;




     }


};

