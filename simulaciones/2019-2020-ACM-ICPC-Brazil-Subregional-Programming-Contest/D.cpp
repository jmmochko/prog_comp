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
#define MAXN 100005
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

int dp[MAXN];
bool vis[MAXN];
vector<int> g[MAXN];
vector<int> g2[MAXN];
bool nohoja[MAXN];
set<pii> valhojas;

// se hace bien
int dfs(int u){
    vis[u] = true;
    if(dp[u]!=0)return dp[u];
    dp[u] = 1;
    for(auto v: g[u]){
        dp[u] += dfs(v);
        nohoja[v] = true;
    }
    return dp[u];
}

void add(int u, int sub){
    //estoy subiendo
    //DGB(u);DGB(sub);
    if(sub==-1){
        vis[u] = true;
        for(auto v: g[u]){
            if(vis[v])continue;
            add(v,-1);
        }
        for(auto v: g2[u]){
            if(vis[v])continue;
            if(dp[v]==dp[u]+1)add(v,dp[u]);
        }
        dp[u] = 0;
        return;
    }
    //bajando
    if(!nohoja[u]){
        valhojas.erase({dp[u],u});
    }
    for(auto v: g2[u]){
        if(dp[v]>dp[u])add(v,sub);
    }
    dp[u] -= sub;
    if(!nohoja[u])valhojas.insert({dp[u],u});
}

int main(){
    //FIN;
    int n,k;
    cin>>n>>k;
    fore(v,1,n){
        int u;
        cin>>u;--u;
        g[v].pb(u);
        g2[v].pb(u);
        g2[u].pb(v);
    }
    fore(i,0,n)if(!vis[i])dfs(i);
    //fore(i,0,n)DGB(dp[i]);
    fore(i,0,n)if(!nohoja[i])valhojas.insert({dp[i],i});
    fore(i,0,n)vis[i] = false;
    int res = 0;
    fore(i,0,k){
        if(valhojas.empty())break;
        auto it = valhojas.end();
        --it;
        res += it->fst;
    //    DGB(it->fst);
    //    DGB(it->snd);
        add(it->snd,-1);
        valhojas.erase(it);
    //    fore(qq,0,n)DGB(dp[qq]);   
    }
    show(res);
    return 0;
}

//Sobrevivimos al pabellon