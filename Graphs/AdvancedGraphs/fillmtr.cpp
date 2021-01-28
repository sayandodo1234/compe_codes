// A matrix B (consisting of integers) of dimension N × N is said to be good if there exists an array A (consisting of integers) such that B[i][j] = |A[i] - A[j]|, where |x| denotes absolute value of integer x.

// You are given a partially filled matrix B of dimension N × N. Q of the entries of this matrix are filled by either 0 or 1. You have to identify whether it is possible to fill the remaining entries of matrix B (the entries can be filled by any integer, not necessarily by 0 or 1) such that the resulting fully filled matrix B is good.
// Input
// The first line of the input contains an integer T denoting the number of test cases.

// The first line of each test case contains two space separated integers N, Q.

// Each of the next Q lines contain three space separated integers i, j, val, which means that B[i][j] is filled with value val.
// Output
// For each test case, output "yes" or "no" (without quotes) in a single line corresponding to the answer of the problem.
// Constraints
// 1 ≤ T ≤ 10^6
// 2 ≤ N ≤ 10^5
// 1 ≤ Q ≤ 10^6
// 1 ≤ i, j ≤ N
// 0 ≤ val ≤ 1
// Sum of each of N, Q over all test cases doesn't exceed 106
// Input
// 4
// 2 2
// 1 1 0
// 1 2 1
// 2 3
// 1 1 0
// 1 2 1
// 2 1 0
// 3 2
// 2 2 0
// 2 3 1
// 3 3
// 1 2 1
// 2 3 1
// 1 3 1
// Output
// yes
// no
// yes
// no


#include<bits/stdc++.h>
#define MAXN 100000
using namespace std;
int setfa[MAXN*2+5];
void Init()
{
	for(int i=0;i<=MAXN*2+3;i++)
		setfa[i]=i;
}
int Findfa(int x)
{
	if(x==setfa[x])
		return x;
	return setfa[x]=Findfa(setfa[x]);
}
void Union(int x,int y)
{
	int fx=Findfa(x),fy=Findfa(y);
	if(fx==fy)
		return;
	setfa[fx]=fy;
}
bool Same(int x,int y)
{
	return Findfa(x)==Findfa(y);
}
int main()
{
	int times;
	int N,Q;
	scanf("%d",&times);
	for(int tmn=1;tmn<=times;tmn++)
	{
		Init();
		scanf("%d %d",&N,&Q);
		int x,y,z; 
		for(int i=1;i<=Q;i++)
		{
			scanf("%d %d %d",&x,&y,&z);
			if(z==0)
			{
				Union(x,y);
				Union(x+MAXN,y+MAXN);
			}
			else if(z==1)
			{
				Union(x,y+MAXN);
				Union(y,x+MAXN);
			}
		}
		bool flag=true;
		for(int i=1;i<=MAXN;i++)
			if(Same(i,i+MAXN)==true)
			{
				flag=false;
				break;
			}
		if(flag==true)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}
