// You are given n activities with their start and finish times. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.
// Input
// The first line of input contains one integer denoting N.
// Next N lines contains two space separated integers denoting the start time and finish time for the ith activity.

// Output
// Output one integer, the maximum number of activities that can be performed
// Constraints
// 1 ≤ N ≤ 10^6
// 1 ≤ ai, di ≤ 10^9
// Sample Input
// 6
// 1 2
// 3 4
// 0 6
// 5 7
// 8 9
// 5 9
// Sample Output
// 4

#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
struct Activity 
{ 
    int start, end; 
}; 

bool sort_end(Activity s1, Activity s2) 
{ 
    return (s1.end< s2.end); 
} 

int main() 
{ 
    ll n;
    cin>>n;
    Activity arr[n];
	for(int i=0; i<n; i++)
	{
		cin>>arr[i].start>>arr[i].end;
    }

    sort(arr, arr+n, sort_end); 


    ll i = 0; 
    ll count =1;

    for (ll j = 1; j < n; j++) 
    { 
      	if (arr[j].start>= arr[i].end) 
      	{	
            count++;
			i = j; 
      	} 
    } 
    cout<<count ;
    return 0; 
}