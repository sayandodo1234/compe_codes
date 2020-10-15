// Given an integer N, find and return the count of unique Binary search trees (BSTs) are possible with nodes valued from 1 to N.
// Output count can be very large, so return the count modulo 10^9+7.
// Input Format :
// Integer n 
// Output Format :
// Count of BSTs
// Contraints :
// 1<= N <=1000
// Sample Input 1:
// 8
// Sample Output 1:
// 1430
// Sample Input 2:
// 3

#include<bits/stdc++.h>
using namespace std ;

typedef long long ll;
int countBST( int n)
{
  /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    ll m = pow(10,9) + 7;
    ll dp[n+1] ;
    for(int i = 0 ; i<=n;i++){
        dp[i] =0 ;
    }
    dp[0] = 1;
    dp[1] = 1 ;
    for(ll i = 2; i <= n;i++){
        for(ll j = 1;j <= i;j++){
            ll prev = (dp[i]%m + m)%m;
            ll left = dp[j-1] % m;
            ll right = dp[i-j] % m ;
            dp[i] = ((prev + (left * right)%m)%m +m)%m ;
        }
    }
    return dp[n] ;

    
    

}


