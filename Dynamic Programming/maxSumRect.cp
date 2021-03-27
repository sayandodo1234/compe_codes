// Given a 2D array, find the maximum sum rectangle in it. In other words find maximum sum over all rectangles in the matrix.
// Input
// First line contains 2 numbers n and m denoting number of rows and number of columns. Next n lines contain m space separated integers denoting elements of matrix nxm.
// Output
// Output a single integer, maximum sum rectangle.
// Constraints
// 1<=n,m<=100
// Sample Input
// 4 5
// 1 2 -1 -4 -20
// -8 -3 4 2 1
// 3 8 10 1 3
// -4 -1 1 7 -6
// Sample Output
// 29

#include <bits/stdc++.h>
using namespace std;
int top , bottom ;
int kadane(int *arr,int n){
    
    int curr = 0;
    int best = 0 ;
    int f=-1;
    for(int i = 0 ;i<n;i++){
        curr = curr + arr[i] ;
        if(curr > best){
            best = curr ;
            f++ ;
            
        }
        if(curr < 0){
            curr = 0 ;
        }
    }
    if(f != -1){
         return best ;
    }
    int neg_best = arr[0] ;
    
    for(int i = 1;i<n;i++){
        
        if(arr[i] > neg_best){
            neg_best = arr[i] ;
        }
    }
    
    return neg_best ;
   
    
}

int max_rect(int **arr,int n,int m){

    int best = INT_MIN ;
    
    for(int l = 0 ;l<=m-1;l++){
        int *sum = new int[n] ;
        for(int i = 0 ; i<n;i++){
            sum[i] = 0 ;
        }
        for(int r=l;r<=m-1;r++){
            
            for(int i = 0 ;i<n;i++){
                sum[i]+=arr[i][r];
            }
            
            best = max(best , kadane(sum,n));
            
        }
    }
    
    return best ;
    
    
}

int main()
{
    int n,m;
    cin>>n>>m;
    int **arr = new int*[n] ;
    for(int i=0;i<n;i++){
        arr[i] = new int[m] ;
    }
    for(int i = 0;i<n;i++){
        for(int j= 0 ;j<m ;j++){
            cin>>arr[i][j] ;       
        }
    }
    cout<<max_rect(arr,n,m)<<endl;
    return 0;
}
