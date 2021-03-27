// Gary has two string S and V. Now, Gary wants to know the length shortest subsequence in S, which is not a subsequence in V.
// Note: The input data will be such that there will always be a solution.
// Input Format :
// The first line of input contains a string, that denotes the value of S. The following line contains a string, that denotes the value of V.
// Output Format :
// Length of shortest subsequence in S such that it is not a subsequence in V
// Constraints:
// 1 <= N <= 1000
// 1 <= M <= 1000 
// Time Limit: 1 second
// Sample Input 1:
// babab
// babba
// Sample Output 1:
// 3
// Explanation:
// "aab" is the shortest subsequence which is present in S and absent in V.

int solve(string S,string V)
{
	// Write your code here.
    
    int m = S.size() ;
    int n = V.size() ;
    
    int dp[m+1][n+1] ;
    
    for(int i = 0 ;i<=m ; i++){
        dp[i][0] = 1 ;
    }
    
    for(int i = 0 ;i<=n ; i++){
        dp[0][i] = 100000 ;
    }
    
    for(int i = 1 ; i<=m ; i++){
        for(int j = 1 ; j<=n ; j++){
            int pos = -1 ;
            for(int k = j-1 ; k>=0 ;k--){
                if(S[i-1] == V[k]){
                    pos = k ;
                    break ;
                }
            }
            
            if(pos == -1){
                dp[i][j]=1;
              
            }
            else{
                dp[i][j] = min(dp[i-1][j],1+dp[i-1][pos]) ;  
                
            }
            
        }
    }
    
    return dp[m][n] ;
    
}