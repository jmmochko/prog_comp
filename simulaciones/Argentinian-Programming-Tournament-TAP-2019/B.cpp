#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ThxDem=b;i<ThxDem;++i)
#define dfore(a,b,c) for(int a=b; a>=c; --a)
#define DGB(a) cout<<#a<<" = "<<a<<"\n"
#define RAYA cout<<"=============="<<"\n"
#define show(a) cout<<a<<"\n"
#define showAll(a) for(auto i:a) cout<<i<<" ";cout<<"\n"
#define input(a) for(auto& i:a) cin>>i
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
    vector<pair<ii,ll>> a(n);
    fore(i,0,n) cin >> a[i].fst.fst >> a[i].fst.snd >> a[i].snd;

    string res = "SI";
    fore(i,0,n){ fore(j,i+1,n){
        if(i==j) continue;

        // calcular interseccion de 2 puntos con coordenada x y, radio h
        ll x1 = a[i].fst.fst;
        ll y1 = a[i].fst.snd;
        ll r1 = a[i].snd;

        ll x2 = a[j].fst.fst;
        ll y2 = a[j].fst.snd;
        ll r2 = a[j].snd;

        ll dist = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);

        // DGB(dist);
        // DGB(r1);
        // DGB(r2);

        if((r1+r2)*(r1+r2) == dist || dist == (r1 - r2)*(r1 - r2) || (dist < (r1+r2)*(r1+r2) && dist > (r1 - r2)*(r1 - r2))) res = "NO";
    }}
    cout << res << "\n";
}

// euro river
