#include<bits/stdc++.h>
using namespace std;

//Problem:https://leetcode.com/problems/combinations/?envType=list&envId=r2zzj5c3

class Solution {
public: 

// jb bhi combination print krwane bole , ya permutation tb backtraking hi lgta h mostly

// khandani code

// yek baari le k explore kr lo 

// yek baari nhi le k explore kr lo


void solve(int n , int k, int i, vector<int>&temp,vector<vector<int>>&ans){
    //bc

    if(k==0){
        ans.push_back(temp);
        return ;
    }

    if(i>n)return ;

    // yek baari le lenge
    temp.push_back(i);
    solve(n,k-1,i+1,temp,ans);

    // ye baari nhi lenge

    temp.pop_back();
    solve(n,k,i+1,temp,ans);

}



vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>temp;

        solve(n,k,1,temp,ans);

        return ans;
        
    }


    // void func(int n, int k,int start,vector<int>&cur, vector<vector<int>>&ans){
    //     if(cur.size()==k){
           
    //         ans.push_back(cur);
    //         return;

    //     }

    //     for(int i=start;i<=n;i++){// i will start from greater than cur start so that we will get pair acc to out put req in increasing order
            
    //         //accept
    //         cur.push_back(i);
    //         func(n,k,i+1, cur, ans);
    //         //reject
    //         cur.pop_back();
             
            
    //     }
    // }
    // vector<vector<int>> combine(int n, int k) {
    //     vector<vector<int>>ans;
    //     vector<int>cur;

    //     func(n,k,1,cur,ans);

    //     return ans;
        
    // }
};