// Daulat Ram is an affluent business man. After demonetization, IT raid was held at his accommodation in which all his money was seized. He is very eager to gain his money back, he started investing in certain ventures and earned out of them. On the first day, his income was Rs. X, followed by Rs. Y on the second day. Daulat Ram observed his growth as a function and wanted to calculate his income on the Nth day.
// The function he found out was FN = FN-1 + FN-2 + FN-1×FN-2
// Given his income on day 0 and day 1, calculate his income on the Nth day (yeah Its that simple).
// Input:
// The first line of input consists of a single integer T denoting number of test cases.

// Each of the next T lines consists of three integers F0, F1 and N respectively.
// Output:
// For each test case, print a single integer FN, as the output can be large, calculate the answer modulo 10^9+7.
// CONSTRAINTS:
// 1 ≤ T ≤ 10^5

// 0 ≤ F0, F1, N ≤ 10^9
// Sample Input :
// 2
// 0 1 2
// 1 2 4
// Sample Output:
// 1
// 107
// Explanation
// In the second test case his income on day 0 is 1 and the income on day 1 is 2. We need to calculate his income on day 4.

// F0=1

// F1=2

// F2=1 + 2 + 1×2 = 5

// F3=2 + 5 + 2×5 = 17

// F4=5 + 17 + 5×17 = 107
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;
void multiply(ll A[2][2],ll M[2][2]){
	ll first=(A[0][0]*M[0][0]+A[0][1]*M[1][0])%(MOD-1);
	ll second=(A[0][0]*M[0][1]+A[0][1]*M[1][1])%(MOD-1);
	ll third=(A[1][0]*M[0][0]+A[1][1]*M[1][0])%(MOD-1);
	ll four=(A[1][0]*M[0][1]+A[1][1]*M[1][1])%(MOD-1);
	A[0][0]=first;
	A[0][1]=second;
	A[1][0]=third;
	A[1][1]=four;
}
void power(ll A[2][2],ll n){
if(n==0||n==1){
	return;
}
	power(A,n/2);
	multiply(A,A);
	if(n%2!=0){
		ll M[2][2]={{1,1},{1,0}};
		multiply(A,M);
	}
}
ll fibonacci(ll n){
	if(n==0){
		return 0;
	}
	ll A[2][2]={{1,1},{1,0}};
	power(A,n-1);
	return A[0][0];
}
ll power1(ll x,ll n){
	ll ans=1;
	while(n!=0){
		int right=n&1;
		if(right!=0){
			ans=(ans*x)%MOD;
		}
		x=(x*x)%MOD;
		n/=2;
	}
	return ans;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		ll a,b,n;
		cin>>a>>b>>n;
		if(n==0){
			cout<<a<<endl;
			continue;
		}
		if(n==1){
			cout<<b<<endl;
			continue;
		}
		a=a+1;
		b=b+1;
		ll x=fibonacci(n-1);
		ll y=fibonacci(n);
		ll ans1=power1(a,x);
		ll ans2=power1(b,y);
		ll ans=(ans1*ans2)-1;
		ans=ans%MOD;
		if(ans<0){
			ans+=MOD;
		}
		cout<<ans<<endl;
		}
	return 0;
}