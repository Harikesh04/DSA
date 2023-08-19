#include<bits/stdc++.h>
using namespace std;


//Problem:https://leetcode.com/problems/maximal-network-rank/description/

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int, unordered_set<int>> adj;

        for (auto v : roads) {
            int i = v[0], j = v[1];
            adj[i].insert(j);
            adj[j].insert(i);
        }

        int maxRank = INT_MIN;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int rank = adj[i].size() + adj[j].size();

                if (adj[i].count(j)) {
                    rank--; // Adjust for duplicate road between i and j
                }

                maxRank = max(maxRank, rank);
            }
        }

        return maxRank;
    }
};
