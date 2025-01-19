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
#define MAXN 404
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

int n;
vector<pair<int,ll>> g[MAXN];//<i,c>
ll dist[MAXN];
void bford(int src){ // O(nm)
	fill(dist,dist+n,MAXll);dist[src]=0;
	fore(_,0,n)fore(x,0,n)if(dist[x]!=MAXll)for(auto t:g[x]){
		dist[t.fst]=min(dist[t.fst],dist[x]+t.snd);
	}
	fore(x,0,n)if(dist[x]!=MAXll)for(auto t:g[x]){
		if(dist[t.fst]>dist[x]+t.snd){
			// neg cycle: all nodes reachable from t.fst have -MAXll distance
			// to reconstruct neg cycle: save "prev" of each node, go up from t.fst until repeating a node. this node and all nodes between the two occurences form a neg cycle
		}
	}
}

void solve(){
    int m,q;
    cin>>n>>m>>q;
    fore(i,0,n)g[i].clear();
    fore(i,0,m){
        int u,v;
        ll w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    vector<pair<int,pair<int,int>>> qs(q); //<<k,<a,b>>
    fore(i,0,q){
        cin>>qs[i].snd.fst>>qs[i].snd.snd>>qs[i].fst;
    }
    sort(all(qs));
    reverse(all(qs));
    
}

int main(){
    FIN;
    int t = 1;
    cin>>t;
    while(t--)solve();
    return 0;
}

//Cue "Eye of the Tiger"