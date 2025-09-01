#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(a,b,c) for(int a=b;a<c;++a)
#define SZ(a) ((int)a.size())
#define fst first
#define snd second
#define all(a) a.begin(),a.end()
#define pb push_back
using namespace std;
typedef long long ll;

int main(){
    FIN;
    ll n,m; cin >> n >> m;
    vector<ll> a(n,0);
    ll res = 0;
    fore(i,0,m){
        ll o1,o2; cin >> o1 >> o2;
        ll c1 = 0, c2 = 0;
        vector<ll> b(n);
        fore(i,0,n){
            ll x; cin >> x;
            if(x==1) c1++;
            else c2++;
            b[i] = x;
        }
        if(o2 > o1/(c1+1)){
            res += o2;
            fore(i,0,n){
                if(b[i]==1){
                    a[i]+= o1/c1;
                } else{
                    a[i] += o2;
                }
            }
        } else{
            res += o1/(c1+1);
            fore(i,0,n){
                if(b[i]==1){
                    a[i]+= o1/(c1+1);
                } else{
                    a[i] += o2;
                }
            }
        }
    }
    fore(i,0,n) cout << a[i] << " ";
    cout << res << "\n";
    return 0;
}