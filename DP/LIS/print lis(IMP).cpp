#include<bits/stdc++.h>
using namespace std;


// ! Approach: 

// 1.here while calculating dp table of LIS we are storing index of prev elem in the hash array
// 2.we create an temp vector
// 3.find the ind of the dp which has max value push that value in the temp (because it is the last element of the ans)
// 4.go to hash array traverse it such that hash[lastIndex]!=lastIndex .and push those ele from array in temp
// 5.reverse temp


vector<int>printlis(int n , vector<int>& arr){

    vector<int>dp(n,0);
    vector<int>hash(n,1);// storing index of previous element to the current index 

    for(int i=0; i<n; i++){
        hash[i]=i;

        for(int prev=0; prev<i; prev++){
            if(arr[i]>arr[prev]){
                if(dp[i]<dp[prev]+1){
                    hash[i]=prev;
                    dp[i]=dp[prev]+1;
                }
            }
        }
    }

    // now we are set with our hash array 


    int ans = INT_MIN;
    int last_index = -1;

    for(int i=0; i<n; i++){
        if(dp[i]>ans){
            ans=dp[i];
            last_index=i;
        }
    }

    // now in last_index we got the ending index of lis i.e the index of last element.

    vector<int>temp;

    temp.push_back(arr[last_index]);


   while(hash[last_index]!=last_index){
    last_index=hash[last_index];
    temp.push_back(arr[last_index]);
   }


   reverse(temp.begin(), temp.end());


   return temp;




}

//dry run

// arr:  5 4 11 1 16 8
// dp:   1 1 2  1  3 2
// hash: 0 1 0  3 2 3
