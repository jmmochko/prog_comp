#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(a,b,c) for(int a=b;a<c;++a)
#define SZ(a) ((int)a.size())
#define fst first 
#define snd second
#define all(a) a.begin(), a.end()
#define pb push_back
using namespace std;
typedef long long ll;

int main(){
    FIN;
    ll n; cin >> n;
    vector<ll> a(n);
    fore(i,0,n) cin >> a[i];
    sort(all(a));
    ll q; cin >> q;
    while(q--){
        ll x; cin >> x;
        cout << distance(a.begin(), upper_bound(all(a), x)) << "\n";
    }
}