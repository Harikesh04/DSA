#include <bits/stdc++.h>
using namespace std;


// Problem:https://leetcode.com/problems/minimum-cost-to-cut-a-stick/description/?envType=list&envId=rwkgex9g


// ! Approach 

// here since we have to do partition therefore its a partition dp problem

// here we sort the cuts so that each cut will be independently work and we will get the min ans

// inserted 0 at begining and n at end to find the length of each stick where we are putting cuts


#include<bits/stdc++.h>
class Solution {
public:



    vector<vector<int>>dp;
    int solve(vector<int>&cuts,int i , int j){
        //bc
        if(i>j)return 0;

        if(dp[i][j]!=-1)return dp[i][j];

        int mini=INT_MAX;
        for(int ind=i;ind<=j;ind++){
            int cost = cuts[j+1]-cuts[i-1] + solve(cuts,i,ind-1)+solve(cuts,ind+1,j) ;// adding the length of curr string + cost for left partition + cost of right partition
            mini=min(cost,mini);
        }


        return dp[i][j]= mini;

       
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        

        cuts.insert(cuts.begin(),0);

        sort(cuts.begin(),cuts.end());
        dp.resize(cuts.size()+1,vector<int>(cuts.size()+1,-1));

        

        int ans = solve(cuts,1,cuts.size()-2);

        return ans;

       
        
    }
};