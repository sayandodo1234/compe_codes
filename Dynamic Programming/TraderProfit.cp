// Mike is a stock trader and makes a profit by buying and selling stocks. He buys a stock at a lower price and sells it at a higher price to book a profit. He has come to know the stock prices of a particular stock for n upcoming days in future and wants to calculate the maximum profit by doing the right transactions (single transaction = buying + selling). Can you help him maximize his profit?
// Note: A transaction starts after the previous transaction has ended. Two transactions can't overlap or run in parallel.
// The stock prices are given in the form of an array A for n days.
// Given the stock prices and a positive integer k, find and print the maximum profit Mike can make in at most k transactions.
// Input Format
// The first line of input contains an integer q denoting the number of queries.

// The first line of each test case contains a positive integer k, denoting the number of transactions. 

// The second line of each test case contains a positive integer n, denoting the length of the array A.

// The third line of each test case contains n space-separated positive integers, denoting the prices of each day in the array A.
// Constraints
// 1<=q<=100

// 0<k<10

// 2<=n<=30

// 0<=elements of array A<=1000
// Output Format
// For each query print the maximum profit earned by Mike on a new line. 
// Sample Input
// 3
// 2
// 6
// 10 22 5 75 65 80
// 3
// 4
// 20 580 420 900
// 1
// 5
// 100 90 80 50 25
// Sample Output
// 87
// 1040
// 0


#include <bits/stdc++.h>
using namespace std;
int dp[31][11][2];


int f(int i,int n,int K,int ong,int *arr){
    
    if(n==0 ){
        return 0;
    }
    
    if(dp[i][K][ong] != -1){
        return dp[i][K][ong] ;
    }
    
    int o1 = f(i+1,n-1,K,ong,arr) ;
    if(ong == 1){
        int o2 =f(i+1,n-1,K-1,0,arr) + arr[i] ;
        o1=max(o1,o2);
    }
    else{
        if(K==0){
            o1=0;
        }
        else{
            int o2 = f(i+1,n-1,K,1,arr) - arr[i] ;
            o1=max(o1,o2);
        }
    } 
    dp[i][K][ong] = o1;
    
    return dp[i][K][ong] ;
}

int main()
{
    int q ;
    cin>>q ; 
    
    while(q--){
        
        int i,j,k,K,n ;
        cin>>K ;
        cin>>n;
        int *arr = new int[n] ;
        
        for(i = 0 ; i<n ; i++){
            cin>>arr[i] ;
        }
        for(int i = 0 ; i<31 ; i++){
            for(j = 0 ; j<11 ; j++){
                dp[i][j][0] = -1 ;
                dp[i][j][1] = -1 ;
            }
        }
        
        cout<<f(0,n,K,0,arr)<<endl ;
        
        
        
    }
    
    return 0;
    
}