#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(a,b,c) for(int a=b;a<c;++a)
#define SZ(a) ((int)a.size())
#define fst first 
#define snd second
#define all(a) a.begin() a.end()
#define pb push_back
using namespace std;
typedef long long ll;

const int MAXN = 1000001;

vector<int> g[MAXN];

void solve(){
    int n,m;
    cin>>n>>m;
    fore(i,0,n)g[i].clear();
    fore(i,0,m){
        int x,y;
        cin>>x>>y;
        --x;--y;
        g[y].pb(x);
        g[x].pb(y);
    }
    
}

int main(){
    FIN;
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}