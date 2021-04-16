// Range Minimum Query
// Given an array A of size N, there are two types of queries on this array.
// 1) q l r: In this query you need to print the minimum in the sub-array A[l:r].
// 2) u x y: In this query you need to update A[x]=y.
// Input:
// First line of the test case contains two integers, N and Q, size of array A and number of queries.
// Second line contains N space separated integers, elements of A.
// Next Q lines contain one of the two queries.
// Output:
// For each type 1 query, print the minimum element in the sub-array A[l:r].
// Contraints:
// 1≤N,Q,y≤10^5
// 1≤l,r,x≤N
// Sample Input :
// 5 5
// 1 5 2 4 3
// q 1 5
// q 1 3
// q 3 5
// u 3 6
// q 1 5
// Sample Output :
// 1
// 1
// 2
// 1

#include<bits/stdc++.h>
using namespace std;

void buildTree(int arr[] , int *tree , int start ,int end , int treeNode){
    if(start == end){
        tree[treeNode] = arr[start] ;
        return ;
    }

    int mid = (start + end) / 2 ;
    buildTree(arr , tree , start , mid, 2*treeNode) ;
    buildTree(arr , tree , mid+1 , end , 2*treeNode + 1) ;
    // tree[treeNode] = tree[2*treeNode]+tree[2*treeNode + 1] ;
    tree[treeNode] = min(tree[2*treeNode],tree[2*treeNode + 1]) ;
    // min(buildTree(arr , tree , start , mid, 2*treeNode) ,buildTree(arr , tree , mid+1 , end , 2*treeNode + 1)) ;
    return ;
}

void updateTree(int arr[],int *tree, int start ,int end ,int treeNode , int idx , int value){

    if(start == end){
        arr[idx] =value ;
        tree[treeNode] = value ;
        return ;
    }
    int mid = (start + end) / 2 ;
    if(idx <= mid){
        updateTree(arr , tree , start , mid, 2*treeNode , idx , value) ;
    }
    else{
        updateTree(arr , tree , mid+1 , end , 2*treeNode + 1 , idx , value) ;
    }
    // tree[treeNode] = tree[2*treeNode] + tree[2*treeNode + 1] ;
    tree[treeNode] = min(tree[2*treeNode],tree[2*treeNode + 1]) ;
    return ;
}

int query(int *tree ,int start , int end, int treeNode ,int left , int right ){
    //Completely outside given range 
    if(start > right || end <left){
        return 1e6 ;
    }

    // Completely inside given range 
    if(start >= left && end <=right){
        return tree[treeNode] ;
    }

    //Partially inside partially outside 
    int mid= (start + end)/2;
    int ans1 = query(tree,start,mid,2*treeNode,left,right) ;
    int ans2 = query(tree,mid+1,end,2*treeNode + 1,left,right) ;
    return min(ans1,ans2) ;
}

int main() {

	// Write your code here
    int n , q;
    cin>>n>>q ;
    int arr[n] ;
    for(int i = 0 ; i<n ; i++){
        cin>>arr[i] ;
    }
    char t ;
    int l ,r ;
    int *tree = new int[4*n] ;
    
    buildTree(arr,tree,0,n-1,1) ;
    
    while(q--){
        cin>>t>>l>>r;
        int minm = 1e6 ;
        if(t == 'u'){
            updateTree(arr,tree,0,n-1,1,l-1,r) ;
        }
        if(t == 'q'){
            cout<<query(tree,0,n-1,1,l-1,r-1)<<endl ;
        }
    }
    
}


//