#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int>dp(n+1,1);
        vector<int>cnt(n+1,1);

        int ans =0;

        int longest_lis=0;
        

        for(int i =0;i<n;i++){
            for(int prev =0;prev<i;prev++){
                if(nums[i]>nums[prev]&& dp[i]<dp[prev]+1){
                    //jb dp[cur] m value greater milegi tb cnt same rkhenge kyu?
                    // kyu abhi voi subseq m add on ho rha h
                    dp[i]=dp[prev]+1;
                    cnt[i]=cnt[prev];
                }else if(nums[i]>nums[prev] && dp[i]==dp[prev]+1){

                    //jb dp[cur] m value same milegi tb cnt +1 kr denge.kyu?
                    // kyuki ab same size ka new sub seq mil rha h
                     cnt[i]+=cnt[prev];
                }
                
            }
            longest_lis=max(longest_lis,dp[i]);
            
           
        }

        // jitne bhi lis state h us index p cnt state ki value ko add on krenge ans m

        for(int i=0;i<n;i++){
            if(dp[i]==longest_lis){
                ans+=cnt[i];
            }
        }



       return ans;
       
        

        
        
    }
};