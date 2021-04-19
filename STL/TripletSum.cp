// You have been given a random integer array/list(ARR) and a number X. Find and return the triplet(s) in the array/list which sum to X.
// Note :
// Given array/list can contain duplicate elements.
// Input format :
// The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

// First line of each test case or query contains an integer 'N' representing the size of the first array/list.

// Second line contains 'N' single space separated integers representing the elements in the array/list.

// Third line contains an integer 'X'.

// arr - input array
// size - size of array
// x - sum of triplets
#include<bits/stdc++.h>
using namespace std;



void FindTriplet(int arr[], int size, int x) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print output and don't return it.
     * Taking input is handled automatically.
     */
    sort(arr,arr+size);
    for(int i =0;i<size;i++)
    {
        int temp = x-arr[i];
        int start = i+1;
        int end = size-1;
        while(start<end)
        {
            if (arr[start] + arr[end] < temp)
                start++;
            else if(arr[start] + arr[end] > temp)
                end--;
            else
            {
                int inc = 0,dec = 0;
                for(int j = start;j<=end;j++)
                {
                    if(arr[j] == arr[start])
                        inc++;
                    else
                        break;
                }
                for(int j=end;j>=start;j--)
                {
                    if(arr[j]==arr[end])
                        dec++;
                    else
                        break;
                }
                int count = inc * dec ;
                if(arr[start] == arr[end])
                    count = ((end-start)*(end-start+1))/2;
                for(int j=0 ; j<count;j++)
                    cout << arr[i] << " " << arr[start] << " " << arr[end] << endl;
                start = start + inc;
                end = end - dec ;                           
            }
        }
    }
 }

