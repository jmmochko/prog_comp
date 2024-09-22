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
#define MAXN 200005
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

bool vis[MAXN];
bool val[MAXN];

vector<int> g[MAXN];

bool dfs(int x){
    vis[x] = true;
    for(auto y: g[x]){
        if(vis[y] && val[y]==val[x])return false;
        if(vis[y])continue;
        val[y] = !val[x];
        if(!dfs(y))return false;
    }
    return true;
}

void solve(){
    int n,m;
    cin>>n>>m;
    fore(i,0,m){
        int x,y;
        cin>>x>>y;
        --x;--y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    fore(i,0,n){
        if(vis[i])continue;
        if(!dfs(i)){
            show("IMPOSSIBLE");
            return;
        }
    }
    fore(i,0,n)cout<<val[i]+1<<" ";cout<<'\n';
}

int main(){
    FIN;
    int t = 1;
    //cin>>t;
    while(t--)solve();
    return 0;
}

//Sale regional?