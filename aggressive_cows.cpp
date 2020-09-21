// Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).
// His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?
// Input
// t – the number of test cases, then t test cases follows. 
// * Line 1: Two space-separated integers: N and C
// * Lines 2..N+1: Line i+1 contains an integer stall location, xi
// Output
// For each test case output one integer: the largest minimum distance.
// Sample Input :
// 1
// 5 3
// 1
// 2
// 8
// 4
// 9
// Sample Output:
// 3 
// Output details:
// FJ can put his 3 cows in the stalls at positions 1, 4 and 8, 
// resulting in a minimum distance of 3.


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

 
ll aggr_cow_d(ll arr[],int cows,int size)
{
    

   ll ans=-1;
   ll start = 0;
   ll end = arr[size-1]-arr[0];
   while(start <= end)
   {
       ll last = arr[0];
       int count= 1;       
       ll mid = (start + end)/2;
       for(int i = 0 ;i<size ; i++)
       {
           if (arr[i] - last >= mid)
           {
               last = arr[i];
               count++;
           }
       }
       if(count == cows)
       {
           ans = mid ;
           start = mid+1;
       }
       else
       {
           end = mid -1 ;
       } 
   }
    return ans ;
 
    
}
int main() {

	// Write your code here
    int t ;
    cin>>t;
    while(t--)
    {
        int n,c;
        cin>>n>>c;
        ll arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i]; 
        }
        sort(arr,arr+n);
        cout<<aggr_cow_d(arr,c,n)<<endl;
    }
}