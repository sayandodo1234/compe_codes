// Roy and Coin Boxes
// Send Feedback
// Roy has N coin boxes numbered from 1 to N.
// Every day he selects two indices [L,R] and adds 1 coin to each coin box starting from L to R (both inclusive).
// He does this for M number of days.

// After M days, Roy has a query: How many coin boxes have atleast X coins.
// He has Q such queries.
// Input
// First line contains N - number of coin boxes.
// Second line contains M - number of days. Each of the next M lines consists of two space separated integers L and R. Followed by integer Q - number of queries.
// Each of next Q lines contain a single integer X.a
// Output
// For each query output the result in a new line.
// Constraints
// 1 ≤ N ≤ 1000000

// 1 ≤ M ≤ 1000000

// 1 ≤ L ≤ R ≤ N

// 1 ≤ Q ≤ 1000000

// 1 ≤ X ≤ N
// Sample Input
// 7
// 4
// 1 3
// 2 5
// 1 2
// 5 6
// 4
// 1
// 7
// 4
// 2
// Sample Output
// 6
// 0
// 0
// 4

#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;


int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    ll n,m ; 
    cin>>n;
    ll box[n+1];
    ll start[n+1] ;
    ll end[n+1] ;
    ll coins[n+1] ;
    ll dp[n+1] ;
    for(ll i = 0 ;i<=n;i++){
        box[i] = 0;
        start[i] = 0;
        end[i] = 0 ;
        coins[i] = 0;
        dp[i] = 0 ;
    }
    cin>>m ; 
    while(m--){
        ll l , r;
        cin>>l>>r;
        start[l]++ ;
        end[r]++ ;

    }
    box[1] = start[1] ;
    coins[box[1]]++;

    for(ll i=2;i<=n;i++){
        box[i] = box[i-1] + start[i] - end[i-1] ;
        coins[box[i]]++;
    }
    dp[n] = coins[n] ;
    for(ll i = n-1;i>=1;i--){
        dp[i] = coins[i] + dp[i+1];
    }
    
    ll q,x;
    cin>>q;
    while(q--){
        cin>>x;
        cout<<dp[x]<<endl;
        
    }
    
    return 0;
}
