#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(a,b,c) for(int a=b;a<c;++a)
#define SZ(a) ((int)a.size())
#define fst first
#define snd second
#define ALL(a) a.begin(),a.end()
#define pb push_back
#define DGB(a) cout<<#a<<" = "<<a<<'\n';
using namespace std;
typedef long long ll;

const ll INF = 1e9;
struct edge {int to,rev;ll f,cap;};

struct Dinic{
	int nodes,src,dst;
	vector<int> dist,q,work;	
	vector<vector<edge>> g;
	Dinic(int x):nodes(x),g(x),dist(x),q(x),work(x){}
	void add_edge(int s, int t, ll cap){
		g[s].pb((edge){t,SZ(g[t]),0,cap});
		g[t].pb((edge){s,SZ(g[s])-1,0,0});
	}
	bool dinic_bfs(){
		fill(ALL(dist),-1);dist[src]=0;
		int qt=0;q[qt++]=src;
		for(int qh=0;qh<qt;qh++){
			int u=q[qh];
			fore(i,0,SZ(g[u])){
				edge &e=g[u][i];int v=g[u][i].to;
				if(dist[v]<0&&e.f<e.cap)dist[v]=dist[u]+1,q[qt++]=v;
			}
		}
		return dist[dst]>=0;
	}
	ll dinic_dfs(int u, ll f){
		if(u==dst)return f;
		for(int &i=work[u];i<SZ(g[u]);i++){
			edge &e=g[u][i];
			if(e.cap<=e.f)continue;
			int v=e.to;
			if(dist[v]==dist[u]+1){
				ll df=dinic_dfs(v,min(f,e.cap-e.f));
				if(df>0){e.f+=df;g[v][e.rev].f-=df;return df;}
			}
		}
		return 0;
	}
	ll max_flow(int _src, int _dst){
		src=_src;dst=_dst;
		ll result=0;
		while(dinic_bfs()){
			fill(ALL(work),0);
			while(ll delta=dinic_dfs(src,INF))result+=delta;
		}
		return result;
	}
};

int n,m;
vector<pair<int,int>> ps;

bool can(int k){
    Dinic d(n+m+2);
    fore(i,0,m){
        int x = ps[i].fst,y = ps[i].snd;
        d.add_edge(x,n+1+i,1);
        d.add_edge(y,n+1+i,1);
    }
    fore(i,n+1,n+m+1){
        d.add_edge(i,n+m+1,1);
    }
    fore(i,1,n+1){
        d.add_edge(0,i,k);
    }
    return d.max_flow(0,n+m+1) == m;
}

int main(){
    FIN;
    cin>>n>>m;
    fore(i,0,m){
        int x,y;
        cin>>x>>y;
        ps.pb({x,y});
    }
    int l = -1, r = n;
    while(l+1<r){
        int medio = (l+r)/2;
        if(can(medio)){
            r = medio;
        }
        else l = medio;
    }
    cout<<r<<'\n';
    Dinic d(n+m+2);
    fore(i,0,m){
        int x = ps[i].fst,y = ps[i].snd;
        d.add_edge(x,n+1+i,1);
        d.add_edge(y,n+1+i,1);
    }
    fore(i,n+1,n+m+1){
        d.add_edge(i,n+m+1,1);
    }
    fore(i,1,n+1){
        d.add_edge(0,i,r);
    }
    d.max_flow(0,n+m+1);
    vector<pair<int,int>> res;
    fore(i,1,n+1){
        fore(u,0,SZ(d.g[i])){
            edge &e=d.g[i][u];
            if(e.f == 1){
                int to = e.to - (n+1);
                int rec = ps[to].fst;
                if(rec == i){
                    rec = ps[to].snd;
                }
                res.pb({i,rec});
            }
        }
    }
    fore(i,0,m){
        cout<<res[i].fst<<" "<<res[i].snd<<'\n';
    }
    return 0;
}