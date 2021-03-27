// You are given:
// a positive integer n,
// an integer k, 1<=k<=n,
// an increasing sequence of k integers 0 < s1 < s2 < ... < sk <= 2n.
// What is the number of proper bracket expressions of length 2n with opening brackets appearing in positions s1, s2,...,sk?
// Illustration
// Several proper bracket expressions:
// [[]][[[]][]] 
// [[[][]]][][[]]
// An improper bracket expression:
// [[[][]]][]][[]]
// There is exactly one proper expression of length 8 with opening brackets in positions 2, 5 and 7.
// Task
// Write a program which for each data set from a sequence of several data sets:
// 1. reads integers n, k and an increasing sequence of k integers from input,
// 2. computes the number of proper bracket expressions of length 2n with opening brackets appearing at positions s1,s2,...,sk,
// 3. writes the result to output.
// Input
// The first line of the input file contains one integer d, 1 <= d <= 10, which is the number of data sets. The data sets follow. Each data set occupies two lines of the input file. The first line contains two integers n and k separated by single space, 1 <= n <= 19, 1 <= k <= n. The second line contains an increasing sequence of k integers from the interval [1;2n] separated by single spaces.
// Output
// The i-th line of output should contain one integer - the number of proper bracket expressions of length 2n with opening brackets appearing at positions s1, s2,...,sk.
// Sample Input
// 5 
// 1 1 
// 1 
// 1 1 
// 2 
// 2 1 
// 1 
// 3 1 
// 2 
// 4 2 
// 5 7 
// Sample Output
// 1 
// 0 
// 2 
// 3 
// 2 
#include <bits/stdc++.h>
using namespace std;
bool check[40];
int dp[40][40];
int fun(int o,int c,int n){
    if(o>n||c>n){
        return 0;
    }
    if(o==n&&c==n){
        return 1;
    }
    if(dp[o][c]!=-1){
        return dp[o][c];
    }
    if(o==c||check[o+c]){
        return dp[o][c]=fun(o+1,c,n);
    }
    else if(o==n){
        return dp[o][c]=fun(o,c+1,n);
    }
    else{
        return dp[o][c]=fun(o,c+1,n)+fun(o+1,c,n);
    }
}
int main()
{    int q;
     cin>>q;
     while(q--){
         int n,k;
         cin>>n>>k;
         memset(check,0,sizeof(check));
         for(int i=0;i<k;i++){
             int c;
             cin>>c;
             check[c-1]=true;
         }
         memset(dp,-1,sizeof(dp));
         cout<<fun(0,0,n)<<endl;
     }
    return 0;
}
