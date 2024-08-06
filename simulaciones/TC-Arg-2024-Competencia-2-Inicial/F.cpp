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
    ll t; cin >> t;
    while(t--){
        ll n, k; cin >> n >> k;
        vector<ll> pos, neg;
        fore(i,0,n){
            ll aux; cin >> aux;
            if(aux < 0) neg.pb(-aux);
            else if(aux>0)pos.pb(aux);
        }

        sort(ALL(pos));
        sort(ALL(neg));
        // k divide n

        ll res = 0;
        for(ll i = SZ(pos)-1; i >= 0; i-=k) res += 2 * pos[i];
        for(ll i = SZ(neg)-1; i >= 0; i-=k) res += 2 * neg[i];

        res -= max(pos.empty()? 0:pos.back(), neg.empty()? 0:neg.back());


        cout << res << "\n";
        
    }
    
}

// Gallardo volvio a river
