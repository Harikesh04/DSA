#include<bits/stdc++.h>
using namespace std;



// ? Problem:https://leetcode.com/problems/course-schedule/?envType=list&envId=rwel0z55


class Solution {
public:

// !Approach : here if see problem carefully then we will find out that , if there is cycle then ans is false else true;

// since its a directed graph problem , how directed graph ?

// since we have to go for b first then a . there fore directed 

// to detect cycle in directed , topological sort.





    bool canFinish(int n, vector<vector<int>>& prerequisites) {

        unordered_map<int,vector<int>>adj;

        for(auto vec: prerequisites){
            int u=vec[1];
            int v=vec[0];

            adj[u].push_back(v);
           
        }

        vector<int>indegree(n,0);

        for(int u=0;u<n;u++){
            for(auto v:adj[u]){
                indegree[v]++;
            }

        }
        queue<int>q;
         int cnt=0;


        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                
                q.push(i);
                cnt++;
                
                }
        }
       

        while(q.empty()==false){
            int u=q.front();
            q.pop();

            for(auto v:adj[u]){
                indegree[v]--;

                if(indegree[v]==0){
                    q.push(v);
                    cnt++;
                    }
            }

        }

       if(cnt==n)return true;// mtlb m saare node visit kr paya , yani no cycle

       return false;// visit nii kr paya, yani cycle thi




        
    }
};