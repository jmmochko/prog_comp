#include <bits/stdc++.h>
#define fore(a,b,c) for(int a=b; a<c; ++a)
#define MAXN 200005
#define MAXll (1ll<<60)
#define fst first
#define snd second 
typedef long long ll;
using namespace std;

vector<pair<int,ll> > g[MAXN];  // u->[(v,cost)]
ll dist[MAXN];
void dijkstra(int x){
	memset(dist,-1,sizeof(dist));
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

int main(){
    int n,m;
    cin>>n>>m;
    fore(_,0,m){
        int a,b;ll c;
        cin>>a>>b>>c;
        g[a].push_back({b,c});
    }
    dijkstra(1);
    fore(i,1,n+1)cout<<dist[i]<<" ";cout<<'\n';
    return 0;
}