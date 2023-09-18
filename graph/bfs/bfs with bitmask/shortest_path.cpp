#include<bits/stdc++.h>
using namespace std;


// #problem:https://leetcode.com/problems/shortest-path-visiting-all-nodes/?envType=daily-question&envId=2023-09-17

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        unordered_map<int, vector<int>> adj;

        for (int i = 0; i < n; i++) {
            for (int it : graph[i]) {
                adj[i].push_back(it);
            }
        }

        int ans = INT_MAX; // Initialize ans with a large value to find the minimum path length.

        for (int i = 0; i < n; i++) {
            ans = min(ans, solve(i, adj, n));
        }

        return ans;
    }

    int solve(int start, unordered_map<int, vector<int>>& adj, int n) {
        queue<pair<int, int>> q; // Use a queue to perform BFS. Each element is a pair (node, mask).
        vector<vector<bool>> visited(n, vector<bool>(1 << n, false)); // To keep track of visited nodes with masks.
        
        q.push({start, 1 << start}); // Start BFS from the 'start' node with mask representing the visited nodes.
        visited[start][1 << start] = true;
        int steps = 0; // Initialize the steps to 0.

        while (!q.empty()) {
            int size = q.size();
            
            for (int i = 0; i < size; i++) {
                int node = q.front().first;
                int mask = q.front().second;
                q.pop();
                
                if (mask == (1 << n) - 1) {// it means all bits are set like 1111
                    return steps; // If all nodes are visited, return the number of steps.
                }
                
                // Explore neighbors of the current node.
                for (int neighbor : adj[node]) {
                    int new_mask = mask | (1 << neighbor);
                    
                    if (!visited[neighbor][new_mask]) {
                        q.push({neighbor, new_mask});
                        visited[neighbor][new_mask] = true;
                    }
                }
            }
            
            steps++; // Increment the number of steps after processing each level.
        }

        // If no path is found, return -1.
        return -1;
    }
};
