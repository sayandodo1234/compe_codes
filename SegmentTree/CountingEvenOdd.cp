// Ashu and Shanu are best buddies. One day Shanu gives Ashu a problem to test his intelligence.He gives him an array of N natural numbers and asks him to solve the following queries:-
// Query 0 :- modify the element present at index i to x.
// Query 1:- count the number of even numbers in range l to r inclusive.
// Query 2:- count the number of odd numbers in range l to r inclusive.
// Input:
// First line of the input contains the number N. Next line contains N natural numbers. 
// Next line contains an integer Q followed by Q queries.

// 0 x y - modify the number at index x to y. 

// 1 x y - count the number of even numbers in range l to r inclusive.

// 2 x y - count the number of odd numbers in range l to r inclusive.
// Constraints:
// 1<=N,Q<=10^5

// 1<=l<=r<=N 

// 0<=Ai<=10^9

// 1<=x<=N

// 0<=y<=10^9
// Note:-
// indexing starts from 1.
// Sample Input
// 6
// 1 2 3 4 5 6
// 4
// 1 2 5
// 2 1 4
// 0 5 4
// 1 1 6
// Sample Output
// 2
// 2
// 4
#include<bits/stdc++.h>
using namespace std;

struct node {
    int even ;
    int odd ;
} ;

void buildTree(int arr[] , node *tree , int start ,int end , int treeNode){
    if(start == end){
        
        if(arr[start] % 2 == 0){
            tree[treeNode].even = 1 ;
            tree[treeNode].odd = 0 ;
        }
        else{
            tree[treeNode].odd = 1 ;
            tree[treeNode].even = 0 ;
        }
        return ;
    }

    int mid = (start + end) / 2 ;
    buildTree(arr , tree , start , mid, 2*treeNode) ;
    buildTree(arr , tree , mid+1 , end , 2*treeNode + 1) ;
    node left = tree[2*treeNode] ;
    node right = tree[2*treeNode + 1] ;
    tree[treeNode].even = left.even + right.even ;
    tree[treeNode].odd = left.odd + right.odd ;

    return ;
}

void updateTree(int arr[],node *tree, int start ,int end ,int treeNode , int idx , int value){

    if(start == end){
        arr[idx] = value ;
        if(arr[idx] % 2 == 0){
            tree[treeNode].even = 1 ;
            tree[treeNode].odd = 0 ;
        }
        else{
            tree[treeNode].odd = 1 ;
            tree[treeNode].even = 0 ;
        }
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
    tree[treeNode].even = left.even + right.even ;
    tree[treeNode].odd = left.odd + right.odd ;

    return ;
}

node query(node *tree ,int start , int end, int treeNode ,int left , int right){
    //Completely outside given range 
    if(start > right || end <left){
        
        node temp ;
        temp.even  = 0 ;
        temp.odd = 0 ;
        return temp  ;
    }

    // Completely inside given range 
    if(start >= left && end <=right){
        
        
        return tree[treeNode] ;

    }

    //Partially inside partially outside 
    int mid= (start + end)/2;


    node ans1 = query(tree,start,mid,2*treeNode,left,right) ;
    node ans2 = query(tree,mid+1,end,2*treeNode + 1,left,right) ;
    
    node temp ;
    
    temp.even = ans1.even + ans2.even ;
    temp.odd = ans1.odd + ans2.odd ;
    

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
        int t ;
        cin>>t ;
        if(t == 0){
            int idx , value ;
            cin>>idx>>value ;
            updateTree(arr,tree,0,n-1,1,idx-1,value) ;
            
        }
        else{
            int l,r ;
            cin>>l>>r ;
            node temp = query(tree,0,n-1,1,l-1 ,r-1) ;
            if(t==1){
                cout<<temp.even<<endl ;
            }
            else{
                cout<<temp.odd<<endl ;
            }
        }
    }
    
    return 0;

}






