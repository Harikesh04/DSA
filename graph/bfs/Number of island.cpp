#include<bits/stdc++.h>
using namespace std;

//Problem:https://leetcode.com/problems/number-of-islands/?envType=list&envId=ouaam7l1

class Solution {
public:

//Approach :

// here approach is simple .

// 1. why graph? => since we have to find number of islands for that we need to traverse all the nodes of an island and check each of the node that they are not connected to some other ilands therefore for traversal graph is the best approach.

// 2. Approach: first we will search 1 in the matrix when we found that we apply bfs on that node and will cover all the 1s which are adjacent to it (in the same ilands where 1 can reach or expands) and will mark them visited. 

// similarly when we'll got stuked up then our graph breaks and we will search for another not visited 1 and will do cnt++.

// finaly will return cnt.

    void bfs(vector<vector<char>>&grid,vector<vector<int>>&vis,int row, int col) {
        int n=grid.size();
        int m=grid[0].size();
        vis[row][col]=1;
        queue<pair<int,int>>q;
        q.push({row,col});
        vector<pair<int,int>>dirs={{1,0},{0,1},{-1,0},{0,-1}};
        while(q.empty()==false){
            auto [x,y] = q.front();
            q.pop();

            for(auto [dx,dy]:dirs){
                int i=x+dx;//row
                int j=y+dy;//col
                if(i>=0 && i<=n-1 && j>=0 && j<=m-1 && vis[i][j]==0 && grid[i][j]=='1'){
                    vis[i][j]=1;
                    q.push({i,j});

                }
            }

        }

    
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();//row
        int m=grid[0].size();//col
        vector<vector<int>>vis(n,vector<int>(m,0));

        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && vis[i][j]==0){
                  bfs(grid,vis,i,j);
                  cnt++;
                }

            }
        }

        return cnt;
        
    }
};