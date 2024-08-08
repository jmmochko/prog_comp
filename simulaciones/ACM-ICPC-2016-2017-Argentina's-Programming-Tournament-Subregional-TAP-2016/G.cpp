#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define fore(a,b,c) for(int a=b; a<c; ++a)
#define dfore(a,b,c) for(int a=b; a>=c; --a)
#define SZ(a) ((int)a.size())
#define fst first
#define snd second
#define show(a) cout<<a<<"\n"
#define showAll(a) for(auto i:a) cout<<i<<" ";cout<<"\n"
#define input(a) for(auto& i:a) cin>>i
#define all(a) a.begin(),a.end()
#define DGB(a) cout<<#a<<" = "<<a<<"\n"
#define RAYA cout<<"=============="<<"\n"
#define pii pair<int,int>
#define pll pair<ll,ll>
#define MAXN 100005
#define ALPH 30
#define M 1000000007
#define MAXINT (1<<30)
#define MAXll (1ll<<60)
#define PI 3.141592653
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

//El Vasito is love, El Vasito is life

vector<pair<int,int>> g[MAXN];
int stcost[MAXN];
bool vis[MAXN];

void dfs(int u, int carry){
    vis[u] = true;
    for(auto v: g[u]){
        if(!vis[v.first])dfs(v.first,carry^v.second);
    }
    stcost[u] = carry;
}

vector<pair<char,vector<int>>> trie;

void trieAdd(string &s){
    int v = 0;
    fore(i,0,SZ(s)){
        int next = -1;
        fore(k,0,SZ(trie[v].second)){
            if(trie[trie[v].second[k]].first==s[i])next = trie[v].second[k];
        }
        if(next==-1){
            trie.push_back({s[i],{}});
            next = SZ(trie)-1;
            trie[v].second.push_back(next);
        }
        v = next;
    }
}

string trieMaximize(string &s){
    int v = 0;
    string res="";
    fore(i,0,SZ(s)){
        int next = trie[v].second[0];
        fore(k,0,SZ(trie[v].second)){
            if(trie[trie[v].second[k]].first!=s[i])next = trie[v].second[k];
        }
        res.push_back(trie[next].first);
        v = next;
    }
    return res;
}

string bitstring(int x){
    string res = "";
    int cmp = 0;
    while((1ll<<cmp)<=x){
        res.push_back((char)('0'+(bool)((1ll<<cmp)&x)));
        ++cmp;
    }
    while(SZ(res)<31){
        res.push_back('0');
    }
    reverse(all(res));
    return res;
}

void solve(){
    int n;
    cin>>n;
    fore(i,0,n-1){
        int a,b,c;
        cin>>a>>b>>c;
        --a;--b;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    dfs(0,0);
    //respond for all i max_{k in range n-1} stcost[i]^stcost[k]
    trie.push_back({'R',{}});
    string itos[n];
    fore(i,0,n){
        itos[i] = bitstring(stcost[i]);
        trieAdd(itos[i]);
    }
    fore(i,0,n){
        string res = trieMaximize(itos[i]);
        reverse(all(res));
        ll cmp = 0;
        fore(k,0,SZ(res)){
            cmp += (1ll<<k)*(res[k]-'0');
        }
        show((stcost[i]^cmp));
    }
}

int main(){
    //FIN;
    int t = 1;
    //cin>>t;
    while(t--)solve();
    return 0;
}

//Gallardo A Boca...