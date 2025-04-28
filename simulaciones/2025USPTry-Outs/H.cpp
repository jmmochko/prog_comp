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
#define MAXN 5001
#define MAXM 5001
#define ALPH 26
#define MAXINT (1<<30)
#define MAXll (1ll<<60)
#define PI 3.141592653
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

vector<int> g[MAXN]; // [0,n)->[0,m)
int n,m;
int mat[MAXM];bool vis[MAXN];
int match(int x){
    if(vis[x])return 0;
	vis[x]=true;
	for(int y:g[x])if(mat[y]<0||match(mat[y])){mat[y]=x;return 1;}
	return 0;
}
vector<pair<int,int> > max_matching(){
	vector<pair<int,int> > r;
	memset(mat,-1,sizeof(mat));
	fore(i,0,n)memset(vis,false,sizeof(vis)),match(i);
	fore(i,0,m)if(mat[i]>=0)r.pb({mat[i],i});
	return r;
}

void solve(){
    int N,M;
    cin>>N>>M;
    fore(i,0,M+1)g[i].clear();
    int G[N][N];
    vector<int> GG[N];
    fore(i,0,N)fore(j,0,N)G[i][j] = -1;
    fore(i,0,M){
        int u,v;
        cin>>u>>v;
        --u;--v;
        G[u][v] = i;
        G[v][u] = i;
        GG[u].pb(v);
        GG[v].pb(u);
        g[i].clear();
    }
    fore(i,0,N)fore(j,0,M){
        if(G[i][j]!=-1){
            int a = G[i][j];
            for(auto x: GG[i]){
                if(G[x][i]>a)g[a].pb(G[x][i]);
                if(G[x][j]>a)g[a].pb(G[x][j]);
            }
        }
    }
    n = M;
    m = M;
    vector<pii> res = max_matching();
    fore(i,0,SZ(res)){
        DGB(res[i].fst);DGB(res[i].snd);
    }
    show(SZ(res));
}

int main(){
    FIN;
    int t = 1;
    cin>>t;
    while(t--)solve();
    return 0;
}