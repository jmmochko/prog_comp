#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(a,b,c) for(int a=b;a<c;++a)
#define SZ(a) ((int)a.size())
#define fst first 
#define snd second
#define all(a) a.begin() a.end()
#define pb push_back
#define MAXN 100005
using namespace std;
typedef long long ll;
ll n,m;
int res = 0;
vector<int> g[MAXN];
bool vis[MAXN];
vector<ll> a(MAXN);

void dfs(int u, int llevo){
    if(llevo > m)return;
    vis[u] = true;
    int cnt = 0;
    for(auto v: g[u]){
        if(!vis[v]){
            ++cnt;
            if(a[v] == 1){
                dfs(v,llevo + a[v]);
            }
            else dfs(v,0);
        }
    }
    if(cnt==0)++res;
}

int main(){
    FIN;
    cin >> n >> m;
    fore(i,0,n){
        cin >> a[i];
    }
    fore(i,0,n-1){
        ll a,b; cin >> a >> b; a--,b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(0,a[0]);
    cout<<res<<'\n';
}