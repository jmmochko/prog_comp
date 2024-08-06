#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ThxDem=b;i<ThxDem;++i)
#define dfore(a,b,c) for(int a=b; a>=c; --a)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) ll(s.size())
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){
    FIN;
    ll n,m; cin >> n >> m;
    ll res = 0;
    bool flag = false;
    vector<vector<ll>> mt(n,vector<ll>(m));
    fore(i,0,n) fore(j,0,m){
        cin >> mt[i][j];
        res += mt[i][j];
    }


    dfore(i,n-1,0){
        dfore(j,m-1,0){
            if(mt[i][j]==0){
                mt[i][j] = min(mt[i][j+1]-1, mt[i+1][j]-1);
                res += mt[i][j];
            }
        }
    }
    

    fore(i,0,n) fore(j,0,m){
        if(j>0){
            if(mt[i][j-1]>=mt[i][j]) flag = true;
        }
        if(i>0){
            if(mt[i-1][j]>=mt[i][j]) flag = true;
        }
    }


    if(flag) cout << -1 << "\n";
    else cout << res << "\n";
    

}

// Gallardo volvio a river
