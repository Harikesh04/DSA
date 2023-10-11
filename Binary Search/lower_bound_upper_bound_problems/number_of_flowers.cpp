#include <bits/stdc++.h>
using namespace std;

// Problem:https://leetcode.com/problems/number-of-flowers-in-full-bloom/

// Approach:

// brute force: O(n^2) , yha p apn hr people k liye hr flowers m ye dekh rhe the ki voh us range m h ya noshowpoint

// Optimization:

// ! yha p apn do array bnaye

// 1. startTime - flowers k khilne ka smay
// 2. endTime - flowers k mrne ka smay

// ap m startTime m upperbound lga k ye check kr lunga ki jb ith people aaya toh koon se index tk flowers khile hue the
// same m endTime m lowerbound lga k ye check kr lunga ki jb ith people aaya toh koon se index tk flowers mre hue the

// dono ko minus kr do -> ans for ith people

class Solution
{
public:
    vector<int> fullBloomFlowers(vector<vector<int>> &flowers, vector<int> &people)
    {

        vector<int> res;

        vector<int> startTime;
        vector<int> endTime;

        for (auto &it : flowers)
        {
            startTime.push_back(it[0]);
            endTime.push_back(it[1]);
        }
        sort(startTime.begin(), startTime.end());
        sort(endTime.begin(), endTime.end());

        for (auto &it : people)
        {

            int max_ele_ind = upper_bound(startTime.begin(), startTime.end(), it) - startTime.begin();
            int min_ele_ind = lower_bound(endTime.begin(), endTime.end(), it) - endTime.begin();

            int flowers_alive = max_ele_ind - min_ele_ind;

            res.push_back(flowers_alive);
        }

        return res;
    }
};