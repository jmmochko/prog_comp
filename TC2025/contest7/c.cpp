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

const ll MAXN = 100005;
vector<ll> g[MAXN];
ll n,m;
struct edge {ll u,v,comp; bool bridge;};
vector<edge> e;
void add_edge(ll u, ll v){
    g[u].pb(e.size()); g[v].pb(e.size());
    e.pb((edge){u,v,-1,false});
}
ll D[MAXN], B[MAXN], T;
ll nbc;
ll art[MAXN];
stack<ll> st;
void dfs(ll u, ll pe){
    B[u]=D[u]=T++;
    for(ll ne : g[u]) if(ne!=pe){
        ll v = e[ne].u ^ e[ne].v ^ u;
        if(D[v]<0){
            st.push(ne); dfs(v, ne);
            if(B[v] > D[u]) e[ne].bridge = true;
            if(B[v] >= D[u]){
                art[u]++;
                ll last;
                do{
                    last = st.top(); st.pop();
                    e[last].comp = nbc;
                } while(last!=ne);
                nbc++;
            }
            B[u] = min(B[u],B[v]);
        }
        else if(D[v] < D[u]) st.push(ne), B[u] = min(B[u], D[v]);
    }
}

void doit(){
    memset(D,-1,n*sizeof(ll)); memset(art,0,n*sizeof(ll));
    nbc=T=0;
    fore(i,0,n) if(D[i]<0) dfs(i,-1),art[i]--;
}

ll dp[MAXN];
vector<ll> g2[MAXN];

ll dfsT(ll u){
    dp[u] = 1;
    for(auto v: g2[u]){
        if(dp[v]==-1){
            dp[u] += dfsT(v);
            dp[u] = min(n,dp[u]);
        }
    }
    return min(n,dp[u]);
}

void solve(){
    cin>>n>>m;
    fore(i,0,n)g[i].clear();
    fore(i,0,n)g2[i].clear();
    fore(i,0,n)B[i] = 0;
    nbc = 0;
    T = 0;
    e.clear();
    fore(i,0,m){
        ll x,y;
        cin>>x>>y;
        --x;--y;
        add_edge(x,y);
        g2[x].pb(y);
        g2[y].pb(x);
    }
    doit();
    fore(i,0,n)dp[i] = -1;
    dfsT(n/2);
    ll tot = n*(n-1)/2;
    ll res = n*(n-1)/2;
    fore(i,0,m){
        if(e[i].bridge){
            ll x = dp[e[i].u],y = dp[e[i].v];
            if(x<y)swap(x,y);
            x = n - y;
            y = y*(y-1)/2;
            x = x*(x-1)/2;
            res = min(res,x + y);
        }
    }
    cout<<res<<'\n';
    fore(i,0,n)g[i].clear();
    fore(i,0,n)g2[i].clear();
    e.clear();
}

int main(){
    FIN;
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}