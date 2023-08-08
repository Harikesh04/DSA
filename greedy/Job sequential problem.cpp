#include<bits/stdc++.h>
using namespace std;


// link :https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#
// Job Sequential Problem:here we have to do jobs and acquire max profit under the given deadline.


// Approach:

// 1.sort on basis of profit.
// 2.make an array jobs of size max deadline .
// 3.now traverse on all the jobs and will try to allocate in jobs array from right(deadline) to left.
// mtlb apn agr kaam ko jldi kr denge tb jada profit nii kma payenge , isisliye apn kaam ko uski deadline se dekhenge agr koi block khali hoga tb us ko kr denge 
// return required ans.

struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};



class Solution
{
public:
    bool static cmp(Job a, Job b)
    {
        return a.profit > b.profit;
    }
    // Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n)
    {
        sort(arr, arr + n, cmp);

        int maxDeadline = 0;

        for (int i = 0; i < n; i++)
        {
            maxDeadline = max(maxDeadline, arr[i].dead);
        }

        int cnt = 0, sum = 0;

        vector<int> v(maxDeadline + 1, -1);

        for (int i = 0; i < n; i++)
        {

            for (int j = arr[i].dead; j > 0; j--)
            {
                if (v[j] == -1)// checking ki apn khali toh nhi
                { // if no job allocated

                    v[j] = i;
                    cnt++;
                    sum += arr[i].profit;
                    break;
                }
            }
        }

        return {cnt, sum};
    }
};