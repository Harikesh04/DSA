#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    vector<int> dijakstra(int V, vector<vector<int>> adj[], int source)
    {

        // priority_queue<int,vector<int>,greater<int>>pq;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> res(V, INT_MAX); // initially marked distance for all node a infinity

        res[source] = 0;// src ka src se distance toh 0 hi hoga

        pq.push({0, source}); // pq m bhi push kr denge

        while (!pq.empty())
        {
            auto [dist, node] = pq.top();// correct node aur us tk distance
            pq.pop();

            for (auto &it : adj[node])// current node k adj value node ko traverse krenge
            {

                int adjNode = it[0];
                int wt = it[1];

                if (dist + wt < res[adjNode])// agr adj node ki duri km h res[adjNode] toh update kr denge res ko
                {

                    res[adjNode] = dist + wt;
                    pq.push({dist + wt, adjNode});
                }
            }
        }

        return res;
    }
};