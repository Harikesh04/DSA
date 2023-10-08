#include<bits/stdc++.h>
using namespace std;

// ! Problem:https://leetcode.com/problems/max-dot-product-of-two-subsequences/description/


// ! Approach:

// here since as in all dp problems we try to break the problem into indexes since the problem depends upon length of both the array so will take two pointers i and j 

// now we have 4 options either 
// 1.include both elements of current index in the product
// 2. exclude 1st element
// 3.exclude 2nd element
// 4.exclude both element


// result will be the max 


class Solution {
public:

    vector<vector<int>>dp;
    int solve(vector<int>& nums1, vector<int>& nums2, int i, int j) {
        // Base case: if any of the arrays is fully traversed, return 0
        if (i >= nums1.size() || j >= nums2.size()) {
            return 0;
        }

        if(dp[i][j]!=-1)return dp[i][j];
        
        // Case 1: Include the current elements in the dot product
        int include = nums1[i] * nums2[j] + solve(nums1, nums2, i + 1, j + 1);
        
        // Case 2: Exclude the current element from either nums1 or nums2
        int exclude = max(solve(nums1, nums2, i + 1, j), max(solve(nums1, nums2, i, j + 1),solve(nums1,nums2,i+1,j+1)));

    
        
        // Return the maximum of the two cases
        return dp[i][j]=max(include, exclude);
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        // Start the recursive function from the beginning of both arrays
        dp.resize(nums1.size()+1,vector<int>(nums2.size()+1,-1));
        int ans= solve(nums1, nums2, 0, 0);

        // this base case is very important

        if(ans==0){
            int a = *max_element(nums1.begin(), nums1.end());
            int b = *min_element(nums1.begin(), nums1.end());
           
            int c = *max_element(nums2.begin(), nums2.end());
            int d = *min_element(nums2.begin(), nums2.end());
           
           return max(a*d, b*c);
        }

        return ans;

    }
};
