#include<bits/stdc++.h>
using namespace std;

//  ? How to find its a backtraking problem 

// ! when ever in question all possible combination, permutation,combination,print all possible way

// ! then backtracking confirm

//Problem:https://leetcode.com/problems/permutations/?envType=list&envId=r2zzj5c3

class Solution {
public:
// Approach :

// when ever All possible / permutation/combinations/subsets (backtracking confirm)

// here khandani code will not work because if le ke explore kr fir mt le explore kr 

// ni lene k baad index to aage badh jayega then how we will get ignored element.
    vector<vector<int>>ans;

    // void solve(vector<int>&cur, int i , vector<int>&nums){
    //     //bc

    //     if(cur.size()==nums.size()){
    //         ans.push_back(cur);
    //     }

    //     if(i>=nums.size())return;


    //     cur.push_back(nums[i]);// le lo
    //     solve(cur,i+1,nums);

    //     cur.pop_back();// mt lo
    //     solve(cur,i+1,nums);
    // }


    // tc: O(n!)

    void solve(vector<int>&cur,vector<bool>&vis,vector<int>&nums){
        //bc

        if(cur.size()==nums.size()){
            ans.push_back(cur);
            return;
        }

        // this is always best approach to use for loop for recursive problem
        // here we have to revisit to the indexes to whom we have rejected
        for(int i=0;i<nums.size();i++){
            if(vis[i]==false){

                cur.push_back(nums[i]);// accept kr lo
                vis[i]=true;
                solve(cur,vis,nums);


                cur.pop_back();// reject kr do
                vis[i]=false;
               

            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<int>cur;
        vector<bool>vis(nums.size(),false);

        solve(cur,vis,nums);


        return ans;

       
    }
};