#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ThxDem=b;i<ThxDem;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) ll(s.size())
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

void bfs(ll v, vector<set<ll>> &g, set<ll> &unvis, vector<bool> &vis) {

    vis[v] = true;

    queue<ll> q,td;
    q.push(v);

    while (!q.empty()) {

        v = q.front();
        q.pop();
        
        for (ll u : unvis) {

            if (!vis[u] && g[v].find(u) == g[v].end()) {
                
                td.push(u);
		        vis[u] = true;
			    q.push(u);

            }
        }

        while(!td.empty()) unvis.erase(td.front()), td.pop(); // optimizacion para no repetir los no visitdaos
    }
}


int main(){
    FIN;
    ll n,m; cin >> n >> m;
    vector<set<ll>> g(n);
    fore(i,0,m){
        ll a,b; cin >> a >> b; a--;b--;
        g[a].insert(b);
        g[b].insert(a);
    }
    vector<bool> vis(n,false);
    set<ll> unvis;
    fore(i,0,n){
        unvis.insert(i);
    }
    ll res = 0;
    fore(i,0,n){
        if(!vis[i]){
            bfs(i,g,unvis,vis);
            res++;
        }
    }
    cout << res-1 << "\n";
}

// Gallardo vuelve a river
