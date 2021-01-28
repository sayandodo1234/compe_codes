// Dominos are lots of fun. Children like to stand the tiles on their side in long lines. When one domino falls, it knocks down the next one, which knocks down the one after that, all the way down the line.
// However, sometimes a domino fails to knock the next one down. In that case, we have to knock it down by hand to get the dominos falling again.
// Your task is to determine, given the layout of some domino tiles, the minimum number of dominos that must be knocked down by hand in order for all of the dominos to fall.
// Input
// The first line of input contains one integer specifying the number of test cases to follow.Each test case begins with a line containing two integers,each no larger than 100 000. The first integer n is the number of domino tiles and the second integer m is the number of lines to follow in the test case. The domino tiles are numbered from 1 to n.
// Each of the following lines contains two integers x and y indicating that if domino number x falls, it will cause domino number y to fall as well.
// Output
// For each test case, output a line containing one integer, the minimum number of dominos that must be knocked over by hand in order for all the dominos to fall.
// Sample Input
// 1
// 3 2
// 1 2
// 2 3
// Sample Output
// 1

#include <bits/stdc++.h>
#define MX 100005
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int const md=1e9+7;
vector<int> G[MX];
int vis[MX];
stack<int> s;
void dfss(int u)
{
	vis[u]=1;
	for(auto v:G[u])
	{
		if(!vis[v])
			dfss(v);
	}
	s.push(u);
	
}
void dfs(int u)
{
	vis[u]=1;
	for(auto v:G[u])
	{
		if(!vis[v])
			dfs(v);
	}
	
}
int main() 
{	
	
	int t;
	cin>>t;
	while(t--)
	{
		for(int i=0;i<MX;i++)
			G[i].clear();
		memset(vis,0,sizeof(vis));
		while(!s.empty())
			s.pop();
		int n,m;
		cin>>n>>m;
		for(int i=0;i<m;i++)
		{
			int u,v;
			cin>>u>>v;
			G[u].push_back(v);
		}
		
		for(int i=1;i<=n;i++)
		{
			if(!vis[i])
				dfss(i);
		}
		memset(vis,0,sizeof(vis));
		int c=0;
		while(!s.empty())
		{
			int u=s.top();s.pop();
			if(!vis[u])
			{
				dfs(u);
				c++;
			}
		}
		
		cout<<c<<endl;
		
		
	}
	return 0;
}