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
    cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<double> a(n);
        fore(i,0,n){
            cin >> a[i];
        }
        sort(ALL(a));
        reverse(ALL(a));
        double min_area = 100000000000;
        fore(i,0,n-2){
            fore(j,i+1,n-1){

                double x = (a[i] - a[j]); // cota que quiero buscar
                ll l = j+1, r = n;
                while(l + 1 < r){
                    ll m = (l+r)/2;
                    if(a[m] > x){
                        l = m;
                    } else{
                        r = m;
                    }
                }
                if(l>=n) continue;
                double k = a[l];
                if(a[i] > a[j] + k) continue;
                double s = double((double(a[i]) + double(a[j]) + k)/double(2));
                s = sqrt(s*(s-a[i])*(s-a[j])*(s-k));
                min_area = min(min_area,s);
            }
        }
        if(min_area == 100000000000){
            cout << "-1\n";
        } else{
            cout << min_area << setprecision(10) << fixed << "\n";
        }
    }
}
