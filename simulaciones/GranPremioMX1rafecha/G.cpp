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

        if(a[0]==1){
            ll count = 1;
            ll n_aux = n;
            fore(i,0,n-1){
                if(a[i] + 1 == a[i+1]){
                count++;
                }
                else if(a[i] != a[i+1]) break;
                else n_aux--;
            }
            if(count%2 == 0 && count-n_aux!=0){
                show("Alicius"); // 1 2 x ..... y
            } else if (count % 2 == 0){
                show("Bobius"); // 1 2
            } else if(count - n_aux != 0){
                show("Bobius"); // 1 2 3 x .... y 
            } else{
                show("Alicius"); // 1 2 3
            }

        } else{
            show("Alicius");
        }
    }
}
