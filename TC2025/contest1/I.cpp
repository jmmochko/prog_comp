#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(a,b,c) for(int a = b; a<c; ++a)
#define ALL(a) a.begin(),a.end()
#define snd second
#define fst first
#define pii pair<int,int>
#define SZ(a) ((int)a.size())
#define pb push_back
using namespace std;
typedef long long ll;

const int INF = 1e9;

// Min cut: nodes with dist>=0 vs nodes with dist<0
// Matching MVC: left nodes with dist<0 + right nodes with dist>0
struct Dinic{
	int nodes,src,dst;
	vector<int> dist,q,work;
	struct edge {int to,rev;ll f,cap;};
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

int brute(vector<ll> nums){
    int res = 0;
    fore(elijo,0,1<<SZ(nums)){
        vector<int> cnt(60,0);
        fore(i,0,SZ(nums)){//para cada numero sumo sus bits
            if(!(elijo & (1ll<<i)))continue;
            fore(b,0,60){
                if((1ll<<b) & nums[i])++cnt[b];
            }
        }
        int bs = 0, largo = 0;
        fore(b,0,60)if(cnt[b])++bs;
        fore(b,0,60)if((elijo & (1ll<<b)))++largo;
        res = max(res,largo - bs);
    }
    return res;
}

int solve(vector<ll> &nums){
    int n = SZ(nums);
    Dinic D(n+63);
    //edges 0 = S, n+62 = T
    // 1,..,n => nums
    // n+1,...,n+60 => bits
    // S -> bit con cap 1
    fore(i,n+1,n+61)D.add_edge(0,i,1);
    // bit -> num sii num tiene prendido este bit
    fore(b,0,60){
        fore(i,0,n){
            if(nums[i] & (1ll<<b)){
                D.add_edge(n+1+b,i+1,INF);
            }
        }
    }
    //num -> T con cap 1
    fore(i,0,n){
        D.add_edge(i+1,n+62,1);
    }
    ll mcut = D.max_flow(0,n+62);
    //cout<<mcut<<'\n';
    return n - mcut;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<ll> nums(n);
        fore(i,0,n)cin>>nums[i];
        //cout<<(brute(nums))<<'\n';
        cout<<solve(nums)<<'\n';
    }
}