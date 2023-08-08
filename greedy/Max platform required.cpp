#include<bits/stdc++.h>
using namespace std;

// Problem:https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1




class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.


    // ! sorting on the basis of first element (first < second)
          
   bool static cmp(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first < b.first;
    }

    
    int maxMeetings(int start[], int end[], int n)
    {
       vector<pair<int,int>>vp;
       
      for(int i=0;i<n;i++){
          vp.push_back({start[i],end[i]});
      }
      
      sort(vp.begin(), vp.end(),cmp);
      
      int ans =1;
      
      int lastvis = vp[0].second;// assuming 1 interval as under consideration
      
     
      
      for(int i=1;i<n;i++){
          if(vp[i].first>lastvis){// if current interval ka start prev interval k end se bda h yani koi dikkat nii consider kr lo
              ans++;
              lastvis=vp[i].second; // updating last vis
          }else if(vp[i].first < lastvis && vp[i].second<lastvis){ // agr koi aaisa interval mila jiska start purane end se chota h and end bhi chota h toh apn apne purane vaale interval ko chod denge isko lastvis kr denge
             
              lastvis= vp[i].second;
              
              
          }
          
          
          
      }
      
      
      
      return max(ans,1);
    }
  
};