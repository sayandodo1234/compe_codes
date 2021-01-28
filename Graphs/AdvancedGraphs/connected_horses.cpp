// You all must be familiar with the chess-board having 
// 8*8 squares of alternate black and white cells. Well, here 
// we have for you a similar 
// N*M size board with similar arrangement of black and white 
// cells.
// A few of these cells have Horses placed over them. 
// Each horse is unique. Now these horses are not the 
// usual horses which could jump to any of the 
// 8 positions they usually jump in. They can move only if there is another horse on one of the 8-positions that it can     go to usually and then both the horses will swap their positions. This swapping can happen infinitely times.
// A photographer was assigned to take a picture of all the different ways that the horses occupy the board! Given the state of the board, calculate answer. Sincethis answer may be quite large, calculate in modulo 
// 10^9+7
// Input:
// First line contains 
// T which is the number of test cases.
// T test cases follow first line of each containing three integers 
// N, M and Q where 
// N,M is the size of the board and 
// Q is the number of horses on it.

// Q lines follow each containing the 2 integers 
// X and Y which are the coordinates of the Horses.
// Output:
// For each test case, output the number of photographs taken by photographer.
// Constraints:
//  1<=T<=10
//  1<=N,M<=1000
//  1<=Q<=N*M
// SAMPLE INPUT
// 2
// 4 4 4
// 1 1
// 1 2
// 3 1
// 3 2
// 4 4 4
// 1 1
// 1 2
// 3 1
// 4 4
// SAMPLE OUTPUT
// 4
// 2

#include<bits/stdc++.h>
using namespace std;

typedef long long ll ;
ll M = pow(10,9) + 7 ;

struct node{
    int x;
    int y;
} ;

ll dx[8] = {-2,-2,-1,-1,1,1,2,2} ;
ll dy[8] = {-1,1,-2,2,-2,2,-1,1} ;

ll dfs(ll i, ll j, vector<node>** graph, ll** visited){
	visited[i][j] = 1;
	ll answer = 1;

	for(ll k = 0; k < graph[i][j].size(); k++){
        ll x = graph[i][j][k].x;
        ll y = graph[i][j][k].y;
        if(!visited[x][y]){
            answer = (answer+dfs(x, y, graph, visited))%M;
        }
    }

    return answer;
}

bool is_eligible(int x, int y,ll** board,ll n, ll m){
    if(x < 0 || x>=n || y<0 || y>=m || board[x][y] !=1){
        return false ;
    }
    
    return true ;
}

void create_graph(vector<node>** graph,ll** board,ll m ,ll n){
    for(ll i = 0 ; i<n ; i++){
        for(ll j = 0 ; j<m ; j++){
            if(board[i][j] == 1){
                for(ll k = 0 ; k<8 ; k++){
                    ll x = i + dx[k] ;
                    ll y = j + dy[k] ;
                    if(is_eligible(x,y,board,n,m)){
                        node temp ;
                        temp.x = x ;
                        temp.y = y ;
                        graph[i][j].push_back(temp) ;
                        
                    }
                }
            }
        }
    }
}


int main()
{
	ll *factorial = new ll[1000000];
    factorial[1] = 1;
    for(ll i = 2; i < 1000000; i++){
    	factorial[i] = (factorial[i-1]*i)%M;
    }

	ll t;
	cin>>t;
	while(t--){
		ll n, m,q;
		cin>>n>>m>>q;

		ll** board = new ll*[n];
		for (ll i = 0; i < n; ++i)
		{
			board[i] = new ll[m];
			for (ll j = 0; j < m; ++j)
			{
				board[i][j] = 0;
			}
		}

		while(q--){
			ll x, y;
			cin>>x>>y;
			board[x-1][y-1] = 1;
		}


        vector<node>** graph = new vector<node>*[n] ;
    
		for (ll i = 0; i < n; ++i)
		{
			graph[i] = new vector<node>[m];
		}


		create_graph(graph, board, m, n);

		
		ll** visited = new ll*[n];
		for (ll i = 0; i < n; ++i)
		{
			visited[i] = new ll[m];;
			for (ll j = 0; j < m; ++j)
			{
				visited[i][j] = 0;
			}
		}

		ll ans = 1;
		for (ll i = 0; i < n; ++i)
		{
			for (ll j = 0; j < m; ++j)
			{
				if (visited[i][j] == 0 && board[i][j] == 1)
				{
					ans = (ans*factorial[dfs(i, j, graph, visited)])%M;
				}
				
			}
		}

		cout << ans << endl;
	}


	return 0 ; 

}
