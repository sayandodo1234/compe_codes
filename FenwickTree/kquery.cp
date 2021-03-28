// Given a sequence of n numbers a1, a2, ..., an and a number of k- queries. A k-query is a triple (i, j, k) (1 ≤ i ≤ j ≤ n). For each k-query (i, j, k), you have to return the number of elements greater than k in the subsequence ai, ai+1, ..., aj.
// Input Format
// Line 1: n (1 ≤ n ≤ 30000).

// Line 2: n numbers a1, a2, ..., an (1 ≤ ai ≤ 10^9).

// Line 3: q (1 ≤ q ≤ 200000), the number of k- queries.

// In the next q lines, each line contains 3 numbers i, j, k representing a k-query (1 ≤ i ≤ j ≤ n, 1 ≤ k ≤ 10^9).
// Output Format
// For each k-query (i, j, k), print the number of elements greater than k in the subsequence ai, ai+1, ..., aj in a single line.
// Sample Input
// 5
// 5 1 2 3 4
// 3
// 2 4 1
// 4 4 4
// 1 5 2 
// Sample Output
// 2
// 0
// 3 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class kquery{
    public:
    ll x;
    ll y;
    ll k;
    ll ind;
    
};

void update(ll ind,ll *bit,ll n){
    for(;ind<=n;ind+=(ind&(-ind))){
        bit[ind]+=1;
    }
}

ll query(ll ind,ll *bit){
    ll res = 0 ;
    for(;ind>0;ind-=(ind&(-ind))){
        res+= bit[ind] ;
    }
    return res ;
}

bool compare(kquery A, kquery B){
    if(A.k == B.k){
        return A.x > B.x ;
    }
    return A.k > B.k ;
}
bool compare2(pair<ll,ll> A,pair<ll,ll> B){
    return A.first > B.first ;
}
int main()
{
    std::ios::sync_with_stdio(false);
    ll n;
    cin>>n;
    pair<ll,ll> arr[n];
    ll *bit = new ll[n+1];
    for(ll i = 0 ; i<n ; i++){
        cin>>arr[i].first ;
        arr[i].second = i;
    }
    sort(arr,arr+n,compare2) ;
    ll q;
    cin>>q;
    ll ans[q] ;
    kquery queries[q];
    ll pos = 0;
    for(ll i = 0 ;i<q;i++){
        cin>>queries[i].x>>queries[i].y>>queries[i].k;
        queries[i].ind = i;
    }
    sort(queries,queries+q,compare);
    for(ll i = 0; i<q; i++){
        
        while(pos<n && arr[pos].first > queries[i].k){
            update(arr[pos].second+1,bit,n);
            pos++;
        }
        ans[queries[i].ind] = query(queries[i].y,bit)- query(queries[i].x-1,bit) ;
    }

    for(auto num : ans){
        printf("%d\n",num);
    }

	return 0;
}


