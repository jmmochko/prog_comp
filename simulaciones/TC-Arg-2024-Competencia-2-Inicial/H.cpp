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
        ll n,m,k; cin >> n >> m >> k;
        vector<ll> a(n);
        fore(i,0,n) cin >> a[i];

        k = min(k,m-1);
        ll left = m-k;
        // cout << "=================\n";
        ll res = 0;
        dfore(i,k,0){
            ll j = n  - (k-i);
            // cout << i << " " << j << "\n";
            // cout << "=================\n";
            ll ar = LONG_LONG_MAX;
            dfore(hi, i+left-1, i){
                ll hj = j - (i+left-hi);
                // cout << hi << " " << hj << "\n";
                ar = min(ar, max(a[hi],a[hj]));
            }
            // cout << "=====" << ar << "=====\n";
            res = max(res,ar);
            // cout << "=================\n";

        }


        cout << res << "\n";
    }
}

// Gallardo volvio a river
