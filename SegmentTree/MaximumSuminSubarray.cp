// You are given a sequence A[1], A[2], ..., A[N] . ( |A[i]| ≤ 15007 , 1 ≤ N ≤ 50000 ). A query is defined as follows:
// Query(x,y) = Max { a[i]+a[i+1]+...+a[j] ; x ≤ i ≤ j ≤ y }.
// Given M queries, your program must output the results of these queries.
// Input
// The first line of the input file contains the integer N.
// In the second line, N numbers follow.
// The third line contains the integer M.
// M lines follow, where line i contains 2 numbers xi and yi.
// Output
// Your program should output the results of the M queries, one 
// query per line.
// Sample Input:
// 3 
// -1 2 3 
// 1
// 1 2
// Sample Output:
// 2

#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
struct node{
    ll sum ;
    ll max_sum ;
    ll bps ;
    ll bss ;
} ;


void build_tree(ll *arr, node * tree, ll start , ll end , ll treeNode){
    
    if(start > end){
        return ;
    }
   
    if(start == end){
        tree[treeNode].sum = arr[start] ;
        tree[treeNode].max_sum = arr[start] ;
        tree[treeNode].bps = arr[start] ;
        tree[treeNode].bss = arr[start] ;
        return ;
    }
    
    ll mid = (start+end)/2 ;
    build_tree(arr,tree,start,mid,2*treeNode) ;
    build_tree(arr,tree,mid+1,end,2*treeNode+1) ;
    node ans1 = tree[2*treeNode] ;
    node ans2 =  tree[2*treeNode + 1] ;
    tree[treeNode].sum = ans1.sum + ans2.sum ;
    tree[treeNode].max_sum = max(max(ans1.max_sum, ans2.max_sum), max(ans1.sum+ans2.bps, max(ans2.sum + ans1.bss,ans1.bss + ans2.bps))) ;
    tree[treeNode].bps = max(ans1.bps , ans1.sum + ans2.bps) ;
    tree[treeNode].bss = max(ans2.bss , ans2.sum + ans1.bss) ;
    return ;
}



node query(ll *arr, node *tree , ll start , ll end , ll treeNode, ll left, ll right){
    
    if(start > right || end < left){
        node temp ;
        temp.sum = INT_MIN;
        temp.max_sum = INT_MIN ;
        temp.bps = INT_MIN ;
        temp.bss = INT_MIN ;
        return temp ;
    }
    
    if(start >= left && end <= right){
        return tree[treeNode] ;
    }
    
    node temp ;
    ll mid = (start+end)/2 ;
    node ans1 = query(arr,tree,start,mid,2*treeNode,left,right) ;
    node ans2 =  query(arr,tree,mid+1,end,2*treeNode+1,left,right) ;
    temp.sum = ans1.sum + ans2.sum ;
    temp.max_sum = max(max(ans1.max_sum, ans2.max_sum), max(ans1.sum+ans2.bps, max(ans2.sum + ans1.bss,ans1.bss + ans2.bps))) ;
    temp.bps = max(ans1.bps , ans1.sum + ans2.bps) ;
    temp.bss = max(ans2.bss , ans2.sum + ans1.bss) ;
    return temp;
    
}
int main() {

	// Write your code here
    ll n , m;
    cin>>n ;
    ll *arr = new ll[n] ;
    for(ll i = 0 ; i<n ; i++){
        cin>>arr[i] ;
    }
    node *tree = new node[4*n] ;
    build_tree(arr,tree,0,n-1,1);
    cin>>m ;
    while(m--){
        ll x,y ;
        cin>>x>>y ;
        x--;
        y--;
        node res = query(arr,tree,0,n-1,1,x,y);
        cout<<res.max_sum<<endl;
    }
    return 0 ;
}

