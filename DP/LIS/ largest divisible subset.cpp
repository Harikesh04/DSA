#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // ! Approach : this is just a small modification of print lcs.

    // here just added an additional condition if nums[curr]%nums[prev]==0 then we will include it in lcs

    // no need to compare % with all the ele because once it is divisible by the last element then it will also be divisible with other element also

    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> dp(n, 1);
        vector<int> hash(n, 1);

        //    dp[i]= lenght of longest increasing subseq till ith index

        for (int i = 0; i < n; i++)
        {
            hash[i] = i;
            for (int prev = 0; prev < i; prev++)
            {
                if (nums[i] > nums[prev] && nums[i] % nums[prev] == 0)
                {
                    if (dp[i] < 1 + dp[prev])
                    {
                        dp[i] = 1 + dp[prev];
                        hash[i] = prev;
                    }
                }
            }
        }

        int last_index = 0, ans = 0;

        for (int i = 0; i < n; i++)
        {
            if (ans < dp[i])
            {
                ans = dp[i];
                last_index = i;
            }
        }

        vector<int> res;

        res.push_back(nums[last_index]);

        while (hash[last_index] != last_index)
        {
            last_index = hash[last_index];
            res.push_back(nums[last_index]);
        }

        reverse(res.begin(), res.end());

        return res;
    }
};