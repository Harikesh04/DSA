#include <bits/stdc++.h>
using namespace std;

// link :https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/?envType=list&envId=rogr9mvd

class Solution
{
public:
    // Approach : yha p maine check kia c ka ith index (i-> 0,31) set h ya nii.

    // if set , then at that position in b and c bit should be set .if in both of them none of them is unset then i will increase the cnt . Since given we have to do OR.

    // if unset , then at that position in b and b bit should be unset . If any or both of them will be set i will increase the cnt.

    int minFlips(int a, int b, int c)
    {

        int cnt = 0;

        for (int i = 1; i <= 31; i++)
        {

            // checking if ith bit of a,b,c is set or not.
            bool setBitInC = (c & 1 << (i - 1) ? true : false);
            bool setBitInB = (b & 1 << (i - 1) ? true : false);
            bool setBitInA = (a & 1 << (i - 1) ? true : false);

            if (setBitInC == true)
            {
                if (setBitInA || setBitInB)
                    cnt += 0;
                if (!setBitInA && !setBitInB)
                    cnt += 1;
            }
            else
            {
                if (setBitInA && setBitInB)
                    cnt += 2;
                if (setBitInA && !setBitInB)
                    cnt += 1;
                if (!setBitInA && setBitInB)
                    cnt += 1;
            }
        }
        return cnt;
    }
};