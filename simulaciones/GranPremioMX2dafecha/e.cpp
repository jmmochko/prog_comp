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
        vector<ii> a(n);
        fore(i,0,n){
            cin >> a[i].fst;
            a[i].fst--; // le bajo uno la cadena de mando
            a[i].snd = i;
        }
        sort(ALL(a));
        reverse(ALL(a));
        vector<ii> res;
        bool prt = true;
        fore(i,0,n){
            // me fijo si al prog i le puedo asignar su valor necesario
            ll counter = 0;
            dfore(j,n-1,i+1){
                if(counter == a[i].fst){ // significa que ya guarde todos los necesarios
                    break;
                }
                ll aa = a[i].snd + 1;
                ll bb = a[j].snd + 1;
                res.pb({aa,bb});
                counter++;
            }
            if(counter != a[i].fst){
                cout << "-1\n";
                prt = false;
                break;
            }
        }
        if(prt){
            assert(SZ(res)<1000000);
            cout << SZ(res) << "\n";
            for(auto p : res){
                cout << p.fst << " " << p.snd << "\n";
            }
        }
    }
}