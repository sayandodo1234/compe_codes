// You are given a sequence A[1], A[2], ..., A[N], ( 0 ≤ A[i] ≤ 10^8 , 2 ≤ N ≤ 10^5 ). There are two types of operations and they are defined as follows:
// Update:
// This will be indicated in the input by a 'U' followed by space and then two integers i and x.
// U i x, 1 ≤ i ≤ N, and x, 0 ≤ x ≤ 10^8.
// This operation sets the value of A[i] to x.
// Query:
// This will be indicated in the input by a 'Q' followed by a single space and then two integers i and j.
// Q x y, 1 ≤ x < y ≤ N.
// You must find i and j such that x ≤ i, j ≤ y and i != j, such that the sum A[i]+A[j] is maximized. Print the sum A[i]+A[j].
// Input
// The first line of input consists of an integer N representing the length of the sequence. 
// Next line consists of N space separated integers A[i]. Next line contains an integer Q, Q ≤ 10^5, representing the number of operations. Next Q lines contain the operations.
// Output
//  Output the maximum sum mentioned above, in a separate line, for each Query.
// Input:
// 5
// 1 2 3 4 5
// 6
// Q 2 4
// Q 2 5
// U 1 6
// Q 1 5
// U 1 7
// Q 1 5
// Output:
// 7
// 9
// 11
// 12
#include<bits/stdc++.h>
using namespace std;

struct node {
    int maxm ;
    int smaxm ;
} ;

void buildTree(int arr[] , node *tree , int start ,int end , int treeNode){
    if(start == end){
        tree[treeNode].maxm = arr[start] ;
        tree[treeNode].smaxm = INT_MIN ;
        return ;
    }

    int mid = (start + end) / 2 ;
    buildTree(arr , tree , start , mid, 2*treeNode) ;
    buildTree(arr , tree , mid+1 , end , 2*treeNode + 1) ;
    node left = tree[2*treeNode] ;
    node right = tree[2*treeNode + 1] ;
    tree[treeNode].maxm = max(left.maxm,right.maxm) ;
    tree[treeNode].smaxm = min(max(left.maxm,right.smaxm),max(left.smaxm,right.maxm)) ;
    return ;
}

void updateTree(int arr[],node *tree, int start ,int end ,int treeNode , int idx , int value){

    if(start == end){
        arr[idx] = value ;
        tree[treeNode].maxm = value ;
        tree[treeNode].smaxm = INT_MIN ;
        return ;
    }
    int mid = (start + end) / 2 ;
    if(idx <= mid){
        updateTree(arr , tree , start , mid, 2*treeNode , idx , value) ;
    }
    else{
        updateTree(arr , tree , mid+1 , end , 2*treeNode + 1 , idx , value) ;
    }
    node left = tree[2*treeNode] ;
    node right = tree[2*treeNode + 1] ;
    tree[treeNode].maxm = max(left.maxm,right.maxm) ;
    tree[treeNode].smaxm = min(max(left.maxm,right.smaxm),max(left.smaxm,right.maxm)) ;

    return ;
}

node query(node *tree ,int start , int end, int treeNode ,int left , int right){
    //Completely outside given range 
    if(start > right || end <left){
        
        node temp ;
        temp.maxm  = INT_MIN ;
        temp.smaxm  = INT_MIN ;
        return temp  ;
    }

    // Completely inside given range 
    if(start >= left && end <=right){
        
        node temp ;
        temp.maxm  = tree[treeNode].maxm ;
        temp.smaxm  = tree[treeNode].smaxm ;
        return temp ;
    }

    //Partially inside partially outside 
    int mid= (start + end)/2;
    node ans1 = query(tree,start,mid,2*treeNode,left,right) ;
    node ans2 = query(tree,mid+1,end,2*treeNode + 1,left,right) ;
    
    node temp ;
    
    
    temp.maxm = max(ans1.maxm,ans2.maxm) ;
    temp.smaxm = min(max(ans1.maxm,ans2.smaxm),max(ans1.smaxm,ans2.maxm)) ;
    

    return temp ;
}

int main() {

	// Write your code here
    
    int n , q;
    cin>>n ;
    int arr[n] ;
    for(int i = 0 ; i<n ; i++){
        cin>>arr[i] ;
    }
    node *tree = new node[3*n] ;
    buildTree(arr,tree,0,n-1,1) ;
    cin>>q ;
    while(q--){
        char t ;
        cin>>t ;
        if( t == 'U'){
            int idx , value ;
            cin>>idx>>value ;
            updateTree(arr,tree,0,n-1,1,idx-1,value) ;
            
        }
        else{
            int l,r ;
            cin>>l>>r ;
            node temp = query(tree,0,n-1,1,l-1 ,r-1) ;
            cout<<temp.maxm + temp.smaxm <<endl;
        }
    }
    
    return 0;
}