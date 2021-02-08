// Pradyumn is tired of using auto - correct feature in his smartphone. He needs to correct his auto - correct more times than the auto - correct corrects him. Pradyumn is thinking to make his own app for mobile which will restrict auto - correct feature, instead it will provide auto - completion. Whenever Pradyumn types factorial, auto - correct changes it to fact. Pradyumn's App will show options such as fact, factorial, factory. Now, he can chose from any of these options. As Pradyumn is busy with his front - end work of his App. He asks you to help him. He said "You will be given set of words(words may repeat too but counted as one only). Now, as user starts the app, he will make queries(in lowercase letters only). So, you have to print all the words of dictionary which have the prefix same as given by user as input. And if no such words are available, add this word to your dictionary." As you know, Pradyumn want this app to be as smart as him :P So, implement a program for him such that he can release it on Fun Store.
// INPUT CONSTRAINTS
// 1≤N≤30000
// sum(len(string[i]))≤2∗10^5
// 1≤Q≤10^3
// INPUT FORMAT
// Single integer N which denotes the size of words which are input as dictionary
// N lines of input, where each line is a string of consisting lowercase letter
// Single integer Q which denotes the number of queries.
// Q number of lines describing the query string on each line given by user
// OUTPUT FORMAT
// If auto - completions exists, output all of them in lexicographical order else output "No suggestions" without quotes

// NOTE: All strings are lowercase
// SAMPLE INPUT
// 3
// fact
// factorial
// factory
// 2
// fact
// pradyumn
// SAMPLE OUTPUT
// fact
// factorial
// factory
// No suggestions


// #include <bits/stdc++.h>
// using namespace std;
// class trie{
//     public:
//     trie ** children;
//     int flag ;
//     char val ;
//     trie(){
//         flag = -1;
//         val = "";
//         children = new trie*[26];
//         for(int i = 0 ; i <26 ; i++){
//             children[i] = NULL;
//         }  
//     }
// };

// void insert(string s, trie *root){
//     if(s.size() == 1){
//         root->val = s[0] ;
//         root->flag = 2 ;
//         return ;
//     }
//     root->flag = 1 ;
//     trie *child ;
//     int index = s[0] - 'a';
//     if(root->children[index] == NULL){
//         child = new trie();
//         child->val = s[0] ;
//         root->children[index] = child;
//     }else{
//         child = root->children[index] ;
//     }
//     insert(s.substr(1),child);
//     return ;
// }

// void search(trie *root,string t,vector<string>&v){
//     trie *curr = root ;
//     // if(root->child[s[0]-'a'] == NULL){
//     //     return;
//     // }
//     string t = "";
//     for(int i = 0 ; i<t.size() ; i++){
//         int index = s[i] - 'a';
//         t.append(s[i]) ;
//         trie *child = curr->children[index];
//         if(child != NULL){
//             // v.push_back(child->val);
//             curr = child ;
//             if(child->flag == 2){
//                 v.push_back(t) ;
//                 return ;
//             }
//         }
//         else{
//             t = "";
//             v.clear() ;
//             return ;
//         }
//     }
    
// }

// int main()
// {
//     int n ,q;
//     cin>>n ;
//     trie * root = new trie() ;
//     for(int i = 0 ; i<n ; i++){
//         string s ;
//         cin>>s;
//         insert(s,root) ;
//     }
//     cin>>q;
//     while(q--){
//         string temp;
//         cin>>temp;
//         vector<string> v;
//         search(root,temp,v) ;
//         if(v.size() == 0){
//             cout<<"No suggestions"<<endl;
//         }
//         for(int i = 0 ; i<v.size() ; i++){
//             cout<<v[i]<<endl;
//         }
//     }
//     return 0;
// }
// #include <bits/stdc++.h>
#define lli long long int
#define vec2 vector<vector<lli>> 
#define fio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define FRE freopen("explicit.in","r",stdin);freopen("explicit.out","w",stdout)
#define pll pair <lli,lli>
#define vll vector <lli>
#define vpll vector <pll>
#define f first
#define s second
#define pb push_back
#define priq priority_queue
#define unm unordered_map
#define pf push_front
#define minii LLONG_MAX
#define all(x) x.begin(), x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define ld long double
#define eb emplace_back
const long double pi = 3.1415926535898;
const lli mod=1e9+7;
//const lli mod=100000000;
using namespace std;
lli lcm (lli a, lli b) {return ((a*b)/__gcd(a,b));}
lli modpower (lli a,lli b)
{
    if(b==0) return 1;
    lli c=modpower(a,b/2)%mod;
    if (b%2) return (((a*c)%mod)*c)%mod;
    else return (c*c)%mod;
}
lli power (lli a,lli b)
{
    if(b==0) return 1;
    lli c=power(a,b/2);
    if (b%2) return (a*c*c);
    else return c*c;
}
bool prime (lli k)
{
    if (k==1||k==0) return 0;
    bool flag=1;
    lli a=sqrt(k);
    for (int i=2;i<=a;i++)
    {
        if (k%i==0)
        {flag=0;break;}
    }
    return flag;
}
lli sieve (int n)
{
    bool qrr[n+1];
    for (int i=0;i<=n;i++)
    qrr[i]=1;qrr[0]=0;qrr[1]=0;
    for (int i=2;i*i<=n;i++)
    {
        if (qrr[i]==1)
        {
            for (int j=2*i;j<=n;j+=i)
            {qrr[j]=0;}
        }
    }
    return 0;
}
struct trie 
{
    lli next[26];
    string ss;
    bool c;
    trie()
    {
        mem(next,-1);
        c=0;
    }
};
vector <trie> v;
void findall(lli par)
{
    lli p;
    for (int i=0;i<26;i++)
    {
        p=v[par].next[i];
        if (p==-1)
        continue;
        if (v[p].c)
        {
            cout<<v[p].ss<<"\n";
        }
        findall(p);
    }
}
int main()
{
    fio;
    v.eb();
    lli n;
    cin>>n;
    string s,t;
    for (int i=0;i<n;i++)
    {
        cin>>s;
        lli par=0;
        for (int j=0;j<s.length();j++)
        {
            if (s[j]<97)
            s[j]+=32;
            t=v[par].ss;
            t+=s[j];
            if (v[par].next[s[j]-97]==-1)
            {
                v[par].next[s[j]-97]=v.size();
                v.eb();
            }
            par=v[par].next[s[j]-97];
            v[par].ss=t;
        }
        v[par].c=1;
    }
    lli q;
    cin>>q;
    bool f=0;
    lli par;
    while (q--)
    {
        cin>>s;
        par=0;f=0;
        for (int i=0;i<s.length();i++)
        {
            if (v[par].next[s[i]-97]==-1)
            {
                f=1;
                break;
            }
            par=v[par].next[s[i]-97];
        }
        if (f)
        {
            cout<<"No suggestions\n";
            par=0;
            for (int i=0;i<s.length();i++)
            {
                t=v[par].ss;
                t+=s[i];
                if (v[par].next[s[i]-97]==-1)
                {
                    f=1;
                    v[par].next[s[i]-97]=v.size();
                    v.eb();
                }
                par=v[par].next[s[i]-97];
                v[par].ss=t;
            }
            v[par].c=1;
        }
        else
        {
            if (v[par].c)
            {
                cout<<v[par].ss<<"\n";
            }
            findall(par);
        }
    }
    return 0;
}