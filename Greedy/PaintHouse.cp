// You want to paint your house. The total area of your house is D units. There are a total of N workers. The ith worker is available after time Ti, has hiring cost Xi and speed Yi. This means he becomes available for hiring from time Ti and remains available after that. Once available, you can hire him with cost Xi, after which he will start painting the house immediately, covering exactly Yi units of house with paint per time unit. You may or may not hire a worker and can also hire or fire him at any later point of time. However, no more than 1 worker can be painting the house at a given time.
// Since you want the work to be done as fast as possible, figure out a way to hire the workers, such that your house gets painted at the earliest possible time, with minimum cost to spend for hiring workers.
// Note: You can hire a previously hired worker without paying him again.
// Input
// The first line of input contains two integers "N D", the number of workers and the area of your house respectively. The ith of the next N lines denotes the ith worker, and contains three integers "Ti Xi Yi", described in the statement.
// Output
// Output one integer, the minimum cost that you can spend in order to get your house painted at the earliest.
// Constraints
// 1 ≤ N, T, X, Y ≤ 10^5
// 1 ≤ D ≤ 10^11
// Sample Input
// 3 3
// 1 1 1
// 2 2 2
// 3 1 5
// Sample Output
// 3

#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
struct Worker{
    int T,x,y ;
    Worker(){}
    Worker(int _T,int _x , int _y){
        T = _T;
        x = _x ;
        y = _y ;
    }
};
bool way(Worker a, Worker b){
    if(a.T == b.T){
        if(a.y == b.y){
            return a.x < b.x ;
        }
        return a.y > b.y ;
    }
    return a.T < b.T ;
}
int main()
{
    //Write your code here
    vector<Worker> input ;
    int n,x,y,T ,i,j;
    ll d ;
    cin>>n>>d;
    for(i = 0 ; i<n;i++){
        cin>>T>>x>>y ;
        input.push_back(Worker(T,x,y));
    }
    sort(input.begin(),input.end(),way) ;
    ll area = 0 ,best_speed = INT_MIN , cost = 0 , last_time = input[0].T;
    for(i = 0 ; i<n ; i++){
        ll additional = best_speed * 1ll * (input[i].T - last_time) ;
        area += additional ;
        if(area >= d){
            break ;
        }
        if(input[i].y > best_speed){
            best_speed = input[i].y ;
            cost += input[i].x ;  
        }
        last_time = input[i].T ;
    }
    cout<<cost<<endl;
    return 0;
}