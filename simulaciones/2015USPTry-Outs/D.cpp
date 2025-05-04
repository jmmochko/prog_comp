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
#define MAXN 100001
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

vector<pair<int,int> > g[MAXN];  // u->[(v,cost)]
int dist[MAXN];
void dijkstra(int x){
	priority_queue<pair<ll,int> > q;
	dist[x]=0;q.push({0,x});
	while(!q.empty()){
		x=q.top().snd;ll c=-q.top().fst;q.pop();
		if(dist[x]!=c)continue;
		fore(i,0,g[x].size()){
			int y=g[x][i].fst; ll c=g[x][i].snd;
			if(dist[y]<0||dist[x]+c<dist[y])
				dist[y]=dist[x]+c,q.push({-dist[y],y});
		}
	}
}

void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    fore(i,0,n){g[i].clear();}
    fore(i,0,m){
        int a,b,c;
        cin>>a>>b>>c;
        --a;--b;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    memset(dist,-1,sizeof(int)*n);
    dijkstra(n-1);
    fore(i,0,n)if(dist[i]<0)dist[i] = MAXINT;
    int i = 0,acc = 0;
    double res = dist[0];
    sort(dist,dist+n);
    while(i<n && dist[i]<MAXINT){
        acc += dist[i];
        double camino = 0;
        if(i>0)camino = (double)acc/(double)(i+1);
        double cntpasos = (double)n/(double)(i+1);
        res = min(res,((double)k * cntpasos) + camino);
        ++i;
    }
    cout<<setprecision(9)<<fixed<<res<<'\n';
}

int main(){
    FIN;
    int t = 1;
    cin>>t;
    while(t--)solve();
    return 0;
}

//Cue "Eye of the Tiger"