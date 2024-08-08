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
#define MAXN 50005
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

vector<vector<int>> g(MAXN);
vector<vector<int>> rg(MAXN);
bool visited[MAXN];
vector<bool> tate(MAXN,0),done(MAXN,false);//1 if it shows, 1 if sub has been completed
int cnt=0;

bool isAv(int u){
    if(!done[u])return false;
    if(tate[u])return true;
    bool res = true;
    for(auto v: rg[u]){
        res = res && isAv(v);
    }
    tate[u] = res;
    if(res)++cnt;
    return tate[u];
}

void upd(int u){
    tate[u] = isAv(u);
    if(!tate[u])return;
    for(auto v: g[u])if(done[v])upd(v);
}

void solve(){
    int n,m;
    cin>>n>>m;
    fore(i,0,m){
        int u,v;
        cin>>u>>v;
        --u;--v;
        g[u].push_back(v);
        rg[v].push_back(u);
    }
    fore(i,0,n){
        int u;
        cin>>u;
        --u;
        done[u] = true;
        upd(u);
        show(cnt);
    }
}

int main(){
    FIN;
    int t = 1;
    //cin>>t;
    while(t--)solve();
    return 0;
}

//Gallardo 2: electric boogaloo