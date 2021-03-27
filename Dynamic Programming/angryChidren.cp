// Bill Gates is on one of his philanthropic journeys to a village in Utopia. He has N packets of candies and would like to distribute one packet to each of the K children in the village (each packet may contain different number of candies). To avoid a fight between the children, he would like to pick K out of N packets such that the unfairness is minimized.
// Suppose the K packets have (x1, x2, x3,....xk) candies in them, where xi denotes the number of candies in the ith packet, then we define unfairness as
// unfairness=0;
// for(i=0;i<n;i++)
// for(j=0;j<n;j++)
//     unfairness+=abs(xi-xj)
// abs(x) denotes absolute value of x.
// Input Format
// The first line contains an integer N.
// The second line contains an integer K.
// N lines follow each integer containing the candy in the ith packet.
// Output Format
// A single integer which will be minimum unfairness.
// Constraints
// 2<=N<=10^5

// 2<=K<=N

// 0<= number of candies in each packet <=10^9
// Sample Input
// 7
// 3
// 10
// 100
// 300
// 200
// 1000
// 20
// 30
// Sample Output
// 40
// Explanation
// Bill Gates will choose packets having 10, 20 and 30 candies.So unfairness will be |10-20| + |20-30| + |10-30| = 40. We can verify that it will be minimum in this way.



#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;

int main()
{
    ll n,k;
    cin>>n>>k ;
    ll unfairness = 0 ;
    ll arr[n] ;
    for(ll i = 0 ;i<n;i++){
        cin>>arr[i] ;
    }
    sort(arr,arr+n);
 
    ll target =  0, prev_sum= arr[0] ;
    for(ll i = 1; i<k ; i++){
        target = target + ((i) * arr[i]) - prev_sum ;
        prev_sum += arr[i] ;
    }
    unfairness = target ;
    ll temp = unfairness ;
    ll j=0;
    for(ll i = k ; i<n,j<(n-1)-k+1; i++){
        ll buff = prev_sum - arr[j] ;
        temp = temp - (2*(buff)) + ((k-1) * arr[j]) + ((k-1) * arr[i]) ;
        if(temp < unfairness){
            unfairness = temp ;
        }
        prev_sum = buff + arr[i] ;
        j++ ;
    }
    
    cout<<unfairness<<endl;
    return 0;
    
    

}



