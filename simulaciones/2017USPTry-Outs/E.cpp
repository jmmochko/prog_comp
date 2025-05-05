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
    ll t = 1;
    // cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<ll> a;
        fore(i,0,n){
            ll aux; cin >> aux;
            a.pb(aux);
        }
        ll res = 0;
        sort(ALL(a));
        while(SZ(a)>=4){
            if(SZ(a)==5){
                ll min1 = a[4] + a[0];
                min1 += min((a[0]+a[0]+a[2]+a[3]),(a[0]+a[1]+a[1]+a[3]));
            }
            ll x = a[0];
            ll y = a[1];
            ll c = a[n-2];
            ll d = a[n-1];
            res += min((x+x+c+d),(x+y+y+d));
            n-=2;
            a.pop_back();
            a.pop_back();
        }
        if(SZ(a)==3){
            res += a[0] + a[1] + a[2];
        }
        if(SZ(a)==2){
            res += a[1];
        }
        if(SZ(a)==1){
            res += a[0];
        }
        cout << res << "\n";
    }
}