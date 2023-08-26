#include<bits/stdc++.h>
using namespace std;

//Problem:https://leetcode.com/problems/reorganize-string/description/

class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mp;
        for (auto &it : s) {
            mp[it]++;
        }

        priority_queue<pair<int, char>, vector<pair<int, char>>> pq;
        for (auto &it : mp) {
            pq.push({it.second, it.first});
        }

        string ans;

        while (!pq.empty()) {
            auto [cnt, ch] = pq.top();
            pq.pop();

            if (ans.size() == 0 || (ans.size() > 0 && ch != ans[ans.size() - 1])) {
                ans.push_back(ch);
                mp[ch]--;
                if (mp[ch] > 0) {
                    pq.push({mp[ch], ch});
                }
            } else {
                if (pq.empty()) {
                    return ""; // Not possible to reorganize
                }
                auto [nextCnt, nextCh] = pq.top();
                pq.pop();
                ans.push_back(nextCh);
                mp[nextCh]--;
                if (mp[nextCh] > 0) {
                    pq.push({mp[nextCh], nextCh});
                }
                pq.push({cnt, ch}); // Add the previous character back to the priority queue
            }
        }

        return ans;
    }
};
