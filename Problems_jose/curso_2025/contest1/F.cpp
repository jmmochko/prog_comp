#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(a,b,c) for(int a=b; a<c; ++a)
#define all(a) a.begin(),a.end()
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;

string s;
vector<pll> copias;
vector<ll> largo;

char solve(ll i, ll k){
    if(i==0)return s[k];
    if(k<largo[i-1])return solve(i-1,k);
    
    ll posEnLaCopia = k - largo[i-1];
    ll pos = posEnLaCopia + copias[i].first;

    return solve(i-1,pos);
}

int main(){
    FIN;
    int t;
    cin>>t;
    while(t--){
        ll n,c,q;
        cin>>n>>c>>q;       
        cin>>s;
        copias.clear();
        largo.clear();
        copias.push_back({0,n});
        largo.push_back(n);
        fore(i,0,c){
            ll r,l;
            cin>>l>>r;
            --l;
            copias.push_back({l,r});
            largo.push_back(largo[i] + (r-l));
        }
        while(q--){
            ll k;
            cin>>k;
            cout<<solve(c,k-1)<<'\n';
        }
    }
    return 0;
}