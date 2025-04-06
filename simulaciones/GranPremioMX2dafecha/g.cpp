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
#define MAXN 1000001
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

int dp[MAXN];//peso del subarbol acá
bool vis[MAXN];
vector<int> g[MAXN];

int f(int u){
    int res = 1;
    vis[u] = true;
    for(auto e: g[u]){
        if(!vis[e])res+=f(e);
    }
    dp[u] = res;
    return res;
}

void solve(){
    int n;
    cin>>n;
    fore(i,0,n-1){
        int u,v;
        cin>>u>>v;
        --u;--v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    f(0);
    int mx = 0;
    int occ = 0;
    fore(i,0,n){
        for(auto e: g[i]){
            if(dp[e]>dp[i])continue;
            int valor = (n-dp[e])*dp[e];
            if(valor==mx)++occ;
            if(valor>mx){
                occ = 1;
                mx = valor;
            }
        }
    }
    cout<<mx<<" "<<occ<<'\n';
}

int main(){
    FIN;
    int t = 1;
    //cin>>t;
    while(t--)solve();
    return 0;
}

//Cue "Eye of the Tiger"