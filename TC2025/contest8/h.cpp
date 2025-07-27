#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(a,b,c) for(int a=b;a<c;++a)
#define SZ(a) ((int)a.size())
#define fst first
#define snd second
#define all(a) a.begin(),a.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int MAXN = 3e5 + 1;

vector<int> g[MAXN];

vector<vector<int>> res;

bool vis[MAXN];

void dfs(int u, int pres){    
    if(pres == -1){
        pres = SZ(res);
        res.pb({});
    }
    res[pres].pb(u);
    //cout<<"PUSHEE "<<u<<" A "<<pres<<'\n';
    vis[u] = true;
    // añado el primero a pres, los otros que se creen uno nuevo
    bool primero = true;
    for(auto v: g[u]){
        if(vis[v])continue;
        if(primero){
            dfs(v,pres);
            primero = false;
        }
        else{
            pres = SZ(res);
            res.pb({u});
            dfs(v,pres);
        }
    }
}

void solve(){
    int n;
    cin>>n;
    fore(i,0,n)g[i].clear();
    res.clear();
    fore(i,0,n)vis[i] = false;
    fore(i,0,n-1){
        int u,v;
        cin>>u>>v;--u;--v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(0,-1);
    cout<<SZ(res)<<'\n';
    fore(i,0,SZ(res)){
        cout<<res[i][0] + 1<<" "<<res[i][SZ(res[i])-1] + 1<<'\n';
    }
}

int main(){
    FIN;
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}