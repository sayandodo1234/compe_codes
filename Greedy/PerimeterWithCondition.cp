// AAahad gives an array of integers and asks Harshit to find which three elements form a triangle (non-degenerate). The task seems easy to Harshit.
// So, Aahad adds some conditions to this task -
// 1. Find the triangle with maximum perimeter
// 2. If there are two or more combinations with same value of maximum perimeter, then find the one with the longest side.
// 3.If there are more than one combinations which satisfy all the above conditions the find with maximum longest minimum side.
// Input Format
// The First line contains no of elements of array: N
// Each T lines contains N space-separated integers: A [i]
// Output Format
// The output contains three space-separated elements that denote the length of the sides of triangle. If no such triangle is possible, then print -1.
// Constraints
// 1 =< N <= 10^5 
// 1 <= A[i] <= 10^9
// Time Limit: 1 second
// Sample Input1:
// 5
// 1 1 1 3 3
// Sample Output1:
// 1 3 3 
// Sample Input2:
// 3
// 2 2 4
// Sample Output3:
// -1 
// Explaination
// In the First Sample case, the elements that form a triangle with maximum perimeter is 1,3,3.
// In the Second Sample case, the elements that can form a triangle are degenerate, so, we printed -1.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll ;

bool check_tri(int x , int y , int z){
    if((x+y)>z && (x+z)>y && (y+z)>x){
        return true ;
    }
    
    return false ;
    
}
int main() {

	// Write your code here
    
    int n ; 
    cin>>n ;
    ll *arr = new ll[n] ;
    int i ;
    for(i = 0 ; i<n ; i++){
        cin>>arr[i] ;
    }
    
    sort(arr,arr+n,greater<int>()) ;
    ll max_p = -1e9 ;
    
    ll l_side , s_side ,m_side;
    
    for(int i = 0 ; i<n-2 ; i++){
        if(check_tri(arr[i],arr[i+1],arr[i+2])){
            
            
        ll sum = arr[i] + arr[i+1] + arr[i+2] ;
        if(sum > max_p){
            max_p = sum ;
            l_side = arr[i] ;
            m_side = arr[i+1] ;
            s_side = arr[i+2] ;
        }
        else if( sum == max_p){
            if(l_side < arr[i]){
                l_side = arr[i] ;
                m_side = arr[i+1] ;
                s_side = arr[i+2] ;
            }
            else if(l_side == arr[i]){
                if(s_side < arr[i+2]){
                    l_side = arr[i] ;
                    m_side = arr[i+1] ;
                    s_side = arr[i+2] ;
                }
            }
        }
            
        }

    }
    if(max_p == -1e9){
        cout<<-1<<endl;
    }
    else{
        cout<<s_side<<" "<<m_side<<" "<<l_side<<endl;
    }
    
}