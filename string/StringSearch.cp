// Given two strings S and T, write a function to find if T is present as a substring inside S or not. If yes, return the starting index otherwise return -1.
// Input format :

// Line 1 : String S

// Line 2 : String T

// Sample Input 1:
// WelcomeBack
// come 
// Sample Output 1:
// 3
// Sample Input 2:
// WelcomeBack
// code
// Sample Output 2:
// -1

// S and T - input strings
// You need to check if string T is present in S or not

#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
void buildZ(int *Z,string str){
    int l = 0 ;
    int r = 0 ;
    int n = str.length() ;
    for(int i = 1; i<n ; i++){

        if(i>r){
            // i does not lie between l and r
            // Z for this does not exist
            l=i;
            r=i;
            while(r<n && str[r-l] == str[r]){
                r++;
            }
            Z[i] = r-l ;
            r--;
        }else{
            int k = i-l;
            if(Z[k] <= r-i){
                // it lies between l and r
                // z will exist previously
                Z[i] = Z[k] ;
            }else{
                // some part of Z is already included
                // You have to start matching further
                l = i ;
                while(r<n && str[r-l] == str[r]){
                    r++ ;
                }
                Z[i] = r-l;
                r--;
            }
        }

    }
}
int searchString(string text , string pattern){
    string str = pattern + "$" + text ;
    int n = str.length() ;
    int *Z = new int[n]() ;
    buildZ(Z,str);
    for(int i = 0 ; i<n; i++){
        if(Z[i] == pattern.length()){
            int curr = i - pattern.length() - 1 ;
            // cout<<i - pattern.length() - 1<<endl ;
            return curr ;
        }
    }
    return -1;

}

int findString(char S[], char T[]) {
    // Write your code here
    
    int s_len = strlen(S) ;
    int t_len = strlen(T) ;
    string text(S) ;
    string pattern(T) ;
    
    return searchString(text,pattern) ;

}
