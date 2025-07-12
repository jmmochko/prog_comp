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
#define MAXN 1001
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

int n,m;
bool vis[MAXN][MAXN];
ll g[MAXN][MAXN];

bool valid(int i, int j){
    return i<n && j<m && i>=0 && j>=0 && g[i][j]>0 && !vis[i][j];
}

vector<pii> D = {{0,1},{1,0},{-1,0},{0,-1}};

ll dfs(int i, int j){
    vis[i][j] = true;
    ll res = g[i][j];
    for(auto d: D){
        int ni = i + d.fst,nj = j + d.snd;
        if(valid(ni,nj))res+=dfs(ni,nj);
    }
    return res;
}

void solve(){
    cin>>n>>m;
    fore(i,0,n)fore(j,0,m){cin>>g[i][j];vis[i][j] = false;}
    ll res = 0;
    fore(i,0,n)fore(j,0,m){
        if(valid(i,j))res = max(res,dfs(i,j));
    }
    show(res);
}

int main(){
    FIN;
    int t = 1;
    cin>>t;
    while(t--)solve();
    return 0;
}

//Cue "Eye of the Tiger"