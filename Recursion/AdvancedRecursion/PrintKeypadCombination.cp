// Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
// Note : The order of strings are not important. Just print different strings in new lines.
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

#include <iostream>
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

void printKeypad(int num){
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */
    // string output  = "";
    // printkeypad(num,output);
    string output[1000];
    int s = keypad(num,output);
    for(int i = 0;i<s;i++)
    {
        cout<<output[i]<<endl;
    }
}
