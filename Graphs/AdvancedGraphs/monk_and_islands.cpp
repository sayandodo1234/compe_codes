// Monk visits the land of Islands. There are a total of N islands numbered from 1 to N. Some pairs of islands are connected to each other by Bidirectional bridges running over water.
// Monk hates to cross these bridges as they require a lot of efforts. He is standing at Island #1 and wants to reach the Island #N. Find the minimum the number of bridges that he shall have to cross, if he takes the optimal route.
// Input:
// First line contains T. T testcases follow.
// First line of each test case contains two space-separated integers N, M.
// Each of the next M lines contains two space-separated integers X and Y , denoting that there is a bridge between Island X and Island Y.
// Output:
// Print the answer to each test case in a new line.
// Constraints:
// 1 ≤ T ≤ 10
// 1 ≤ N ≤ 10000
// 1 ≤ M ≤ 100000
// 1 ≤ X, Y ≤ N
// SAMPLE INPUT
// 2
// 3 2
// 1 2
// 2 3
// 4 4
// 1 2
// 2 3
// 3 4
// 4 2
// SAMPLE OUTPUT
// 2
// 2

#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;


ll bfs(vector<ll> *g , int n , int sv,bool* visited,ll *d)
{
    queue<ll> q ;
    q.push(sv);
    visited[sv] = true ;
    d[sv] = 0 ;
    while(!q.empty()){
        ll curr = q.front();
        q.pop();
        for(int i = 0 ; i< g[curr].size() ; i++)
        {
            ll temp = g[curr][i] ;

            if(!visited[temp]){
                q.push(temp);
                visited[temp] = true ; 
                d[temp] = d[curr] + 1 ;
            }
        }
        
    }
    return d[n-1] ;
}

int main()
{
	//code
    ll t ;
    cin>>t ;
    while(t--){
        ll n,m ;
        cin>>n>>m ;
        vector<ll> *g= new vector<ll>[n] ;
        while(m--){
            ll x, y;
            cin>>x>>y ;
            x-- ;
            y-- ;
            g[x].push_back(y) ;
            g[y].push_back(x) ;
        }
        
        bool *visited = new bool[n] ;
        for(ll i = 0 ; i<n; i++){
            visited[i] = false ;
        }
        ll count = 0 ;
        ll *d = new ll[n] ;
       
        cout<< bfs(g,n,0,visited,d)<<endl;
        
    }
	return 0;
}