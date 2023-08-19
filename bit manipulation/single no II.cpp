#include<bits/stdc++.h>
using namespace std;

//Problem:https://leetcode.com/problems/single-number-ii/?envType=list&envId=rogr9mvd

class Solution
{
public:
    // Naive Approach
    // int singleNumber(vector<int>& nums) {

    //     unordered_map<long long,long long>mp;

    //     for(auto &it:nums){
    //         mp[it]++;
    //     }

    //     for(auto &it: mp){
    //         if(it.second==1)return it.first;
    //     }

    //     return 0;

    // }

    // ! Bit Manipulation

    // ? Approach: here what we are going to do is we will iterate through each no. of the array and each bit of the no.

    // ? at each ith position will count no. set bit and no. of unset bit , if any of its %3 != 0 it means it is bit of the no. which is the single element.

    // ? will include that bit in ans 

    // eg

    // 2 2 2 3

    // 10
    // 10
    // 10
    // 11

    // here at 0th position un_set_bit%3==0 but set_bit%3!=0 so here we found out result's 0th bit

    int singleNumber(vector<int> &nums)
    {

        int ans = 0, cnt_set = 0, cnt_unset = 0;

        for (int i = 0; i < 32; i++)
        {
            cnt_set = 0, cnt_unset = 0;
            for (auto &it : nums)
            {
                bool isSet = (it & (1 << i));

                if (isSet)
                {
                    cnt_set++;
                }
                else
                {
                    cnt_unset++;
                }
            }

            // as our initial ans is 0 therefore all the bits are initialy unset so , we have to only take care of set bits

            if (cnt_set % 3)
                ans = ans | (1 << i);
        }

        return ans;
    }
};