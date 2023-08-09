#include <bits/stdc++.h>
using namespace std;

// this is the brute force approach to find the max sum of the subarray of the array .
int main(int argc, char const *argv[])
{
    int arr[1000] = {-5, 4, 6, -3, 4, -1};
    int maxSum = 0;
    int sum = 0;
    for (int i = 0; i < 6; i++)
    {
        sum = 0;
        for (int j = i; j < 6; j++)
        {
            sum += arr[j];
            maxSum = max(maxSum, sum);
        }
    }
    cout << maxSum << endl;
    return 0;
}


// ! using kadane's algo

void solve()
{
    int arr[1000]= {-5, 4 ,6,-3,4,-1};
      int maxSum =0,sum=0;
      for (int i = 0; i < 6; i++)
      {
         sum=sum+arr[i];
         sum=max(0,sum);
         maxSum = max(maxSum,sum);
      }
      cout<<maxSum<<endl;
      

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

   

    solve();
    return 0;
}