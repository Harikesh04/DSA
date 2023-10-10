#include <bits/stdc++.h>
using namespace std;

// Problem:https://leetcode.com/problems/palindrome-partitioning-ii/description/?envType=list&envId=rwkgex9g

// ! Approach

class Solution
{
public:
    //    tc: O(n2)*O(n)== O(n3) // tle
    // vector<vector<int>>dp;

    vector<int> dp;

    bool isPalindrome(int i, int j, string &s)
    {
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    // int solve(string& s, int i , int j){
    //     if(i>j)return 0;

    //     string temp ;

    //     if(dp[i][j]!=-1)return dp[i][j];

    //     for(int ind=i;ind<=j;ind++){
    //         temp.push_back(s[ind]);
    //     }

    //     if(isPalindrome(temp))return 0;

    //     int mini=INT_MAX;

    //     for(int cut=i;cut<j;cut++){

    //             int ans = solve(s,i,cut)+solve(s,cut+1,j)+1;

    //             mini=min(mini,ans);

    //     }
    //     return dp[i][j]= mini;

    // }

    int f(int i, int n, string &str)
    {
        // Base case:
        if (i == n)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int minCost = INT_MAX;
        // string[i...j]
        for (int j = i; j < n; j++)
        {
            if (isPalindrome(i, j, str))
            {
                int cost = 1 + f(j + 1, n, str);
                minCost = min(minCost, cost);
            }
        }
        return dp[i] = minCost;
    }
    int minCut(string str)
    {

        int n = str.size();
        dp.resize(n + 1, -1);
        return f(0, n, str) - 1;
    }
};