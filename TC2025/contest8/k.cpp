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

const int MAXN = 2e5 + 3;

vector<int> g[MAXN];
bool blks[MAXN];
bool vis[MAXN];

int dfs(int u){
    vis[u] = true;
    if(blks[u] == true)return 1;
    int res = 1;
    for(auto v: g[u]){
        if(!vis[v])res += dfs(v);
    }
    return res;
}

vector<pair<int,vector<int>>> res; //nodo, vecinos que invita

void dfsvis(int u){
    vis[u] = true;
    vector<int> tores;
    for(auto v: g[u]){
        if(!vis[v]){tores.pb(v);if(blks[v])vis[v] = true;}
        if(!vis[v] && !blks[v]){
            dfsvis(v);
        }
    }
    if(SZ(tores) == 0)return;
    res.pb({u,tores});
}

int main(){
    FIN;
    int n,m,k;
    cin>>n>>m>>k;
    fore(i,0,k){
        int e;
        cin>>e;--e;
        blks[e] = true;
    }
    fore(i,0,m){
        int u,v;
        cin>>u>>v;
        --u;--v;
        g[u].pb(v);
        g[v].pb(u);
    }
    int i = 0;
    while(i<n && blks[i])++i;
    if(i==n || dfs(i) != n){
        cout<<"No\n";
        return 0;
    }
    cout<<"Yes\n";
    fore(d,0,n)vis[d] = false;
    dfsvis(i);
    reverse(all(res));
    cout<<SZ(res)<<'\n';
    fore(d,0,SZ(res)){
        cout<<res[d].fst + 1<<" "<<SZ(res[d].snd)<<" ";
        fore(k,0,SZ(res[d].snd)){
            cout<<res[d].snd[k] + 1<<" ";
        }
        cout<<'\n';
    }
    return 0;
}