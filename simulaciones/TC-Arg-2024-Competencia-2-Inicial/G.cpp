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
    ll n; cin >> n;
    vector<ii> a(n);
    ll res = 0;

    // max(ci,aj−ai) = ci + max(0,aj-ai-ci);
    fore(i,0,n){
        cin >> a[i].fst >> a[i].snd;
        //si o si usamos los ci en la respuesta
        res += a[i].snd;    
    }
    sort(ALL(a));
    //buscamos llegar a n de la manera mas rapida posible, volver al principio es gratis
    ll maxj = a[0].fst + a[0].snd;

    // max(0,aj-ai-ci);
    fore(i,1,n){
        res += max(0LL, a[i].fst - maxj);
        maxj = max(maxj, a[i].fst + a[i].snd);
    }

    cout << res << "\n";
}

// Gallardo volvio a river
