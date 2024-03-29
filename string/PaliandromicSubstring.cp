// Given a string S, count and return the number of substrings of S that are palindrome.
// Single length substrings are also palindromes. You just need to calculate the count, not the substrings.
// Input Format :
// String S
// Output Format :
// count of palindrome substrings
// Constraints :
// 1 <= Length of S <= 1000
// Sample Input :
// aba
// Sample Output :
// 4
// **Note : Here 4 corresponds to ("a","b","a","aba").

#include<bits/stdc++.h>
using namespace std;
int lps(string s){
    int max = 0 ;
    int n = s.length() ;
    int count = 0 ;
    for(int i = 0 ; i<n; i++){
        // odd length
        int l = i ;
        int r = i ;
        while(l >= 0 && r<n && s[l] == s[r]){

            count++;
            l--;
            r++;
        }
        // Even length
        l = i ;
        r = i+1 ;
        while(l >= 0 && r<n && s[l] == s[r]){

            count++ ;
            l--;
            r++;
        }
                  
    }

    return count ;
}



int countPalindromeSubstrings(char s[]) {
	// Write your code here
    
    string str(s) ;
	return lps(str) ;
}
