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

bool g[MAXN][MAXN];

void solve(){
    int n,m;
    cin>>n>>m;
    if(n==1 && m==0){
        show("NO");
        return;
    }
    fore(i,0,m){
        int u,v;
        cin>>u>>v;
        --u;--v;
        g[u][v] = true;
        g[v][u] = true;
    }
    vector<pii> res;
    fore(i,0,n/2){
        fore(j,i+1,n/2+1){
            if(!g[i][j])res.push_back({i+1,j+1});
        }
    }
    fore(i,n/2+1,n-1){
        fore(j,i+1,n){
            if(!g[i][j])res.push_back({i+1,j+1});
        }
    }
    show("YES");
    show(SZ(res));
    fore(i,0,SZ(res)){
        cout<<res[i].fst<<" "<<res[i].snd<<'\n';
    }
}

int main(){
    FIN;
    int t = 1;
    //cin>>t;
    while(t--)solve();
    return 0;
}

//Cue "Eye of the Tiger"