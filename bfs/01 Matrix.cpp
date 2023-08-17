#include<bits/stdc++.h>
using namespace std;


//Problem:https://leetcode.com/problems/01-matrix/description/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        vector<vector<int>> ans(row, vector<int>(col, -1));
        
        queue<pair<int, int>> q;
        
        // Enqueue all zero cells and mark them as visited
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    ans[i][j] = 0;
                }
            }
        }
        
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            
            for (auto dir : dirs) {
                int newX = curr.first + dir.first;// new row
                int newY = curr.second + dir.second;// new col
                
                if (newX >= 0 && newX < row && newY >= 0 && newY < col && ans[newX][newY] == -1) {
                    ans[newX][newY] = ans[curr.first][curr.second] + 1;
                    q.push({newX, newY});
                }
            }
        }
        
        return ans;
    }
};
