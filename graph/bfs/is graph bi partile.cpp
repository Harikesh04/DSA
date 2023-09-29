#include<bits/stdc++.h>
using namespace std;

//Problem:https://leetcode.com/problems/is-graph-bipartite/?envType=list&envId=ouaam7l1

class Solution {
public:

    //bipartite graph : if in a graph we paint all the nodes with two different colour such that no adj node have same colour is called bipartite graph

    // if graph with odd length of cycle then no bi partite(2 adj node ka color same ho hi jayega i.e first and last)

    // if graph with even lenghth of cycle then bi partite

    // if graph with no cycle then bi partite

    bool bfs(vector<vector<int>>& graph,int src,vector<int>& colour){
        queue<int>q;
        q.push(src);
        colour[src]=1;

        while(q.empty()==false){

            int size = q.size();

            while(size--){
                auto node = q.front();
                q.pop();
                for(auto v:graph[node]){
                    if(colour[v]==-1){// if adj node is not colored
                        colour[v]= 1-colour[node];//giving colour alter of the curr color of the node
                        q.push(v);//pushing the vertex in the queue
                    }
                    else if(colour[v]==colour[node])return false;//if adj node of cur node have similar colour then it is not bipartite 
                }
          

            }
            
                
        }
        return true;

    }
    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();

        vector<int>colour(n,-1);//instead of vis array i have maintained color arr where -1 represents that not coloured

        for(int i=0;i<n;i++){
            if(colour[i]==-1){
            if(bfs(graph,i,colour)==false){
                return false;
            }
            }
           
        }
        return true;
        
    }
};