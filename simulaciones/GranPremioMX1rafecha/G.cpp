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
        vector<ll> a(n);
        input(a);
        sort(ALL(a));
        if(a[0]==1 && a[n-1]!=1) show("Bobius");
        else show("Alicius");
    }

}


//La manera mas optima de jugar es obligar al enemigo a sacar 1 siempre
//    - Si la proxima torre mas baja tiene altura h, saco h-1 piedras entonces el enemigo tiene que sacar 1
//    - Si la primera torre mas baja tiene largo 1 entonces el otro va a hacer lo mismo
//    - Si todas las torres tienen largo 1 entonces gano igual

// 0 2 3 4