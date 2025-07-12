#include <bits/stdc++.h>
#define fore(a,b,c) for(int a = b; a<c; ++a)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fst first
#define snd second 
#define all(a) a.begin(),a.end()
using namespace std;
typedef long long ll;

vector<pair<ll,ll>> fact(ll x){
    int i = 2;
    vector<pair<ll,ll>> res;
    while(i*i<=x){
        if(x%i==0){
            res.push_back({i,0});
        }
        while(x%i==0){
            res[res.size()-1].snd++;
            x/=i;
        }
        ++i;
    }
    if(x!=1){
        res.push_back({x,1});
    }
    return res;
}

void solve(){
    ll p,q;
    cin>>p>>q;
    if(p%q != 0){
        cout<<p<<'\n';
        return;
    }
    vector<pair<ll,ll>> ft = fact(q);
    ll res = 0;
    fore(i,0,ft.size()){
        ll np = p, cmp = 1;
        fore(k,0,ft[i].snd)cmp*=ft[i].fst;
        while(np%cmp == 0){
            np /= ft[i].fst;
        }
        res = max(res,np);
    }
    cout<<res<<'\n';
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