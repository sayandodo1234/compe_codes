// Given two strings, S and T with lengths M and N, find the length of the 'Longest Common Subsequence'.
// For a string 'str'(per se) of length K, the subsequences are the strings containing characters in the same relative order as they are present in 'str,' but not necessarily contiguous. Subsequences contain all the strings of length varying from 0 to K.
// Example :
// Subsequences of string "abc" are:  ""(empty string), a, b, c, ab, bc, ac, abc.
// Input format :
// The first line of input contains the string S of length M.

// The second line of the input contains the String T of length N.
// Output format :
// Print the length of the 'Longest Common Subsequence'.
// Constraints :
// 0 <= M <= 10 ^ 3
// 0 <= N <= 10 ^ 3

// Time Limit: 1sec
// Sample Input 1 :
// adebc
// dcadb
// Sample Output 1 :
// 3
// Explanation of the Sample Input 1 :
// Both the strings contain a common subsequence 'adb', which is the longest common subsequence with length 3. 
// Sample Input 2 :
// ab
// defg
// Sample Output 2 :
// 0
// Explanation of the Sample Input 2 :
// The only subsequence that is common to both the given strings is an empty string("") of length 0.

int lcs(string s1, string s2)
{
    //Write your code here
    int m = s1.size() ;
    int n = s2.size() ;
    int LCS[m+1][n+1];
    for(int i = 0 ; i<=m ;i++){
        LCS[i][0] = 0 ;
    }
    for(int i = 0 ; i<=n ;i++){
        LCS[0][i] = 0 ;
    }
    for(int i = 1 ; i<=m;i++){
        for(int j = 1 ; j<=n ; j++){
            if(s1[i-1] == s2[j-1]){
                LCS[i][j] = 1 + LCS[i-1][j-1];
            }
            else{
                LCS[i][j] = max(LCS[i-1][j],LCS[i][j-1]);
            }
        }
    }
    
    return LCS[m][n];
    
}