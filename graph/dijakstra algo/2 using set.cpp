#include <bits/stdc++.h>
using namespace std;


// ! Approach 

// ? here we are doing the same as priority queue method but advantage of set over priority queue is that we can erase the smaller distace pair from set and due to that we prevent some unnecessary traversal , which we can't in pq.

class Solution
{

public:
    vector<int> dijakstra(int V, vector<vector<int>> adj[], int source)
    {

        set<pair<int, int>> st;

        vector<int> res(V, INT_MAX);

        st.insert({0, source});

        res[source] = 0;

        while (!st.empty())
        {
            auto &it = *st.begin();
            int node = it.second;
            int distance = it.first;

            st.erase(it);

            for (auto &it : adj[node])
            {

                int adjNode = it[0];
                int wt = it[1];

                if (distance + wt < res[adjNode])
                {

                    if (res[adjNode] != INT_MAX)// mtlb hmare pass koi chota pair h toh usko kyu hi rkhenge , remove kr dete h
                    {
                        st.erase({res[adjNode], adjNode});
                    }

                    res[adjNode] = distance + wt;
                    st.insert({distance + wt, adjNode});
                }
            }

            return res;
        }
    }
};