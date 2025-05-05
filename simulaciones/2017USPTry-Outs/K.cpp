        
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

ll f(ll k){
    if(k==0) return 1;
    else if(k==1) return 3;
    else return ((f(k-1) - f(k-2)) * 3 + f(k-2));

}

int main(){
    FIN;
    ll t = 1;
    // cin >> t;
    while(t--){
        ll k; cin >> k;
        cout << f(k) << "\n";
    }
}