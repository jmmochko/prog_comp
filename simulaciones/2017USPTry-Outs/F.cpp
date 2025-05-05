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
        ll r; cin >> r;
        ll res = 0;
        fore(i,0,3){
            ll x,y; cin >> x >> y;
            double h = sqrt((x*x)+(y*y));
            if(h<=r){
                res += 10;
            } else if(h<=2*r){
                res += 9;
            } else if(h<=3*r){
                res += 8;
            } else if(h<=4*r){
                res += 7;
            } else if(h<=5*r){
                res += 6;
            } else if(h<=6*r){
                res += 5;
            } else if(h<=7*r){
                res += 4;
            } else if(h<=8*r){
                res += 3;
            } else if(h<=9*r){
                res += 2;
            } else if(h<=10*r){
                res += 1;
            }
        }
        cout << res;

    }
}