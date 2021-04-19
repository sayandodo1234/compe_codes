// Given a string S, you need to remove all the duplicates. That means, the output string should contain each character only once. The respective order of characters should remain same, as in the input string.
// Input format:
// The first and only line of input contains a string, that denotes the value of S.
// Output format :
// The first and only line of output contains the updated string, as described in the task.
// Constraints :
// 0 <= Length of S <= 10^8
// Time Limit: 1 sec
// Sample Input 1 :
// ababacd
// Sample Output 1 :
// abcd
// Sample Input 2 :
// abcde
// Sample Output 2 :
// abcde

#include<bits/stdc++.h>
using namespace std;
char* uniqueChar(char *str){
    // Write your code here
    int n= strlen(str);
    if(n==0)
    {
        char *temp = new char[1];
        temp[0] = '\0';
        return temp;
    }
    char *temp = new char[n+1];
    unordered_map<char,bool> m;
    int k=0;
    for(int i=0;i<n;i++)
    {
        char buff = str[i];
        if(m.count(buff) == 0)
        {
            m[buff] = true;
            temp[k] = buff;
            k++;
        }
    }
    temp[k] = '\0';
    return temp;

}