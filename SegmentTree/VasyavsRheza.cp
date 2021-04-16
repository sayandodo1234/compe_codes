// Queen Vasya is preparing for a war against Rhezo. She has N warriors in total arranged in a line. Let us number the warriors by numbers from 1 to N. She will fight Rhezo's army for Q days, and each day she can choose only one warrior.
// For each warrior, we know 2 values associated with him, let us call these A and B. Each day Vasya can choose her warrior from a range Li to Ri, she must choose the warrior with maximum A value. If there is more than 1 warrior having the same maximum A value, she chooses the warrior with minimum B value. If still there is more than 1 warrior with same maximum A value and same minimum B value, she chooses the one with lower index in line.
// You being the hand of Queen Vasya, need to help her in choosing the warrior for each day.
// Input:
// First line contains a single integer N, denoting the number of warriors Queen Vasya has. 
// Second line contains N space separated integers Ai. Third line contains N space separated integers Bi.
// Next line contains a single integer Q, denoting the number of days Queen Vasya chooses a warrior. 
// Each of the next Q lines contains 2 integers Li and Ri.
// Output:
// For each Li and Ri, print the index of the warrior that Queen Vasya should choose.
// Constraints:
// 1≤ N,Q ≤10^6
// 1≤ Ai,Bi ≤10^9
// 1≤Li≤Ri
// Sample Input
// 5
// 1 8 4 6 8
// 4 8 6 3 7
// 4
// 1 4
// 2 4
// 3 4
// 1 5
// Sample Output
// 2
// 2
// 4
// 5

#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
struct war{
    ll A;
    ll B;
} ;
struct node{
    ll best_a ;
    ll best_b ;
    ll best_index ;
} ;
void build_tree(war *arr,node *tree ,ll start , ll end ,ll treeNode){
    if(start == end){
        tree[treeNode].best_a = arr[start].A ;
        tree[treeNode].best_b = arr[start].B ;
        tree[treeNode].best_index = start ;
        return ;
    }
    
    ll mid = (start+end)/2 ;
    build_tree(arr,tree,start,mid,2*treeNode);
    build_tree(arr,tree,mid+1,end,2*treeNode+1);
    node left = tree[2*treeNode] ;
    node right = tree[2*treeNode+1] ;
    
    if(left.best_a != right.best_a){
        if(left.best_a > right.best_a){
            tree[treeNode].best_a = left.best_a ;
            tree[treeNode].best_b = left.best_b ;
            tree[treeNode].best_index = left.best_index ;
            
        }
        else{
            tree[treeNode].best_a = right.best_a ;
            tree[treeNode].best_b = right.best_b ;
            tree[treeNode].best_index = right.best_index ;
        } 
    }
    else{
        if (left.best_b != right.best_b){
            if(left.best_b < right.best_b){
                tree[treeNode].best_a = left.best_a ;
                tree[treeNode].best_b = left.best_b ;
                tree[treeNode].best_index = left.best_index ;
            
            }
            else{
                tree[treeNode].best_a = right.best_a ;
                tree[treeNode].best_b = right.best_b ;
                tree[treeNode].best_index = right.best_index ;
           } 
        }
        else{
            
            if(left.best_index < right.best_index){
                tree[treeNode].best_a = left.best_a ;
                tree[treeNode].best_b = left.best_b ;
                tree[treeNode].best_index = left.best_index ;
            
            }
            else{
                tree[treeNode].best_a = right.best_a ;
                tree[treeNode].best_b = right.best_b ;
                tree[treeNode].best_index = right.best_index ;
           } 
            
        }
    }
    return ;
    
    
}

node query(node *tree,ll start,ll end ,ll treeNode, ll left , ll right){
    
    if(start >right || end <left){
        node temp ;
        temp.best_a = -1e6 ;
        temp.best_b = 1e6 ;
        temp.best_index = 1e6 ;
        return temp ;
    }
        
    if(start >= left && end <=right){
        return tree[treeNode] ;
    }
    
    
    
    ll mid = (start+end)/2 ;
    node left_node = query(tree,start,mid,2*treeNode,left,right);
    node right_node = query(tree,mid+1,end,2*treeNode+1,left,right);
    node temp ;
    
    if(left_node.best_a != right_node.best_a){
        if(left_node.best_a > right_node.best_a){
            temp.best_a = left_node.best_a ;
            temp.best_b = left_node.best_b ;
            temp.best_index = left_node.best_index ;
            
        }
        else{
            temp.best_a = right_node.best_a ;
            temp.best_b = right_node.best_b ;
            temp.best_index = right_node.best_index ;
        } 
    }
    else{
        if (left_node.best_b != right_node.best_b){
            if(left_node.best_b < right_node.best_b){
                temp.best_a = left_node.best_a ;
                temp.best_b = left_node.best_b ;
                temp.best_index = left_node.best_index ;
            
            }
            else{
                temp.best_a = right_node.best_a ;
                temp.best_b = right_node.best_b ;
                temp.best_index = right_node.best_index ;
           } 
        }
        else{
            
            if(left_node.best_index < right_node.best_index){
                temp.best_a = left_node.best_a ;
                temp.best_b = left_node.best_b ;
                temp.best_index = left_node.best_index ;
            
            }
            else{
                temp.best_a = right_node.best_a ;
                temp.best_b = right_node.best_b ;
                temp.best_index = right_node.best_index ;
           } 
            
        }
    }
    return temp ;
    
    
}
int main() {

	// Write your code here
    ll n;
    cin>>n ;
    war *arr = new war[n] ;
    for(ll i = 0 ; i<n ; i++){
        cin>>arr[i].A ;
    }
    for(ll i = 0 ; i<n ; i++){
        cin>>arr[i].B ;
    }
    node *tree = new node[4*n] ;
    build_tree(arr,tree,0,n-1,1);
    ll q ;
    cin>>q ;
    while(q--){
        ll l,r ;
        cin>>l>>r ;
        l-- ;
        r-- ;
        node res = query(tree,0,n-1,1,l,r) ;
        cout<<res.best_index+1<<endl ;
    }
}