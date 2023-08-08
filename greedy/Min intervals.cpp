#include<bits/stdc++.h>
using namespace std;

// Problem:https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#


// Approach :

// 1. sorting on basis of smaller first element

class Solution{
    public:
    
    
    bool static cmp(pair<int,int>&a,pair<int,int>&b){
        if(a.first==b.first){
            
            return a.second<b.second;
            
        }
        return a.first<b.first;
    }
    
    int findPlatform(int arr[], int dep[], int n)
    {
       vector<pair<int,int>>vp;
       
       for(int i=0;i<n;i++){
           vp.push_back({arr[i],dep[i]});
       }
       
       sort(vp.begin(),vp.end(),cmp);
       
      priority_queue <int, vector<int>, greater<int> > pq;// min heap
        int curr = 0;
        int res = 0;
        for(int i =0;i<n;i++){
            while(!pq.empty() && pq.top()<vp[i].first){
                curr--;
                pq.pop();
            }
            curr++;
            res = max(res, curr);
            pq.push(vp[i].second);
        }
        return res;
       
         
       
       
    }
};