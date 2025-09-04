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
#define MAXN 200005
#define ALPH 26
#define M 998244353
#define MAXINT (1<<30)
#define MAXll (1ll<<60)
#define PI 3.141592653
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

//El Vasito is love, El Vasito is life

ll add(ll a, ll b){
    return (a+b)%M;
}

ll mul(ll a, ll b){
    return (a*b)%M;
}

vector<pair<int,ll>> g[MAXN];
ll unos[MAXN],ceros[MAXN],invs[MAXN];//unos, ceros e inversiones del cacho de string al procesar este nodo
bool vis[MAXN];

ll init1(int u){
    if(vis[u])return unos[u];
    vis[u] = true;
    for(auto v:g[u]){
        if(v.snd == 1)unos[u] = add(1,unos[u]);
        unos[u] = add(unos[u],init1(v.fst));
    }
    return unos[u];
}

ll init0(int u){
    if(vis[u])return ceros[u];
    vis[u] = true;
    for(auto v:g[u]){
        if(v.snd == 0)ceros[u] = add(1,ceros[u]);
        ceros[u] = add(ceros[u],init0(v.fst));
    }
    return ceros[u];
}

ll dfs(int u, ll llevo){//vertice, cantidad de 1s que llevo
    if(vis[u])return invs[u]%M;
    llevo = 0;
    vis[u] = true;
    for(auto v:g[u]){
        if(v.snd == 0)invs[u] = add(invs[u],llevo);
        else llevo = add(1,llevo);
        invs[u] = add(invs[u],add(dfs(v.fst,llevo),mul(llevo,ceros[v.fst])));
        llevo = add(llevo,unos[v.fst]);
    }
    return invs[u]%M;
}

int main(){
    FIN;
    int n;
    cin>>n;
    fore(i,0,n){
        int s;
        cin>>s;
        fore(j,0,s){
            ll u,w;
            cin>>u>>w;--u;
            g[i].pb({u,w});
        }
    }
    init0(0);
    fore(i,0,n)vis[i] = false;
    init1(0);
    fore(i,0,n)vis[i] = false;
    cout<<dfs(0,0)<<'\n';
    //fore(i,0,n){DGB(i);DGB(ceros[i]);DGB(unos[i]);DGB(invs[i]);RAYA;}
    return 0;
}

//Sobrevivimos al pabellon