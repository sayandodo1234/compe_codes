// Shaky has N (1<=N<=50000) candy boxes each of them contains a non-zero number of candies (between 1 and 1000000000). Shaky want to distibute these candies among his K (1<=K<=1000000000) IIIT-Delhi students. He want to distibute them in a way such that:
// 1. All students get equal number of candies.
// 2. All the candies which a student get must be from a single box only.
// As he want to make all of them happy so he want to give as many candies as possible. Help Shaky in finding out what is the maximum number of candies which a student can get.
// Input
// First line contains 1<=T<=20 the number of test cases. Then T test cases follow. First line of each test case contains N and K. Next line contains N integers, ith of which is the number of candies in ith box.
// Output
// For each test case print the required answer in a seperate line.
// Sample Input:
// 2
// 3 2 
// 3 1 4
// 4 1
// 3 2 3 9
// Sample Output:
// 3
// 9

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


ll binary_check(ll arr[],ll size,ll students)
{

    
    ll lo;
    ll hi;
    ll mid;
    //int i;
    ll count;
    lo = 0;
    hi = arr[size-1];
    ll sol =0 ;

    while(lo <= hi) {
        //mid = lo + (hi-lo+1)/2;
        mid = (lo + hi)/2;
        count = 0;
        for(ll i = 0; i < size; i++) {
            count = count + (arr[i]/mid);
        }

        if(count >= students) {
            sol = mid;
            lo = mid+1;
        }
        else {
            hi = mid-1;
        }
    }

    return sol;
    
}

int main() {

	// Write your code here
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll arr[n];
        ll tot_sum=0;
        for(ll i = 0;i<n;i++){
            cin>>arr[i];
            tot_sum += arr[i];
        }
        sort(arr,arr+n);
        cout<<binary_check(arr,n,k)<<endl;
    }
}