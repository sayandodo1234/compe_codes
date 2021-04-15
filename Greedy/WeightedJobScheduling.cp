// You are given N jobs where every job is represented as:
// 1.Start Time
// 2.Finish Time
// 3.Profit Associated
// Find the maximum profit subset of jobs such that no two jobs in the subset overlap.
// Input
// The first line of input contains one integer denoting N.
// Next N lines contains three space separated integers denoting the start time, finish time and the profit associated with the ith job. 
// Output
// Output one integer, the maximum profit that can be achieved.
// Constraints
// 1 ≤ N ≤ 10^6
// 1 ≤ ai, di, p ≤ 10^6
// Sample Input
// 4
// 3 10 20
// 1 2 50
// 6 19 100
// 2 100 200
// Sample Output
// 250

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class Job
{
    public:
    int s;
    int f;
    int p;
};
bool end_sort(Job j1 , Job j2)
{
    return j1.f < j2.f;
}

int binarySearch(Job jobs[], int index) 
{ 
    int low = 0, high = index - 1; 
  
    while (low <= high) 
    { 
        int mid = (low + high) / 2; 
        if (jobs[mid].f <= jobs[index].s) 
        { 
            if (jobs[mid + 1].f <= jobs[index].s) 
                low = mid + 1; 
            else
                return mid; 
        } 
        else
            high = mid - 1; 
    } 
  
    return -1; 
}
int main()
{
    //Write your code here
    ll n;
    cin>>n;
    Job jobs[n];
    for(int i=0;i<n;i++)
    {
        cin>>jobs[i].s>>jobs[i].f>>jobs[i].p;
    }
    sort(jobs,jobs+n,end_sort);
    int dp[n];
    dp[0] = jobs[0].p;
    for(int i=0;i<n;i++)
    {
        int temp = jobs[i].p;
        int l = binarySearch(jobs,i);

        if(l != -1)
        {
             temp += dp[l];
        }
        dp[i] = max(temp,dp[i-1]);
       
    }
    cout<<dp[n-1]<<endl;
    return 0;
}