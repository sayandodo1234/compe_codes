// Given n, calculate and print the sum :
// LCM(1,n) + LCM(2,n) + .. + LCM(n,n)
// where LCM(i,n) denotes the Least Common Multiple of the integers i and n.
// Input Format :
// Line 1 : Integer n
// Output Format :
// Required sum
// Constraints :
// 1 <= T <= 300000
// 1 <= n <= 1000000
// Sample Input 1 :
// 5
// Sample Output 1 :
// 55
// Sample Input 2 :
// 2
// Sample Output 2 :
// 4
#include <bits/stdc++.h> 
using namespace std; 
#define ll long long int 
  
// Function to calculate the required LCM sum 
void func(long long n) 
{ 
    ll sum = 0; 
  
    for (long long int i = 1; i <= n; i++) { 
  
        // GCD of i and n 
        long long int gcd = __gcd(i, n); 
  
        // LCM of i and n i.e. (i * n) / gcd(i, n) 
        long long int lcm = (i * n) / gcd; 
  
        // Update sum 
        sum = sum + lcm; 
    } 
  
    cout<<sum; 
    return ;
} 

