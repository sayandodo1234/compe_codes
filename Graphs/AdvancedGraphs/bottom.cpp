// We will use the following (standard) definitions from graph theory. Let V be a non-empty and finite set, its elements being called vertices (or nodes). Let E be a subset of the Cartesian product V×V, its elements being called edges. Then G=(V,E) is called a directed graph.

// Let n be a positive integer, and let p=(e1,…,en) be a sequence of length n of edges ei∈E such that ei=(vi,vi+1)for a sequence of vertices (v1,…,vn+1). Then p is called a path from vertex v1 to vertex vn+1 in G and we say that vn+1 is reachable from v1, writing (v1→vn+1).

// Here are some new definitions. A node v in a graph G=(V,E) is called a sink, if for every node w in G that is reachable from v, v is also reachable from w. The bottom of a graph is the subset of all nodes that are sinks, i.e., bottom(G)={v∈V∣∀w∈V:(v→w)⇒(w→v)}. You have to calculate the bottom of certain graphs.
// Input Specification
// The input contains several test cases, each of which corresponds to a directed graph G. Each test case starts with an integer number v, denoting the number of vertices of G=(V,E) where the vertices will be identified by the integer numbers in the set V={1,…,v}. You may assume that 1≤v≤5000. That is followed by a non-negative integer e and, thereafter, e pairs of vertex identifiers v1,w1,…,ve,we with the meaning that (vi,wi)∈E. There are no edges other than specified by these pairs. The last test case is followed by a zero.
// Output Specification
// For each test case output the bottom of the specified graph on a single line. To this end, print the numbers of all nodes that are sinks in sorted order separated by a single space character. If the bottom is empty, print an empty line.
// Sample Input
// 3 3
// 1 3 2 3 3 1
// 2 1
// 1 2
// 0
// Sample Output
// 1 3
// 2

#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
ll id = 0 ;

void dfs(vector<ll>* g ,ll sv, bool* onS , ll* dfsn,ll* low,stack<ll>& s){
    low[sv] = dfsn[sv] = id++ ; 
    s.push(sv) ; 
    onS[sv] = true ; 
    for(ll i = 0 ; i<g[sv].size();i++){ 
        ll curr = g[sv][i] ; 
        if(dfsn[curr] == -1){
            dfs(g,curr,onS,dfsn,low,s) ; 
            low[sv] = min(low[sv],low[curr]) ; 
        } 
        else if (onS[curr]){
            low[sv] = min(low[sv],dfsn[curr]) ; 
        } 
        
    }
    if (low[sv] == dfsn[sv]){
        while(!s.empty()){ 
            ll curr = s.top() ; 
            s.pop() ; 
            onS[curr] = false ; 
            low[curr] = dfsn[sv] ;
            if(curr == sv){
                break ;
            }
        }
    }
}

void tarjan(vector<ll>* g, ll n, bool* onS , ll* dfsn,ll* low){
    id = 0;
    stack<ll> s ;
    for(ll i = 0 ; i<n; i++){ 
        if(dfsn[i] == -1){ 
            dfs(g,i,onS,dfsn,low,s) ; 
        }
    }
}


int main()
{
	//code
    while(1){
        ll n,e ;
        cin>>n ;
        if(n==0){
            break ;
        }
        cin>>e ;
        vector<ll>* g = new vector<ll>[n] ;
        
        while(e--){
            ll f,s ;
            cin>>f>>s ;
            f-- ; 
            s-- ;
            g[f].push_back(s) ;
        }
       
        bool *stat = new bool[n] ;
        bool *onS = new bool[n] ;
        ll *dfsn = new ll[n] ;
        ll *low = new ll[n] ;
       
        for(ll i = 0 ; i<n ; i++){
            
            low[i] = -1 ;
            dfsn[i] = -1 ;
            onS[i] = false ;
            stat[i] = true ;
        }
        
        tarjan(g,n,onS,dfsn,low) ;
        
        for(ll i = 0 ; i<n; i++){
            for(ll j = 0 ; j<g[i].size(); j++){
                ll curr = g[i][j] ;
                if(low[i] != low[curr]){
                    stat[low[i]] = false ;
                    break ;
                }
            }
        }
        
        for(ll i = 0 ; i<n; i++){
            if(stat[low[i]]){
                cout<<i+1<<" " ;
            }
        }
        cout<<endl ;
        
    }
	return 0;
}
