// In this problem, you have to maintain a dynamic set of numbers which support the two fundamental operations
// INSERT(S,x): if x is not in S, insert x into S
// DELETE(S,x): if x is in S, delete x from S
// and the two type of queries
// K-TH(S) : return the k-th smallest element of S
// COUNT(S,x): return the number of elements of S smaller than x
// Input Format
// Line 1: Q (1 ≤ Q ≤ 200000), the number of operations
// In the next Q lines, the first token of each line is a character I, D, K or C meaning that the corresponding operation is INSERT, DELETE, K-TH or COUNT, respectively, following by a whitespace and an integer which is the parameter for that operation.

// If the parameter is a value x, it is guaranteed that ≤ |x| ≤ 10^9. If the parameter is an index k, it is guaranteed that 1 ≤ k ≤ 10^9.`
// Output
// For each query, print the corresponding result in a single line. In particular, for the queries K-TH, if k is larger than the number of elements in S, print the word 'invalid'.
// Input Format
// 8
// I -1
// I -1
// I 2
// C 0
// K 2
// D -1
// K 1
// K 2
// Output Format
// 1
// 2
// 2
// invalid
#include<bits/stdc++.h>
using namespace std;
set<int> s;
map<int,int> m,M;
int ft[200002],q,x[200002],n=0,t,cnt=0;
char ch[200002];
void ud(int x,int v){
    for(;x<=n;x+=-x&x)  ft[x]+=v;
}
int gs(int x){
    int sum=0;
    for(;x>0;x-=-x&x)     sum+=ft[x];
    return sum;
}

int bs(int s,int e,int x){
    if(s==e)    return M[s];
    int m=(s+e)/2;
    if(gs(m)<x)     return bs(m+1,e,x);
    return bs(s,m,x);
}
int main(){
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        scanf(" %c %d",&ch[i],&x[i]);
        s.insert(x[i]);
    }
    for(set<int>::iterator it=s.begin();it!=s.end();it++)
        m[*it]=++n,M[n]=*it;
    for(int i=0;i<q;i++){
        t=m[x[i]];
        if(ch[i]=='I')
            if(gs(t)==gs(t-1))    ud(t,1),cnt++;
        if(ch[i]=='D')
            if(gs(t)!=gs(t-1))    ud(t,-1),cnt--;
        if(ch[i]=='K'){
            if(cnt<x[i])    printf("invalid\n");
            else    printf("%d\n",bs(1,n,x[i]));
        }
        if(ch[i]=='C')
            printf("%d\n",gs(t-1));
    }
    return 0;
}