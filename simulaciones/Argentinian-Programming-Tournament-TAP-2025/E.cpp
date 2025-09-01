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

const int MAXN = 200003;

ll val[MAXN];

const int K = 23;

vector<ll> g[1<<K];int n;
int F[K][1<<K],D[1<<K];
void lca_dfs(int x){
    fore(i,0,SZ(g[x])){
        int y = g[x][i];if(y==F[0][x])continue;
        F[0][y] = x;D[y]=D[x] + 1;lca_dfs(y);
    }
}
void lca_init(){
    D[0] = 0; F[0][0] = -1;
    lca_dfs(0);
    fore(k,1,K)fore(x,0,n)
    ////
        if(F[k-1][x]<0)F[k][x]=-1;
        else F[k][x]=F[k-1][F[k-1][x]];
}
int lca(int x,int y){
    if(D[x]<D[y])swap(x,y);
    for(int k=K-1;k>=0;--k)if(D[x]-(1<<k)>=D[y])x=F[k][x];
    if(x==y)return x;
    for(int k=K-1;k>=0;--k)if(F[k][x]!=F[k][y])x=F[k][x],y=F[k][y];
    return F[0][x];
}

ll dist[MAXN];
bool vis[MAXN];
ll smdist[MAXN];
ll lcas[MAXN];// lca de todos los nodos a distancia i

ll md = 0;
vector<ll> nd;

void cdist(ll u, ll d){
    vis[u] = true;
    nd.pb(u);
    dist[u] = d;
    smdist[d] += val[u];
    for(auto v: g[u])if(!vis[v])cdist(v, d+1);
    md = max(d,md);
}
pair<ll,ll> res = {0,1};
void solve(int u){
    cdist(u,0);
    fore(i,0,md+1)lcas[i] = -1;
    for(auto i: nd){
        if(val[i]==0)continue;
        ll d = dist[i];
        if(lcas[d] == -1)lcas[d] = i;
        else lcas[d] = lca(lcas[d],i);
    }
    
    for(auto i: nd){
        ll d = dist[i];
        if(lcas[d] == -1)continue;
        ll p = abs(dist[lcas[d]] - dist[i]);
        if(res.fst < smdist[d]) res = {smdist[d], p};
        if(res.fst == smdist[d] && p<res.snd)res = {smdist[d], p};
    }
    fore(i,0,md+1)smdist[i] = 0;
    md = 0;
    nd.clear();
}

int main(){
    FIN;
    cin>>n;
    fore(i,1,n)cin>>val[i];
    fore(i,0,n-1){
        ll u,v;
        cin>>u>>v;
        --u;--v;
        g[u].pb(v);
        g[v].pb(u);
    }
    vis[0] = true;
    lca_init();
    for(auto u: g[0]){solve(u);}
    cout<<res.fst<<" "<<res.snd+1<<'\n';
    return 0;
}