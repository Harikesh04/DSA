#include <bits/stdc++.h>
using namespace std;


// Problem:https://leetcode.com/problems/coin-change-ii/submissions/

// ! Approach: 
// always have two options either take it or not take it
// jb hm koi ko nhi lenge tb ind+1 kr denge mtlb ab aage badho
// jb lenge toh kuch nhi krenge because we have unlimited coins of same type

class Solution
{
public:

    vector<vector<int>> dp;

    int solve(vector<int> &coins, int amount, int ind)
    {
        // bc
        if (amount == 0)
            return 1;

        if (amount < 0)
            return 0;

        if (ind == coins.size())
            return 0;

        if (dp[ind][amount] != -1)
            return dp[ind][amount];

        int op1 = 0, op2 = 0;

        // take

        if (amount >= coins[ind])
        {

            op1 = solve(coins, amount - coins[ind], ind);
        }

        // don't take

        op2 = solve(coins, amount, ind + 1);

        return dp[ind][amount] = op1 + op2;
    }
    int change(int amount, vector<int> &coins)
    {

        dp.resize(coins.size() + 1, vector<int>(amount + 1, -1));

        return solve(coins, amount, 0);
    }
};