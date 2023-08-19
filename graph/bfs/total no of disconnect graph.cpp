#include<bits/stdc++.h>
using namespace std;


//Problem:https://leetcode.com/problems/number-of-provinces/?envType=list&envId=ouaam7l1

class Solution {
public:


    void DFS(unordered_map<int,vector<int>>&adj,vector<bool>& vis,int u){
        vis[u]=true;

        for(auto v:adj[u]){
            if(vis[v]==false){

            DFS(adj,vis,v);
            }
        }
        return;
    }

    void BFS(unordered_map<int,vector<int>>&adj,vector<bool>& vis,int u){
        queue<int>q;
        q.push(u);
        vis[u]=true;

        while(q.empty()==false){
            int cur= q.front();
            q.pop();

            for(auto v:adj[cur]){
                if(vis[v]==false){
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {

        //we have to return total no. of disconnected graph

        int n= isConnected.size();

        unordered_map<int,vector<int>>adj;

       for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
               if(i==j)continue;

               if(isConnected[i][j]==1){
                   adj[i].push_back(j);
               }
           }
       }

        vector<bool>vis(n,false);
        int ans=0;

       for(int i=0;i<n;i++){
           if(vis[i]==false){
            //    DFS(adj,vis,i);
            BFS(adj,vis,i);
               ans++;
           }

       }

       return ans;

        
    }
};