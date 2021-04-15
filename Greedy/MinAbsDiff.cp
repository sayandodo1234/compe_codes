// Given an integer array A of size N, find and return the minimum absolute difference between any two elements in the array.
// We define the absolute difference between two elements ai, and aj (where i != j ) is |ai - aj|.
// Input format :
// Line 1 : Integer N, Array Size
// Line 2 : Array elements (separated by space)
// Output Format :
// Minimum difference
// Constraints :
// 1 <= N <= 10^6
// Sample Input :
// 5
// 2 9 0 4 5
// Sample Input :
// 1


// arr - input array
// n - size of array
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int minAbsoluteDiff(int arr[], int n) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    sort(arr,arr+n);
    int d=arr[1]-arr[0];
    for(ll i=2;i<n;i++)
    {
        int t = abs(arr[i+1]-arr[i]);
        if(t<d)
          d = t;
    }
    return d;

}