#include<bits/stdc++.h>
using namespace std;

// ! Problem:https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/description/

// ? Approach:

// here we just have to break the problem in options and question is done
// optimization to avoid tle: dp[1e6][500] will give tle
// since we traverse max of number of steps not more than that , therefore we can reduce arrayLen and take dp[500][500].



class Solution {
public:
    vector<vector<long long>> dp;
    int M = 1e9 + 7;

    long long solve(int steps, int arrLen, int ind) {
        if (ind < 0 || ind >= arrLen) {
            return 0;
        }

        if (steps == 0) {
            if (ind == 0) {
                return 1;
            }
            return 0;
        }

        if (dp[steps][ind] != -1) {
            return dp[steps][ind];
        }

        long long op1 = solve(steps - 1, arrLen, ind + 1) % M;
        long long op2 = solve(steps - 1, arrLen, ind - 1) % M;
        long long op3 = solve(steps - 1, arrLen, ind) % M;

        long long res = (op1 + op2 + op3) % M;

        return dp[steps][ind] = res;
    }

    int numWays(int steps, int arrLen) {
        int modified_arr_len = min(steps,arrLen);
        dp.resize(steps + 1, vector<long long>(modified_arr_len + 1, -1));
        long long ans = solve(steps, arrLen, 0);
        return ans;
    }
};
