#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(a,b,c) for(ll a=b;a<c;++a)
#define SZ(a) ((int)a.size())
#define fst first
#define snd second
#define all(a) a.begin(),a.end()
#define pb push_back
#define DGB(i) cout<<#i<<" = "<<i<<'\n'
using namespace std;
typedef long long ll;
const ll MAXN = 100005;
vector<pair<ll,ll>> g[MAXN];
ll dist[MAXN];
vector<pair<ll,ll>> g2[MAXN];
ll dist2[MAXN];
ll n,m,s,t;
vector<ll> g3[MAXN];

struct edge {ll u, v, comp; bool bridge;};
vector<edge> e;
void add_edge(ll u, ll v){
    g3[u].pb(e.size());g3[v].pb(e.size());
    e.pb((edge){u,v,-1,false});
}
ll D[MAXN], B[MAXN],T;
ll art[MAXN];
void dfs(ll u, ll pe){
    B[u]=D[u]=T++;
    for(ll ne : g3[u]) if(ne!=pe){
        ll v = e[ne].u^e[ne].v^u;
        if(D[v]<0){
            dfs(v,ne);
            if(B[v]>D[u]) e[ne].bridge = true;
            if(B[v] >= D[u]){
                art[u]++;
            }
            B[u] = min(B[u],B[v]);
        }
        else if(D[v] < D[u])B[u] = min(B[u],D[v]);
    }
}

void doit(){
    memset(D,-1,sizeof(D)); memset(art,0,sizeof(art));
    fore(i,0,n) if(D[i] < 0) dfs(i,-1), art[i]--;
}

void dijkstra(ll x){
	memset(dist,-1,sizeof(dist));
	priority_queue<pair<ll,ll> > q;
	dist[x]=0;q.push({0,x});
	while(!q.empty()){
		x=q.top().snd;ll c=-q.top().fst;q.pop();
		if(dist[x]!=c)continue;
		fore(i,0,g[x].size()){
			ll y=g[x][i].fst; ll c=g[x][i].snd;
			if(dist[y]<0||dist[x]+c<dist[y])
				dist[y]=dist[x]+c,q.push({-dist[y],y});
		}
	}
}

void Rdijkstra(ll x){
	memset(dist2,-1,sizeof(dist2));
	priority_queue<pair<ll,ll> > q;
	dist2[x]=0;q.push({0,x});
	while(!q.empty()){
		x=q.top().snd;ll c=-q.top().fst;q.pop();
		if(dist2[x]!=c)continue;
		fore(i,0,g2[x].size()){
			ll y=g2[x][i].fst; ll c=g2[x][i].snd;
			if(dist2[y]<0||dist2[x]+c<dist2[y])
				dist2[y]=dist2[x]+c,q.push({-dist2[y],y});
		}
	}
}

int main(){
    FIN;
    cin >> n >> m >> s >> t;
    --s;--t;
    vector<ll> u(m),v(m),c(m);
    map<pair<ll,ll>,ll> salio;//minimo costo
    fore(i,0,m){
        cin >> u[i] >> v[i] >> c[i];
        u[i]--;v[i]--;
        if(salio.count({u[i],v[i]})){
            salio[{u[i],v[i]}] = min(salio[{u[i],v[i]}],c[i]);
        }
        else{
            salio[{u[i],v[i]}] = c[i];
        }
    }
    for(auto arista: salio){
        ll x = arista.fst.fst, y = arista.fst.snd, costo = arista.snd;
        g[x].pb({y,costo});
        g2[y].pb({x,costo});
    }
    dijkstra(s);
    Rdijkstra(t);
    //marcar que aparecen en caminos minimos
    vector<bool> valNode(n,false);
    fore(i,0,n){
        if(dist[i] + dist2[i] == dist[t])valNode[i] = true;
    }
    // busco puentes
    vector<bool> loVi(n,false);
    map<ll,ll> comoPuente;
    ll cnt = 0;
    fore(i,0,m){
        ll x = dist[u[i]],y = c[i],z = dist2[v[i]], d = dist[t];
        //DGB(x);DGB(y);DGB(z);DGB(d);
        if(x+y+z == d){
            add_edge(u[i],v[i]);
            comoPuente[i] = cnt;
            ++cnt;
            loVi[u[i]] = true;
            loVi[v[i]] = true;       
        }
    }
    //fore(i,0,n)if(!loVi[i])add_edge(0,i);
    doit();
    fore(i,0,m){
        ll x = dist[u[i]],y = c[i],z = dist2[v[i]], d = dist[t];
        //DGB(x);DGB(y);DGB(z);DGB(d);
        if(dist[t] == -1){
            cout<<"NO\n";
            continue;
        }
        if(x==-1 || z == -1){
            cout<<"NO\n";
            continue;
        }
        if(x+y+z == d && e[comoPuente[i]].bridge){
            cout<<"YES\n";
            continue;
        }
        ll necesito = d - x - z - 1;
        if(c[i] - necesito <= 0){
            cout<<"YES\n";
            continue;
        }
        //DGB(necesito);
        if (necesito > 0 && c[i] - necesito > 0 && necesito < c[i]){
            cout<<"CAN "<<c[i] - necesito <<'\n';
            continue;
        }
        cout<<"NO\n";
    }
}