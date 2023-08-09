#include <bits/stdc++.h>
using namespace std;

// Problem:https://leetcode.com/problems/maximum-product-subarray/?envType=list&envId=odt08246


class Solution {
public:
    int maxProduct(vector<int>& nums) {

        //important question

        //perception to solve the problem: wether our ans will be a subarray starting from 0th ind to some ith ind else from n-1th ind to some ith index

        // whenever we find any 0 we will make our cur prod 1 for considering upcoming windows

        int mxProd =INT_MIN;
        int curProd =1;

//checking from begining
        for(int i=0;i<nums.size();i++){
            curProd = curProd*nums[i];
            mxProd = max(mxProd,curProd);
            if(curProd==0)curProd =1;
        }

        curProd =1;

        //checking from end

        for(int i=nums.size()-1;i>=0;i--){
              curProd = curProd*nums[i];
            mxProd = max(mxProd,curProd);
            if(curProd==0)curProd =1;

        }

        return mxProd;
        
    }
};