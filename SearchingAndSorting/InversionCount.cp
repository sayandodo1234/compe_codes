// For a given integer array/list of size N, find the total number of 'Inversions' that may exist.
// An inversion is defined for a pair of integers in the array/list when the following two conditions are met.
// A pair (arr[i], arr[j]) is said to be an inversion when,
// 1. arr[i] > arr[j] 
// 2. i < j

// Where 'arr' is the input array/list, 'i' and 'j' denote the indices ranging from [0, N).
// Input format :
// The first line of input contains an integer N, denoting the size of the array.

// The second line of input contains N integers separated by a single space, denoting the elements of the array.
// Output format :
// The only line of output prints the total count of inversions in the array.
// Note:
// You are not required to print anything. Return the total number of inversion count.
// Constraints :
// 1 <= N <= 10^5 
// 1 <= arr[i] <= 10^9

// Time Limit: 1sec
// Sample Input 1 :
// 3
// 3 2 1
// Sample Output 1 :
// 3
// Explanation of Sample Input 1:
// We have a total of three pairs which satisfy the condition of inversion. (3, 2), (2, 1) and (3, 1).
// Sample Input 2 :
// 5
// 2 5 1 3 4
// Sample Output 2 :
// 4

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll merge(ll *A,int left,int mid,int right){

	int i=left,j=mid,k=0;

	int temp[right-left+1];
	ll count = 0;
	while(i<mid && j<=right){
		if(A[i] <= A[j]){
			temp[k++] = A[i++];
		}else{
			temp[k++] = A[j++];
			count += mid - i;
		}
	}
	while(i<mid){
		temp[k++] = A[i++];
	}
	while(j<=right){
		temp[k++] = A[j++];
	}

	for(int i=left,k=0;i<=right;i++,k++){
		A[i] = temp[k];
	}
	return count;
}

long long getInversions(ll *input, int n,int left =0)   
{
    //Write your code here
    
    int right = n-1;
	if(right > left)
    {
		int mid = (left + right)/2;
		return getInversions(input,mid+1,left) + getInversions(input,right+1,mid+1) + merge(input,left,mid+1,right);
	}
	return 0;

    
}