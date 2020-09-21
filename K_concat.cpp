// https://www.codechef.com/problems/KCON


// You are given an array A with size N (indexed from 0) and an integer K. Let's define another array B with size N · K as the array that's formed by concatenating K copies of array A.

// For example, if A = {1, 2} and K = 3, then B = {1, 2, 1, 2, 1, 2}.

// You have to find the maximum subarray sum of the array B. Fomally, you should compute the maximum value of Bi + Bi+1 + Bi+2 + ... + Bj, where 0 ≤ i ≤ j < N · K.

// Input
// The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
// The first line of each test case contains two space-separated integers N and K.
// The second line contains N space-separated integers A0, A1, ..., AN-1.
// Output
// For each test case, print a single line containing the maximum subarray sum of B.

// Constraints
// 1 ≤ T ≤ 10
// 1 ≤ N ≤ 105
// 1 ≤ K ≤ 105
// -106 ≤ Ai ≤ 106 for each valid i
// Subtasks
// Subtask #1 (18 points): N · K ≤ 105

// Subtask #2 (82 points): original constraints

// Example
// Input:

// 2
// 2 3
// 1 2
// 3 2
// 1 -2 1

// Output:

// 9
// 2
// Explanation
// Example case 1: B = {1, 2, 1, 2, 1, 2} and the subarray with maximum sum is the whole {1, 2, 1, 2, 1, 2}. Hence, the answer is 9.

// Example case 2: B = {1, -2, 1, 1, -2, 1} and the subarray with maximum sum is {1, 1}. Hence, the answer is 2



#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll kadane(int arr[],int n)
{
    ll curr_sum = 0;
    ll best_sum = INT_MIN;
    for(int i=0;i<n;i++)
    {
        curr_sum = curr_sum + arr[i];
        if(best_sum < curr_sum)
        {
            best_sum = curr_sum;
        }
        if(curr_sum<0)
        {
            curr_sum = 0;
        }
    }
    return best_sum;
}
ll sum_arr(int arr[],int n,int k)
{
    ll kadanes_sum = kadane(arr,n);
    if ( k==1)
        return kadanes_sum;
    ll curr_pre_sum = 0,max_pre_sum = INT_MIN;
    ll curr_suff_sum = 0,max_suff_sum = INT_MIN;

    for(int i=0;i<n;i++)
    {
        curr_pre_sum = curr_pre_sum + arr[i];
        max_pre_sum = max(curr_pre_sum,max_pre_sum);
    }
    ll totalSum = curr_pre_sum;
    for(int i = n-1;i>=0;i--)
    {
        curr_suff_sum = curr_suff_sum + arr[i];
        max_suff_sum = max(max_suff_sum,curr_suff_sum);
    }
    ll ans;
    if (totalSum<0)
    {
        ans = max(max_suff_sum + max_pre_sum,kadanes_sum);
    }
    else
    {
        ans = max(max_suff_sum+max_pre_sum+(totalSum *(k-2)),kadanes_sum);
    }
    return ans;

}
int main()
{
    int t,n,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];

        }
        cout<<sum_arr(a,n,k)<<endl;
    }
    return 0;
}