#include <bits/stdc++.h>
#define fore(a,b,c) for(int a = b; a<c; ++a)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fst first
#define snd second 
#define all(a) a.begin(),a.end()
#define SZ(x) x.size()
#define pb push_back
using namespace std;
typedef long long ll;

const ll INF = 1000000000;

struct Dinic {
    ll nodes, src, dst;
    vector<ll> dist,q,work;
    struct edge {ll to,rev;ll f,cap;};
    vector<vector<edge>> g;
    Dinic(ll x): nodes(x),g(x),dist(x),q(x),work(x){}
    void add_edge(ll s, ll t, ll cap){
        g[s].pb((edge){t,SZ(g[t]),0,cap});
        g[t].pb((edge){s,SZ(g[s])-1,0,0});
    }
    bool dinic_bfs(){
        fill(all(dist),-1);dist[src]=0;
        ll qt = 0; q[qt++]=src;
        for(ll qh=0;qh<qt;qh++){
            ll u = q[qh];
            fore(i,0,SZ(g[u])){
                edge &e = g[u][i]; ll v = g[u][i].to;
                if(dist[v]<0&&e.f<e.cap) dist[v]=dist[u]+1,q[qt++]=v;
            }
        }
        return dist[dst]>=0;
    }

    ll dinic_dfs(ll u, ll f){
        if(u==dst)return f;
        for(ll &i = work[u];i<SZ(g[u]);i++){
            edge &e = g[u][i];
            if(e.cap<=e.f){
                ll v = e.to;
                if(dist[v] == dist[u]+1){
                    ll df = dinic_dfs(v,min(f,e.cap-e.f));
                    if(df>0){e.f+=df;g[v][e.rev].f -= df;return df;}
                }
            }
        }
        return 0;
    }
    
    ll max_flow(ll _src, ll _dst){
        src = _src; dst = _dst;
        ll result = 0;
        while(dinic_bfs()){
            fill(all(work),0);
            while(ll delta = dinic_dfs(src, INF)) result += delta;
        }
        return result;
    }
};


bool cmp(pair<ll,ll> x, pair<ll,ll>y){
    if(x.snd == y.snd) return x.fst <= y.fst;
    return x.snd <= y.snd;
}

int main(){
    FIN;
    return 0;
    ll n; cin >> n;
    vector<pair<ll,ll>> g1(n),g2(n);
    fore(i,0,n){
        ll a1,a2; cin >> a1 >> a2;
        g1[i] = {a1,a2};
        g2[i] = {a1,a2};
    }
    sort(all(g1));
    sort(all(g2),cmp);

    fore(k,1,n){
        // hacemos el dinic para g1
        Dinic d1(n);
        
        fore(i,0,n-k){
            Dinic d1(n);
            d1.add_edge(-1,i,INF);
        }
    }
}