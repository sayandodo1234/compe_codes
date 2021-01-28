// Given a graph with N vertices (numbered from 0 to N-1) and M undirected edges, then count the distinct 3-cycles in the graph. A 3-cycle PQR is a cycle in which (P,Q), (Q,R) and (R,P) are connected by an edge.
// Input Format :
// The first line of input contains two space separated integers, that denotes the value of N and M.
// Each of the following M lines contain two integers, that denote the vertices which have an undirected edge between them. Let us denote the two vertices with the symbol u and v. 
// Output Format :
// Print the count the number of 3-cycles in the given graph
// Constraints :
// 0 <= N <= 100
// 0 <= M <= (N*(N-1))/2
// 0 <= u <= N - 1
// 0 <= v <= N - 1
// Time Limit: 1 sec
// Sample Input 1:
// 3 3
// 0 1
// 1 2
// 2 0
// Sample Output 1:
// 1
#include <iostream>
using namespace std;

int main() {
    // Write your code here
    int n ,m;
    cin>>n>>m ;
    int **edges = new int*[n] ;
    for(int i = 0;i<n ; i++){
        edges[i] = new int[n] ;
        for(int j=0 ; j<n; j++){
            edges[i][j] = 0 ;
        }
    }
    
    for(int i = 0 ; i<m ; i++){
        int f,s ;
        cin>>f>>s ;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    int count = 0 ;
    for(int i = 0 ; i<n-2 ; i++){
        for(int j = i+1 ; j<n-1 ;j++){
                for(int k = j+1; k<n ; k++){
                    if(edges[i][j]==1 && edges[j][k]==1 && edges[k][i]==1){
                            count++ ;
            
                    }
                }
            }

        }
    cout<<count<<endl ;
    return 0 ;
}