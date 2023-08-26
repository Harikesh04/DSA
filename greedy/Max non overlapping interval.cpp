#include<bits/stdc++.h>
using namespace std;

// ! #Problem:https://leetcode.com/problems/maximum-length-of-pair-chain/description/

// Approach

// have sorted pairs on basis of second element in inc order 
// iterate over all pairs and count required one

class Solution {
public:
    bool static cmp(vector<int>&a, vector<int>&b){
        if(a[1]<b[1]){// agr dusra ele chota h a ka b se toh return true;
            return true;
        }

        if(a[1]==b[1]){// agr dusra brabr h toh pehla bda chiye
            if(a[0]>=b[0]){
                return true;

            }

            return false;
        }

        return false;
    }
    int findLongestChain(vector<vector<int>>& pairs) {

        sort(pairs.begin(),pairs.end(),cmp);
        int cnt=0;

        int prev_last= INT_MIN; 

        for(auto &v: pairs){

            cout<<v[0]<<" "<<v[1]<<endl;
        }


        for(auto &v: pairs){
            if(v[0]>prev_last){
                cnt++;
                prev_last=v[1];
            }
            
        } 

        return cnt;


        
    }
};