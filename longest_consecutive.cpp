// Longest Consecutive Sequence
// Send Feedback
// You are given an array of unique integers that contain numbers in random order. Write a program to find the longest possible sequence of consecutive numbers using the numbers from given array.
// You need to return the output array which contains consecutive elements. Order of elements in the output is not important.
// Best solution takes O(n) time.
// If two sequences are of equal length then return the sequence starting with the number whose occurrence is earlier in the array.
// Input Format :
// Line 1 : Integer n, Size of array
// Line 2 : Array elements (separated by space)
// Constraints :
// 0 <= n <= 10^8
// Sample Input 1 :
// 13
// 2 12 9 16 10 5 3 20 25 11 1 8 6 
// Sample Output 1 :
// 8 
// 9 
// 10 
// 11 
// 12
// Sample Input 2 :
// 7
// 3 7 2 1 9 8 41
// Sample Output 2 :
// 7
// 8
// 9
// Explanation: Sequence should be of consecutive numbers. Here we have 2 sequences with same length i.e. [1, 2, 3] and [7, 8, 9], but output should be [7, 8, 9] because the starting point of [7, 8, 9] comes first in input array.
// Sample Input 3 :
// 7
// 15 24 23 12 19 11 16
// Sample Output 3 :
// 15 
// 16


#include <vector>
#include<bits/stdc++.h>
using namespace std;

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n){
	//Your Code goes here
    vector<int> v;
    unordered_map<int,bool> check;
    unordered_map<int,int> pos;
    for(int i = 0;i<n;i++)
    {
        pos[arr[i]] = i;
        if (check.count(arr[i]) == 0){
            check[arr[i]] = true;
        }

    }
    int max_length = 1;
    int start = 0 ;
    for(int i=0;i<n;i++){
        int buff = arr[i] ;
        int curr_index = i ;
        int sum = 0;
        int temp = buff ;
        while(check.count(temp) ==1 && check[temp]== true){
            check[temp] = false;
            sum++;
            temp++;
        }
        
        int temp_b = buff - 1;
        
        while(check.count(temp_b) == 1 && check[temp_b]==true){
            check[temp_b] = false;
            sum++;
            curr_index = pos[temp_b]  ;
            temp_b--;
        }
        
        if(sum > max_length){
            max_length = sum ;
            start = curr_index ;
        }
        else if (sum == max_length){
            if (curr_index < start)
               start = curr_index;
        } 
    }
        
    int num = arr[start] ;
        
    v.push_back(num);
    max_length--;
        
    while(max_length != 0){
        num++;
        v.push_back(num);
        max_length--;
    }
    return v;
    
}