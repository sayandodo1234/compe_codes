// Segment trees are extremely useful. In particular "Lazy Propagation" (i.e. see here, for example) allows one to compute sums over a range in O(lg(n)), and update ranges in O(lg(n)) as well. In this problem you will compute something much harder:
// The sum of squares over a range with range updates of 2 types:
// 1) increment in a range
// 2) set all numbers the same in a range.
// Input
// There will be T (T <= 25) test cases in the input file. First line of the input contains two positive integers, N (N <= 100,000) and Q (Q <= 100,000). 
// The next line contains N integers, each at most 1000. Each of the next Q lines starts with a number, which indicates the type of operation:

// 2 st nd -- return the sum of the squares of the numbers with indices in [st, nd] {i.e., from st to nd inclusive} (1 <= st <= nd <= N).

// 1 st nd x -- add "x" to all numbers with indices in [st, nd] (1 <= st <= nd <= N, and -1,000 <= x <= 1,000).

// 0 st nd x -- set all numbers with indices in [st, nd] to "x" (1 <= st <= nd <= N, and -1,000 <= x <= 1,000).
// Output
// For each test case output the “Case <caseno>:” in the first line and from the second line output the sum of squares for each operation of type 2. Intermediate overflow will not occur with proper use of 64-bit signed integer.
// Input:
// 2
// 4 5
// 1 2 3 4
// 2 1 4
// 0 3 4 1
// 2 1 4
// 1 3 4 1
// 2 1 4
// 1 1
// 1
// 2 1 1
// Output:
// Case 1:
// 30
// 7
// 13
// Case 2:
// 1

#include <bits/stdc++.h>
using namespace std;
 
#define endl "\n"
#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

typedef struct 
{
	long long f,s;
	long long lazy[2];
}pairs;

vector<long long>arr(100005);
vector< pairs >tree(400005);

void build(int idx, int l, int r)
{
	if(l==r)
	{
		tree[idx].f=arr[l];
		tree[idx].s=(arr[l]*arr[l]);
		tree[idx].lazy[0]=tree[idx].lazy[1]=-1001;
		return;
	}
	int mid=(l+r)>>1;
	build(idx<<1,l,mid);
	build(idx<<1|1,mid+1,r);
	tree[idx].f=tree[idx<<1].f+tree[idx<<1|1].f;
	tree[idx].s=tree[idx<<1].s+tree[idx<<1|1].s;
	tree[idx].lazy[0]=tree[idx].lazy[1]=-1001;
}

bool check(int y)
{
	if(y>=-1000 && y<=1000) return true;
	return false;
}

void lazier(int idx, int l, int r, int beg, int end)
{
	if(l!=r)
	{
		int mid=(r+l)>>1;
		if(check(tree[idx].lazy[0]))
		{
			tree[idx<<1].f=(tree[idx].lazy[0]*(mid-l+1));
			tree[idx<<1].s=(tree[idx].lazy[0]*tree[idx].lazy[0]*(mid-l+1));
			tree[idx<<1|1].f=(tree[idx].lazy[0]*(r-mid));
			tree[idx<<1|1].s=(tree[idx].lazy[0]*tree[idx].lazy[0]*(r-mid));
			tree[idx<<1].lazy[0]=tree[idx<<1|1].lazy[0]=tree[idx].lazy[0];
			tree[idx].lazy[0]=-1001;
		}
		else if(check(tree[idx].lazy[1]))
		{
			tree[idx<<1|1].s += (tree[idx].lazy[0]*tree[idx].lazy[0]+ (tree[idx].lazy[0]*tree[idx<<1|1].f*2));
			tree[idx<<1].s += (tree[idx].lazy[0]*tree[idx].lazy[0]+ (tree[idx].lazy[0]*tree[idx<<1].f*2));
			tree[idx<<1|1].f += (tree[idx].lazy[0]*(r-mid));
			tree[idx<<1].f += (tree[idx].lazy[0]*(mid-l+1));
			tree[idx<<1].lazy[1]=tree[idx<<1|1].lazy[1]=tree[idx].lazy[1];
			tree[idx].lazy[1] = -1001;
		}
	}
}

void update(int idx, int l, int r, int beg, int end, pair<long long, long long>&x)
{
	if(check(tree[idx].lazy[0]) || check(tree[idx].lazy[1])) lazier(idx,l,r,beg,end);

	if(l>end || r<beg) return;

	if(beg<=l && r<=end)
	{
		if(check(x.first))
		{
			tree[idx].f=(x.first*(r-l+1));
			tree[idx].s=(x.first*x.first*(r-l+1));
			if(l!=r)
			{
				tree[idx].lazy[0]=x.first;
			}
		}
		else if(check(x.second))
		{
			tree[idx].s+=(x.second*x.second*(r-l+1) + (x.second*(tree[idx].f)*2));
			tree[idx].f+=(x.second*(r-l+1));
			if(l!=r)
			{
				tree[idx].lazy[1]=x.second;
			}
		}
		return;
	}
	int mid=(l+r)>>1;
	update(idx<<1, l, mid, beg, end, x);
	update(idx<<1|1, mid+1, r, beg, end, x);
	tree[idx].f=tree[idx<<1].f+tree[idx<<1|1].f;
	tree[idx].s=tree[idx<<1].s+tree[idx<<1|1].s;
}

long long get(int idx, int l, int r, int beg, int end)
{
	if(check(tree[idx].lazy[0]) || check(tree[idx].lazy[1])) lazier(idx,l,r,beg,end);

	if(l>end || r<beg) return 0;

	if(beg<=l && r<=end)
	{
		return tree[idx].s;
	}
	int mid=(l+r)>>1;
	return get(idx<<1, l, mid, beg, end) + get(idx<<1|1, mid+1, r, beg, end);
}
 
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	for(int test=1;test<=t;test++)
	{
		cout<<"Case "<<test<<":\n";
		int n,q;
		cin>>n>>q;
		for(int i=0;i<n;i++) cin>>arr[i];
		build(1,0,n-1);
		while(q--)
		{
			int i,l,r,v;
			cin>>i;
			if(i==0)
			{
				cin>>l>>r>>v;
				pair<long long, long long>temp{v,-1001};
				update(1,0,n-1,l-1,r-1,temp);
			}
			else if(i==1)
			{
				cin>>l>>r>>v;
				pair<long long, long long>temp{-1001,v};
				update(1,0,n-1,l-1,r-1,temp);
			}
			else
			{
				cin>>l>>r;
				cout<<get(1,0,n-1,l-1,r-1)<<"\n";
			}
		}
	}
}