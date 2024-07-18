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
#define M 1000000007
#define MAXINT (1<<30)
#define MAXll (1ll<<60)
#define PI 3.141592653
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

//El Vasito is love, El Vasito is life
vector<int> G[MAXN];
ll stsz[MAXN];

ll dfssz(int u){
    stsz[u] = 1;
    for(auto v: G[u])if(stsz[v]==-1)stsz[u]+=dfssz(v);
    return stsz[u];
}

vector<int> g[MAXN];ll n;
struct edge {int u,v,comp;bool bridge;};
vector<edge> e;
void add_edge(int u, int v){
	g[u].pb(e.size());g[v].pb(e.size());
	e.pb((edge){u,v,-1,false});
}
int D[MAXN],B[MAXN],T;
int nbc;  // number of biconnected components
int art[MAXN];  // articulation point iff !=0
stack<int> st;  // only for biconnected
void dfs(int u,int pe){
	B[u]=D[u]=T++;
	for(int ne:g[u])if(ne!=pe){
		int v=e[ne].u^e[ne].v^u;
		if(D[v]<0){
			st.push(ne);dfs(v,ne);
			if(B[v]>D[u])e[ne].bridge = true; // bridge
			if(B[v]>=D[u]){
				art[u]++; // articulation
				int last; // start biconnected
				do {
					last=st.top();st.pop();
					e[last].comp=nbc;
				} while(last!=ne);
				nbc++;    // end biconnected
			}
			B[u]=min(B[u],B[v]);
		}
		else if(D[v]<D[u])st.push(ne),B[u]=min(B[u],D[v]);
	}
}

void doit(){
	memset(D,-1,sizeof(D));memset(art,0,sizeof(art));
	nbc=T=0;
	fore(i,0,n)if(D[i]<0)dfs(i,-1),art[i]--;
}

void solve(){
    
    int m;
    cin>>n>>m;
    fore(i,0,n+1){
        g[i].clear();
        G[i].clear();
        stsz[i]=-1;
    }
    int u,v;
    fore(i,0,m){
        cin>>u>>v;
        --u;--v;
        G[u].push_back(v);
        G[v].push_back(u);
        add_edge(u,v);
    }
    doit();
    dfssz(0);
    //fore(i,0,n)cout<<stsz[i]<<" ";cout<<'\n';
    ll res = (n*(n-1ll))/2ll;
    for(auto bridge: e){
        if(bridge.bridge){
            //DGB(bridge.u);DGB(bridge.v);RAYA;
            ll sza = min(stsz[bridge.u],stsz[bridge.v]),other = n-sza;
            res = min(res,(sza*(sza-1ll))/2ll + (other*(other-1ll))/2ll);
        }
    }
    show(res);
    fore(i,0,n+1){
        g[i].clear();
        G[i].clear();
        stsz[i]=-1;
    }
    e.clear();
}

int main(){
    FIN;
    int t = 1;
    cin>>t;
    while(t--)solve();
    return 0;
}

//Escuchen, corran la bola...