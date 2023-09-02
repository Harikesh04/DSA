#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int ans = 0;
    unordered_set<string> st;
    int n = 0;
    vector<int> dp;

    int solve(string &s, int i)
    {
        if (i >= s.size())
        {
            return 0;
        }

        if (dp[i] != -1)
            return dp[i];

        string curStr = "";

        int minCost = INT_MAX;

        for (int j = i; j < n; j++)
        {

            curStr.push_back(s[j]);

            int extraCost = 0;

            if (!st.count(curStr))
            {

                extraCost = curStr.size();
            }
            else
            {
                extraCost = 0;
            }

            int furtherCost = solve(s, j + 1);

            int totalCost = extraCost + furtherCost;

            minCost = min(minCost, totalCost);
        }

        return dp[i] = minCost;
    }

    int minExtraChar(string s, vector<string> &dict)
    {
        dp.resize(s.size() + 1, -1);
        n = s.size();

        for (auto &it : dict)
        {
            st.insert(it);
        }

        return solve(s, 0);
    }
};