// You are given a connected weighted undirected graph without any loops and multiple edges.

// Let us remind you that a graph's spanning tree is defined as an acyclic connected subgraph of the given graph that includes all of the graph's vertexes. The weight of a tree is defined as the sum of weights of the edges that the given tree contains. The minimum spanning tree (MST) of a graph is defined as the graph's spanning tree having the minimum possible weight. For any connected graph obviously exists the minimum spanning tree, but in the general case, a graph's minimum spanning tree is not unique.

// Your task is to determine the following for each edge of the given graph: whether it is either included in any MST, or included at least in one MST, or not included in any MST.
// Input
// The first line contains two integers n and m (2 ≤ n ≤ 10^5, ) — the number of the graph's vertexes and edges, correspondingly. Then follow m lines, each of them contains three integers — the description of the graph's edges as "ai bi wi" (1 ≤ ai, bi ≤ n, 1 ≤ wi ≤ 10^6, ai ≠ bi), where ai and bi are the numbers of vertexes connected by the i-th edge, wi is the edge's weight. It is guaranteed that the graph is connected and doesn't contain loops or multiple edges.
// Output
// Print m lines — the answers for all edges. If the i-th edge is included in any MST, print "any"; if the i-th edge is included at least in one MST, print "at least one"; if the i-th edge isn't included in any MST, print "none". Print the answers for the edges in the order in which the edges are specified in the input.
// Sample input 1
// 4 5
// 1 2 101
// 1 3 100
// 2 3 2
// 2 4 2
// 3 4 1
// sample output 1
// none
// any
// at least one
// at least one
// any
// Sample input 2
// 3 3
// 1 2 1
// 2 3 1
// 1 3 2
// sample output 2
// any
// any
// none
// sample input 3
// 3 3
// 1 2 1
// 2 3 1
// 1 3 1
// sample output 3
// at least one
// at least one
// at least one
// Note
// In the second sample the MST is unique for the given graph: it contains two first edges.

// In the third sample any two edges form the MST for the given graph. That means that each edge is included at least in one MST.
#include<bits/stdc++.h>

using namespace std; 


struct Edge {
	int x, y, cost;
	Edge(int X, int Y, int Cost) { x = X; y = Y; cost = Cost; }
	bool operator < (const Edge b) const {
		return cost != b.cost ? cost < b.cost : (x < b.x || (x == b.x && y < b.y));
	}
};

struct DSU {
	vector<int> p, r;
	DSU(int size) {
		r.assign(size, 1);
		p.resize(size);
		for (int i = 0; i < size; i++)
			p[i] = i;
	}
	DSU() {}

	int get(int x) { return p[x] == x ? x : (p[x] = get(p[x])); }
	bool unite(int x, int y) {
		x = get(x); y = get(y);
		if (x == y)
			return false;
		if (r[x] < r[y])
			swap(x,y);
		p[y] = x;
		r[x] += r[y];
		return true;
	}
};

vector<pair<Edge,int> > edges;
vector<string> answer;
DSU dsu;
vector<vector<int> > g;
vector<int> u, d, l;
int n, m, globalCounter;

void dfs(int v, int p = -1, int depth = 0) {
	l[v] = d[v] = depth;
	u[v] = globalCounter+1;
	for (int i = 0; i < (int)g[v].size(); i++) {
		if (g[v][i] == p)continue;
		int id = g[v][i], x = dsu.get(edges[id].first.x), y = dsu.get(edges[id].first.y), to = x == v ? y : x;
		if (u[to]>globalCounter)
			l[v] = min(l[v], d[to]);
		else {
			dfs(to, g[v][i], depth+1);
			l[v] = min(l[v], l[to]);
		}

		if (l[to] > d[v]) {
			answer[edges[g[v][i]].second] = "any";
		}
	}
}

void solve() {
	cin >> n >> m;
	d.resize(n); l.resize(n); u.resize(n);
	g.assign(n, vector<int> ());
	answer.assign(m, "at least one");

	dsu = DSU(n);
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		x--; y--;
		edges.push_back(make_pair(Edge(x,y,z),i));
	}

	sort(edges.begin(), edges.end());
	for (int i = 0; i < m;) {
		int k = i;
		while (k < (int)edges.size() && edges[k].first.cost == edges[i].first.cost)
			k++;
		for (int j = i; j < k; j++) {
			int x, y;
			x = dsu.get(edges[j].first.x);
			y = dsu.get(edges[j].first.y);

			if (x != y) {
				g[x].push_back(j);
				g[y].push_back(j);
			} else
				answer[edges[j].second] = "none";
		}

		for (int j = i; j < k; j++) {
			int x, y;
			x = dsu.get(edges[j].first.x);
			y = dsu.get(edges[j].first.y);
			if (u[x]<=globalCounter)
				dfs(x);
			if (u[y]<=globalCounter)
				dfs(y);
		}
		for (int j = i; j < k; j++) {
			int x, y;
			x = dsu.get(edges[j].first.x);
			y = dsu.get(edges[j].first.y);
			dsu.unite(x, y);
			g[x].clear(); g[y].clear();
		}

		i = k;
		globalCounter++;
	}
	for (int i = 0; i < m; i++)
		cout << answer[i] << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	solve();
	return 0;
}