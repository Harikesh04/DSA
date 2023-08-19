#include<bits/stdc++.h>
using namespace std;

//Problem:https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/?envType=list&envId=r2zzj5c3

class Solution
{
public:
    vector<string> ans;

    void solve(string &digits, vector<string> &v, string temp, int start)
    {
        // bc
        if (temp.size() == digits.size())
        {
            ans.push_back(temp);
            return;
        }

        int ind = digits[start] - '0';
        string s = v[ind];

        for (int i = 0; i < s.size(); i++)
        {
            temp.push_back(s[i]);
            solve(digits, v, temp, start + 1);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {

        if (digits == "")
            return ans;

        vector<string> v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string temp;

        solve(digits, v, temp, 0);

        return ans;
    }
};