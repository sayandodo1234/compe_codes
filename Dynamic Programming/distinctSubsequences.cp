// Given a string, count the number of distinct subsequences of it ( including empty subsequence ). For the uninformed, A subsequence of a string is a new string which is formed from the original string by deleting some of the characters without disturbing the relative positions of the remaining characters.
// For example, "AGH" is a subsequence of "ABCDEFGH" while "AHG" is not.
// Input
// First line of input contains an integer T which is equal to the number of test cases. You are required to process all test cases. Each of next T lines contains a string s.
// Output
// Output consists of T lines. Ith line in the output corresponds to the number of distinct subsequences of ith input string. Since, this number could be very large, you need to output ans%1000000007 where ans is the number of distinct subsequences. 
// Constraints and Limits
// T ≤ 100, length(S) ≤ 100000

// All input strings shall contain only uppercase letters.
// Sample Input
// 3
// AAA
// ABCDEFG
// CODECRAFT
// Sample Output
// 4
// 128
// 496
#include <bits/stdc++.h>
using namespace std;

typedef long long ll ;
ll m = pow(10,9) + 7 ;
int main()
{
    int t;
    cin>>t ;
    while(t--){
        string s;
        cin>>s;
        int n  = s.size() ;
        
        ll dp[n+1] ;
        for(int i = 0 ; i<n ; i++){
            dp[i] = 0 ;
        }
        dp[0] = 1 ;
        
        ll last[27] ;
        for(int i = 0 ; i<27 ; i++){
            last[i] = -1 ;
        }
        
        for(int i = 1 ; i<=n ; i++){
            dp[i] = (2*dp[i-1]) % m;
            
            int ch = s[i-1] - 'A' ;
            if(last[ch] != -1){
                dp[i] = (dp[i] - dp[last[ch]] + m)%m ;
            }
            
            last[ch] = i-1 ;

        }
        cout<<dp[n]<<endl;
    }
    return 0;
    
}


