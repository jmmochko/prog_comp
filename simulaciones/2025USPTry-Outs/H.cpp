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
#define MAXN 1001
#define MAXM 1001
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
    n = N; m = N;
    fore(i,0,n)g[i].clear();
    fore(i,0,M){
        int u,v;
        cin>>u>>v;
        --u;--v;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    vector<pii> res = max_matching();
    int dobles = SZ(res)/2;
    /*DGB(dobles);
    DGB(max(0,(n-(2*dobles))));
    fore(i,0,dobles){
        cout<<res[i].fst<<" "<<res[i].second<<'\n';
    }*/
    show(dobles + max(0,(n-(2*dobles))));
}

int main(){
    FIN;
    int t = 1;
    cin>>t;
    while(t--)solve();
    return 0;
}