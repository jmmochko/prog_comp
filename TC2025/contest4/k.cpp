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
const ll INF = 100000000;

int main(){
    FIN;
    ll n; cin >> n;
    vector<ll> a(n);
    fore(i,0,n){
        string s;
        ll t1,t2,t3;
        cin >> s >> t1 >> t2 >> t3;
        if(t1 == -1) t1 = INF;
        if(t2 == -1) t2 = INF;
        if (t3 == -1) t3 = INF;
        a[i] = min(t1,min(t2,t3));
        // cout << s << " min " << a[i] << "\n";   
    }
    sort(all(a));
    // fore(i,0,n) cout << a[i] << "\n";
    ll res = 0;
    ll cont = 0;
    fore(i,0,n){
        if(cont + a[i] <= 300){
            cont += a[i];
            res++;
        } else{
            break;
        }
    }
    cout << res << "\n";
}