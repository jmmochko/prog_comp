#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(a,b,c) for(int a=b;a<c;++a)
#define SZ(a) ((int)a.size())
#define fst first
#define snd second
#define all(a) a.begin(),a.end()
#define pb push_back
using namespace std;
typedef long long ll;

ll n,m;

void dfs(ll v,vector<vector<ll>> &g,vector<bool> &vis, vector<ll> &res){
    vis[v] = true;
    res.pb(v);
    for(auto u : g[v]){
        if(!vis[u]){
            res.pb(u);
            dfs(u,g,vis,res);
        }
    }
    return;
}

int main(){
    FIN;
    cin >> n >> m;
    vector<ll> a(n);
    fore(i,0,n){
        cin >> a[i];
    }

    vector<vector<ll>> g(n);

    fore(i,0,m){
        ll a,b; cin >> a >> b, a--,b--;
        g[a].pb(b);
        g[b].pb(a);
    }

    vector<bool> vis(n);
    vector<ll> res(n);
    fore(i,0,n){
        if(!vis[i]){
            vector<ll> indexes;
            dfs(i,g,vis,indexes);
            sort(all(indexes));
            vector<ll> vals;
            for(auto j : indexes){
                vals.pb(a[j]);
            }
            sort(all(vals));
            reverse(all(vals));
            fore(j,0,SZ(vals)){
                res[indexes[j]] = vals[j];
            }
        }
    }
    fore(i,0,n) cout << res[i] << " ";
    cout << "\n";
}