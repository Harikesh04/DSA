#include <bits/stdc++.h>
using namespace std;

// Approach:https://leetcode.com/problems/remove-duplicate-letters/?envType=daily-question&envId=2023-09-26

// ! Approach

// ? here we have to print lexographically smallest string with unique characters
// ? toh yha p hm check kr rhe h ki agr koi char jo apn place kr rhe h agr uske phle usse bde present h aur agr unbde char ka occurrence string m baad m bhi h toh unko pop kr denge

// ! here we have used string , but can also be done using stack , also this type of pattern is called as monotonic stack pattern
class Solution
{
public:
    string removeDuplicateLetters(string s)
    {

        string res;

        vector<bool> visited(26, false);
        vector<int> lastInd(26);

        for (int i = 0; i < s.size(); i++)
        {

            lastInd[s[i] - 'a'] = i;
        }

        for (int i = 0; i < s.size(); i++)
        {

            char ch = s[i];

            int ind = s[i] - 'a';

            if (visited[ind] == true)
                continue;

            while (res.size() > 0 && res.back() > ch && lastInd[res.back() - 'a'] > i)
            {
                visited[res.back() - 'a'] = false;
                res.pop_back();
            }

            res.push_back(ch);
            visited[ind] = true;
        }

        return res;
    }
};