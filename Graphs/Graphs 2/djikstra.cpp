// Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
// Find and print the shortest distance from the source vertex (i.e. Vertex 0) to all other vertices (including source vertex also) using Dijkstra's Algorithm.
// Input Format :
// Line 1: Two Integers V and E (separated by space)
// Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
// Output Format :
// For each vertex, print its vertex number and its distance from source, in a separate line. The vertex number and its distance needs to be separated by a single space.
// Note : Order of vertices in output doesn't matter.
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
// 0 0
// 1 3
// 2 4
// 3 5

#include <bits/stdc++.h>
using namespace std;

   
// }
int get_min(bool *visited ,int* dist,int n){
    int min_v = -1 ;
    for(int i = 0 ; i<n ; i++){
        if(!visited[i] && ((min_v == -1) || (dist[min_v] > dist[i]))){
            min_v = i ;
        }
    }
    return min_v ;
}
void djikstra(int ** edges,int n , int e){
    bool * visited = new bool [n] ;
    int *dist = new int[n] ;
    int *parent = new int[n] ;
    for(int i = 0 ; i<n ; i++){
        dist[i] = 1e6 ;
        visited[i] = false ;
    }
    parent[0] = -1 ;
    dist[0] = 0 ;
    for(int i = 0 ;i <n; i++){
        int min_ver = get_min(visited,dist,n) ;
        visited[min_ver] = true ;
        for(int j = 0 ; j<n ; j++){
            if(edges[min_ver][j] != 0 && !visited[j]){
                if(dist[j] > dist[min_ver] + edges[min_ver][j]){
                    dist[j] = dist[min_ver] + edges[min_ver][j] ;
                }
            }
        }
    }
    
    for(int i = 0 ; i<n; i++){
        cout<<i<<" "<<dist[i]<<endl ;

    }
    
}
int main() {
    // Write your code here
    int n,e ;
    cin>>n>>e ;
    int **edges = new int*[n] ;
    for(int i = 0 ; i<n;i++){
        edges[i] = new int[n] ;
        for(int j = 0 ; j<n;j++){
            edges[i][j] = 0 ;
        }
    }
    for(int i = 0 ; i<e ; i++){
        int f,s,w ;
        cin>>f>>s>>w;
        edges[f][s] = w ;
        edges[s][f] = w ;
    }
    djikstra(edges,n,e) ;
    return 0 ;
}