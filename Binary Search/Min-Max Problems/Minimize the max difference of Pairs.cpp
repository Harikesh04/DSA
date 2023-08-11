#include<bits/stdc++.h>
using namespace std;


// Problem: https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/description/

// Approach: 

// since here we have to minimize the maximun difference .
// also mini ans could be any thing so binary search will work here
// in check function if we go with generating all pairs then it will cost O(n^2)
// since we done using sliding window therefore done in O(n). therefore overall nlogn.


class Solution
{
public:
    bool check(int x, vector<int> &nums, int p)
    {
        int cnt = 0;

        int head = 1, tail = 0;

        for (head = 1; head < nums.size();)
        {

            if (cnt >= p)// agar p pairs mil gye jo x se chote h toh return true kr do
                return true;
            if (abs(nums[head] - nums[tail]) <= x)
            {

                cnt++;
                head += 2;
                tail += 2;
                
            }
            else
            {
                head++;
                tail++;
            }
        }

        return cnt >= p;
    }
    int minimizeMax(vector<int> &nums, int p)
    {

        sort(nums.begin(), nums.end());

        int lo = 0, hi = abs(nums[0] - nums[nums.size() - 1]);

        int ans = -1;

        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;

            if (check(mid, nums, p))
            {
                ans = mid;
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }

        return ans;
    }
};