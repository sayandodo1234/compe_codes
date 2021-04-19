// A number is called n-factorful if it has exactly n distinct prime factors. Given positive integers a, b, and n, your task is to find the number of integers between a and b, inclusive, that are n-factorful. We consider 1 to be 0-factorful.
// Input
// Your input will consist of a single integer T followed by a newline and T test cases. Each test cases consists of a single line containing integers a, b, and n as described above.
// Output
// Output for each test case one line containing the number of n-factorful integers in [a, b].
// Constraints
// T < 10000

// 1 ≤ a ≤ b ≤ 10^6

// 0 ≤ n ≤ 10
// Sample Input
// 5
// 1 3 1
// 1 10 2
// 1 10 3
// 1 100 3
// 1 1000 0
// Sample Output
// 2 
// 2
// 0
// 8
// 1

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define memo(a,b) memset(a,b,sizeof(a))
#define INF 1e9
#define EPS 1e-8
#define PI 3.14159265358979323846

typedef long long ll ;
typedef unsigned long long ull ;

/* int dx[] = {1,-1,0,0} , dy[] = {0,0,1,-1}; */ // 4 Direction
/* int dx[] = {1,-1,0,0,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1,1,-1}; */ // 8 Direction
/* int dx[] = {1,-1,1,-1,2,2,-2,-2} , dy[] = {2,2,-2,-2,1,-1,1,-1}; */ // Knight Direction
/* int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1}; */ // Hexagonal Direction

int divisor[1000000+10] , ANS[11][1000000+10] ;

void sieve()
{
    for(int i=2;i<=1000000;i++)
    {
        if(divisor[i]==0)
        {
            for(int j=i;j<=1000000;j+=i) divisor[j]++;
        }
    }

    for(int n=0;n<=10;n++)
    {
        for(int i=1;i<=1000000;i++) ANS[n][i] = ANS[n][i-1] + (bool) ( divisor[i] == n ) ;
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    sieve();
    int T ;
    scanf("%d",&T);
    while( T-- )
    {
        int a , b , n ;
        scanf("%d%d%d",&a,&b,&n);
        printf("%d\n",ANS[n][b]-ANS[n][a-1]);
    }
    return 0;
}
