// Kevin has a permutation P of N integers 1, 2, ..., N, but he doesn't like it. Kevin wants to get a permutation Q.

// Also he believes that there are M good pairs of integers (ai , bi). Kevin can perform following operation with his permutation:

// Swap Px and Py only if (x, y) is a good pair.
// Help him and tell if Kevin can obtain permutation Q using such operations.
// Input format:
// The first line of input will contain an integer T, denoting the number of test cases.

// Each test case starts with two space-separated integers N and M. The next line contains N space-separated integers Pi. The next line contains N space-separated integers Qi. Each of the next M lines contains two space-separated integers ai and bi.
// Output format:
// For every test case output "YES" (without quotes) if Kevin can obtain permutation Q and "NO" otherwise.
// Constraints:
// 1 ≤ T ≤ 10
// 2 ≤ N ≤ 100000
// 1 ≤ M ≤ 100000
// 1 ≤ Pi, Qi ≤ N. Pi and Qi are all distinct.
// 1 ≤ ai < bi ≤ N
// SAMPLE INPUT
// 2
// 4 1
// 1 3 2 4
// 1 4 2 3
// 3 4
// 4 1
// 1 3 2 4
// 1 4 2 3
// 2 4
// SAMPLE OUTPUT
// NO 
// YES
#include<bits/stdc++.h>
using namespace std;
void dfs(int start, vector<int>* edges, int n, bool* visited, unordered_set<int> * component) {
    visited[start] = true ;
	component->insert(start);

    for(int i = 0 ; i<edges[start].size();i++){
        int next = edges[start][i] ;
        if(!visited[next]){
            dfs(next,edges,n,visited,component) ;
        }
    }
    return ;

}

unordered_set<unordered_set<int>*>* getComponents(vector<int>* edges, int n) {
	bool *visited = new bool[n] ;
    for(int i = 0 ; i<n ; i++){
        visited[i] = false ;
    }
	unordered_set<unordered_set<int>*>* output = new unordered_set<unordered_set<int>*>();
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			unordered_set<int> * component = new unordered_set<int>();
			dfs(i, edges,n, visited, component);
			output->insert(component);
		}
	}
	return output;
}
int main()
{
	//code
    int t ;
    cin>>t ;
    while(t--){
        int n,m ;
        cin>>n>>m ;
        int * p = new int[n] ;
        int * q = new int[n] ;
        for(int i = 0 ; i<n ; i++){
            cin>>p[i] ;
        }
        for(int i = 0 ; i<n ; i++){
            cin>>q[i] ;
        }
        vector<int>* edges = new vector<int>[n];
	    for (int i = 0; i < m; i++) {
		    int j, k;
		    cin >> j >> k;
		    edges[j - 1].push_back(k - 1);
		    edges[k - 1].push_back(j - 1);
	    }
        
        unordered_set<unordered_set<int>*>* components = getComponents(edges, n);
        unordered_set<unordered_set<int>*>::iterator it = components->begin();
        int f = 0 ;
        while (it != components->end()) {
		    unordered_set<int>* component = *it;
		    unordered_set<int>::iterator it2 = component->begin();
            vector<int> temp ;
            vector<int> t_p ;
            vector<int> t_q ;
		    while (it2 != component->end()) {
                temp.push_back(*it2) ;
                int ind = *it2 ;
                t_p.push_back(p[ind]);
                t_q.push_back(q[ind]) ;
			    it2++;
		    }
            sort(t_p.begin(),t_p.end());
            sort(t_q.begin(),t_q.end());
            for(int i = 0 ; i<temp.size();i++){
                if(t_p[i] != t_q[i]){
                    f=1 ;
                    break ;
                }
                else{
                    f = 0 ;
                }
            }
            if(f==1){
                break ;
            }
		    delete component;
		    it++;
	    }
        
        if(f==0){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
        
        
    }
    

	return 0;
}