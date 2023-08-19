#include<bits/stdc++.h>
using namespace std;

//Problem:https://leetcode.com/problems/maximum-number-of-achievable-transfer-requests/?envType=list&envId=r2zzj5c3


// Approach:

// ? yek baari le ke explore kro , yek baari mt le ke explore kro

class Solution {
public:

    int ans = 0;
    void solve(vector<vector<int>>& req,int n, vector<int>&build,int ind,int count){
        
        //bc
        if(ind==req.size()){
           
            for(int i=0;i<n;i++){
                if(build[i]!=0)return;

            }
            ans=max(ans,count);
            return;

        }


        int lo = req[ind][0];
        int hi = req[ind][1];

        build[lo]++;
        build[hi]--;
        solve(req,n,build,ind+1,count+1);
        build[lo]--;
        build[hi]++;
         solve(req,n,build,ind+1,count);

       

    }
    int maximumRequests(int n, vector<vector<int>>& req) {

        vector<int>build(n,0);

        solve(req,n,build,0,0);
        return ans;

        
    }
};