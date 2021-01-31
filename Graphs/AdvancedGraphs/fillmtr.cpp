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
using namespace std;

class edges{
    public:
    int s;
    int e;
    edges(int start,int end){
        s=start;
        e=end;
    }
};
class Disj{
    public:
  	int parent;
  	int rank;
};

int find(int child,Disj *dj)
{
  	if(dj[child].parent != child)
    {
      	dj[child].parent = find(dj[child].parent,dj);
    }
  	return dj[child].parent;
}

void Union(int x,int y,Disj *ds)
{
  	int rootX = find(x,ds);
    int rootY = find(y,ds);

  	if(rootX == rootY)
      	return;
  	
    if(ds[rootX].rank < ds[rootY].rank)
    {
        ds[rootX].parent = rootY;
    }
    else if(ds[rootX].rank > ds[rootY].rank)
    {
        ds[rootY].parent = rootX;
    }
    else
    {
        ds[rootX].parent = rootY;
        ds[rootY].rank++;
    }
}

bool isUnion(int x,int y, Disj *dj)
{
  	return find(x,dj) == find(y,dj);
}
bool bipartite(vector<int>* edges, int n) {
	if (n == 0) {
		return true;
	}
	unordered_set<int> sets[2];
	vector<int> pending;
	sets[0].insert(0);
	pending.push_back(0);
	while (pending.size() > 0) {
		int current = pending.back();
		pending.pop_back();
		int currentSet = sets[0].count(current) > 0 ? 0 : 1;
		for (int i = 0; i < edges[current].size(); i++) {
			int neighbor = edges[current][i];
			if (sets[0].count(neighbor) == 0 && sets[1].count(neighbor) == 0) {
				sets[1 - currentSet].insert(neighbor);
				pending.push_back(neighbor);
			} else if (sets[currentSet].count(neighbor) > 0) {
				return false;
			}
		}
	}
	return true;
}


int main()
{
	//code
  	int t;
  	cin >> t;
  
  	while(t--)
    {
      	int n,q;
      	cin >> n >> q;
      
      	vector<int> *graph = new vector<int>[n];
      	vector<pair<int,int>> oneDiff;
      	
     	Disj *dj = new Disj[n];
      	for(int i = 0; i < n; i++)
        {
          	dj[i].parent = i;
          	dj[i].rank = 0;
        }
        vector<edges> Edges;
      
        bool sanity_check = true;
      
      	for(int i = 0; i < q; i++)
        {
          	int a,b,c;
          	cin >> a >> b >> c;
          	a--;
          	b--;
          	
          	if(a == b && c != 0)
              	sanity_check = false;
          	
          	if(c == 0)
            {
              	Union(a,b,dj);
            }
          	else
            {
                Edges.push_back(edges(a,b)) ;
            }
        }
      

        for(int i = 0 ; i < Edges.size(); i++){
            int e1 = find(Edges[i].s,dj) ;
            int e2 = find(Edges[i].e,dj) ;
            if(e1 == e2){
                sanity_check = false;
                break;
            }
            graph[e2].push_back(e1) ;
        }

      
      	if(!sanity_check)
        {
          	cout << "no" << endl;
          	continue;
        }
      
      	bool ans = bipartite(graph,n);
      	if(ans)
        {
          	cout << "yes" << endl;
        }
      	else
        {
          	cout << "no" << endl;
        }
    }
	return 0;
}
