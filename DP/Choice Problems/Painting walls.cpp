#include<bits/stdc++.h>
using namespace std;


// ! #Problem:https://leetcode.com/problems/painting-the-walls/description/


// greedy (fail)

// class Solution {
// public:

//     bool static cmp(pair<int,int>a,pair<int,int>b){

//         if(a.first==b.first){
//             return a.second>b.second;
//         }

//         return a.first<=b.first;// if cost is less

        
        
//     }
//     int paintWalls(vector<int>& cost, vector<int>& time) {

//         vector<pair<int,int>>vp;

//         for( int i=0;i<cost.size();i++){
//             vp.push_back({cost[i],time[i]});


//         }

//         sort(vp.begin(),vp.end(),cmp);

//         int n = cost.size();

//         long long ans =0;


//         for(int i=0;i<n;i++){

//             ans+=vp[i].first;

//             n-=vp[i].second;

//         }

//         return ans;
        
//     }
// };


// greedy will not work

// eg for test case

// cost: 3 1 1 1 1 1 1 1
// time: 7 1 1 1 1 1 1 1


//! Approach: ya toh paid painter paint krega ya nii krega
// if he will paint then cost include kr lo and remainging wall = wallRemaining -1 - time[i];
// ? here we have done -1 -time[i] because jitni der m voh paint krega utni der m free wala painter utni wall paint kr dega , -1 for usne jo wall paint kri .


class Solution {
public:

  vector<vector<int>>dp;

    long long solve(int ind , int wallRemaining,vector<int>&cost,vector<int>&time){

        //bc

        if(wallRemaining<=0)return 0;

        if(ind>=cost.size())return INT_MAX;// because this is useless so INT_MAX 

        if(dp[ind][wallRemaining]!=-1)return dp[ind][wallRemaining];


        long long paint = cost[ind]+ solve(ind+1,wallRemaining-1-time[ind],cost,time);

        long long donot_paint = solve(ind+1,wallRemaining,cost,time);


        return dp[ind][wallRemaining] =min(paint,donot_paint);

    }


    int paintWalls(vector<int>& cost, vector<int>& time) {
        long long  n = cost.size();

        dp.resize(n+1,vector<int>(n+1,-1));
        long long ans = solve(0,n,cost,time);

        return ans;
        
    }
};
