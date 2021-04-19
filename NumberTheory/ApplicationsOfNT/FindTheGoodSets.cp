// You are given array a consisting of n distinct integers. A set s of numbers is called good if you can rearrange the elements in such a way that each element divides the next element in the order, i.e. 'si' divides 'si + 1', such that i < |s|, where |s| denotes size of set |s|.
// Find out number of distinct good sets that you can create using the values of the array. You can use one value only once in a particular set; ie. a set cannot have duplicate values. Two sets are said to be different from each other if there exists an element in one set, which does not exist in the other.
// As the answer could be large, print your answer modulo 10^9 + 7.
// Input
// First line of the input contains an integer T denoting the number of test cases. T test cases follow.

// First line of each test case contains an integer n denoting number of elements in array a.

// Next line contains n space separated integers denoting the elements of array a.
// Output
// For each test case, output a single line containing the corresponding answer.
// Constraints
// 1 ≤ T ≤ 3

// 1 ≤ n ≤ 7.5 * 10^5

// 1 ≤ ai ≤ 7.5 * 10^5

// All the elements of array a are distinct.
// Example
// Input
// 2
// 2
// 1 2
// 3
// 6 2 3
// Output:
// 3
// 5
// Explanation
// Test case 1. There are three sets which are good {1}, {2}, {1, 2}.

// Test case 2. There are five sets which are good {6}, {2}, {3}, {6 2}, {6, 3}.
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
ll a[750006],f[750006],dp[750006];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll i,j,k,t,n;
    cin>>t;
    while(t--)
    {
        for(i=1;i<=750000;i++)
        {
            dp[i]=0;
            f[i]=0;
        }
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>a[i];
            f[a[i]]=1;
        }
        sort(a+1,a+n+1);
        reverse(a+1,a+n+1);
        for(i=1;i<=n;i++)
        {
            j=a[i];
            dp[j]=1;
            for(k=2*j;k<=750000;k+=j)
            {
                if(f[k])
                dp[j]+=dp[k];
            }
            dp[j]%=MOD;
        }
        ll ans=0;
        for(i=1;i<=750000;i++)
        ans+=dp[i];
        cout<<ans%MOD<<"\n";
    }
    return 0;
}