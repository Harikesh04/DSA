#include<bits/stdc++.h>
using namespace std;

// Problem link:https://www.interviewbit.com/problems/maximum-sum-combinations/


// Approach :

// ? Naive: if we insert all pairs then take best C pair : TC O(n^2);

// ? Optimal: 
// 1. sorted both the array in reverse order because we want the maximum sum
// 2. at every index the maximum element could be either (i+1,j) or (i,j+1);
// 3. we are pushing both the elements in the pq
// 4. maintaining a set so that to prevent repetition
// 5. since C elements are required so repeating this process C times.

vector<int>solve(vector<int> &A, vector<int> &B, int C)
{
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());
    vector<int> ans;
    priority_queue<pair<int, pair<int, int>>> pq;
    set<pair<int, int>> st;
    pq.push({A[0] + B[0], {0, 0}});

    for (int i = 0; i < C; i++)
    {
        pair<int, pair<int, int>> p = pq.top();
        pq.pop();
        ans.push_back(p.first);
        if (p.second.first + 1 < A.size() && st.count({p.second.first + 1, p.second.second}))
        {
            pq.push({A[p.second.first + 1] + B[p.second.second], {p.second.first + 1, p.second.second}});
            st.insert({p.second.first + 1, p.second.second});
        }
        if (p.second.second + 1 < B.size() && st.count({p.second.first, p.second.second + 1}))
        {
            pq.push({A[p.second.first] + B[p.second.second + 1], {p.second.first, p.second.second + 1}});
            st.insert({p.second.first, p.second.second + 1});
        }
    }
    return ans;
}
