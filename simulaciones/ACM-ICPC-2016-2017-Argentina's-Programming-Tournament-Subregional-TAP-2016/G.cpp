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
#define ALPH 30
#define M 1000000007
#define MAXINT (1<<30)
#define MAXll (1ll<<60)
#define PI 3.141592653
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

//El Vasito is love, El Vasito is life

vector<pair<int,vector<int>>> g[MAXN];//cost as number of tickets of each price
bool vis[MAXN];

vector<int> dfs(int u){//amount of each bill paid in subtree
    vector<int> cur(ALPH,0);
    for(auto v: g[u]){
        if(!vis[v.first]){
            vector<int> cpm = dfs(v.first);
            fore(i,0,ALPH)cur[i]+=cpm[i];
        }
    }
}

void solve(){
    int n;
    cin>>n;
    fore(i,0,n-1){
        int u,v;
        ll c;
        cin>>u>>v>>c;
        --u;--v;
        //c to costs
        vector<int> cur(ALPH,0);
        fore(k,0,ALPH){
            if(c&(1ll<<k)){
                cur[k]++;
            }
        }
        g[u].push_back({v,cur});
        g[v].push_back({u,cur});
    }
}

int main(){
    FIN;
    int t = 1;
    //cin>>t;
    while(t--)solve();
    return 0;
}

//Gallardo A Boca...