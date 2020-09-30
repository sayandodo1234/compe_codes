// Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
// This number can be huge, so return output modulus 10^9 + 7.
// Write a simple recursive solution.
// Input Format :
// Integer h
// Output Format :
// Count % 10^9 + 7
// Input Constraints :
// 1 <= h <= 40
// Sample Input 1:
// 3
// Sample Output 1:
// 15
// Sample Input 2:
// 4
// Sample Output 2:
// 315

#include<bits/stdc++.h>
using namespace std;

typedef long long ll ;
ll balancedBTs(int h) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return the output and don’t print it.
  */
    
    ll m = pow(10,9) + 7;
    ll dp[h + 1] ;
    dp[0] = dp[1] = 1; 
    for(ll i = 2; i <= h; i++) { 
        dp[i] = (dp[i - 1] * ((2 * dp [i - 2])%m + dp[i - 1])%m) % m; 
    } 
    return dp[h]; 

}
