#include <bits/stdc++.h>
using namespace std;

// Problem:https://leetcode.com/problems/maximum-sum-circular-subarray/description/

// Approach:

// 1. we will sum maxsum subarray by kadane's algo
// 2.we will mn sum of the array
// 3. ans will be maximum of maxsum or totalSum-mnSum;


class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &nums)
    {
        int mnSum = INT_MAX, minEndingHere = INT_MAX;
        int n = nums.size();
        int cursum = 0, mxSum = INT_MIN, totalSum = 0;

        for (int i = 0; i < n; i++)
        {

            if (minEndingHere > 0)
            {
                minEndingHere = nums[i];
            }
            else
            {
                minEndingHere += nums[i];
            }
            mnSum = min(minEndingHere, mnSum);
            cursum += nums[i];
            cursum = max(cursum, 0);
            mxSum = max(mxSum, cursum);

            totalSum += nums[i];
        }

        if (totalSum - mnSum == 0 && mxSum > 0)
        {
            return mxSum;
        }

        if (totalSum - mnSum == 0)
        {
            return *max_element(nums.begin(), nums.end());
        }
        return max(totalSum - mnSum, mxSum);
    }
};