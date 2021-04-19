// Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
// Return empty string for numbers 0 and 1.
// Note : 1. The order of strings are not important.
// 2. Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.
// Input Format :
// Integer n
// Output Format :
// All possible strings in different lines
// Constraints :
// 1 <= n <= 10^6
// Sample Input:
// 23
// Sample Output:
// ad
// ae
// af
// bd
// be
// bf
// cd
// ce
// cf
#include <string>
#include<bits/stdc++.h>
using namespace std;

const char keys[10][5] = {"", "", "abc", "def", "ghi", "jkl", 
                               "mno", "pqrs", "tuv", "wxyz"};
int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    if (num==0)
    {
        output[0] = "";
        return 1;
    }
    int new_num = num/10;
    int rem = num % 10 ;
    int size = keypad(new_num,output);
    
    if(rem == 1 || rem == 0)
    {
        return 1 ;
    }
    
    int key_size = 3;
    if (rem == 7 || rem == 9)
        key_size = 4;
    int new_size = key_size * size ;
    string temp[new_size];
    int k =0;
    
    for(int i=0 ; i<size;i++)
    {
        for(int j = 0 ;j<key_size ; j++)
        {
            string buff = output[i];
            buff.push_back(keys[rem][j]);
            temp[k] = buff;
            k++;
        }
        
    }
    
    for(int i =0 ; i< new_size;i++)
    {
        output[i] = temp[i];
    }
    return new_size;
        
}
