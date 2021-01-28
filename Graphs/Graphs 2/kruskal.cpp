// Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
// Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.
// For printing MST follow the steps -
// 1. In one line, print an edge which is part of MST in the format - 
// v1 v2 w
// where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1  <= v2 i.e. print the smaller vertex first while printing an edge.
// 2. Print V-1 edges in above format in different lines.
// Note : Order of different edges doesn't matter.
// Input Format :
// Line 1: Two Integers V and E (separated by space)
// Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
// Output Format :
// Print the MST, as described in the task.
// Constraints :
// 2 <= V, E <= 10^5
// Time Limit: 1 sec
// Sample Input 1 :
// 4 4
// 0 1 3
// 0 3 5
// 1 2 1
// 2 3 8
// Sample Output 1 :
// 1 2 1
// 0 1 3
// 0 3 5

#include <bits/stdc++.h>
using namespace std;

class edge{
    public:
    int src;
    int des;
    int wt ;
} ;
int getParent(int v,int *parent){
    if(parent[v]==v){
        return v ;
    }
    
    return getParent(parent[v],parent) ;
}
bool weight_sort(edge e1 , edge e2){
    return e1.wt < e2.wt ;
}
vector<edge> kruskal(edge *input,int n ,int e){
    sort(input,input+e,weight_sort) ;
    // edge *output = new edge[n-1] ;
    vector<edge> output;
    int * parent = new int[n] ;
    for(int i = 0 ;i<n ; i++){
        parent[i] = i ;
    }
    int count = 0 ;
    int i=0, j =1 ;
    while(count < n-1){
        edge curr = input[i] ;
        int src_parent = getParent(curr.src,parent) ;
        int des_parent = getParent(curr.des,parent) ;
        if(src_parent != des_parent){
            // output[count] = curr ;
            count++ ;
            output.push_back(curr);
            parent[src_parent] = des_parent ;
        }
        i++;
    }
    return output ;
}

int main() {
    // Write your code here
    int n,e ;
    cin>>n>>e ;
    edge * input = new edge[e] ;
    for(int i = 0 ; i<e ; i++){
        int f,s,w ;
        cin>>f>>s>>w;
        input[i].src = f ;
        input[i].des = s;
        input[i].wt = w ;
    }
    vector<edge> ans;
    // edge * ans = new edge[e] ;
    ans =kruskal(input,n,e) ;
    
    for(int i = 0; i<ans.size() ; i++){
        if(ans[i].src < ans[i].des){
            cout<<ans[i].src<<" "<<ans[i].des<<" "<<ans[i].wt<<endl;
        }
        else{
            cout<<ans[i].des<<" "<<ans[i].src<<" "<<ans[i].wt<<endl;
        }
    }

    
    
    return 0 ;
}