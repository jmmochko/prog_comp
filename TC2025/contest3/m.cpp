#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(a,b,c) for(int a=b;a<c;++a)
#define SZ(a) ((int)a.size())
#define fst first 
#define snd second
#define all(a) a.begin(),a.end()

using namespace std;
typedef long long ll;

int main(){
    FIN;
    ll a,b,m,r0;
    cin >> a >> b >> m >> r0;
    ll r = r0;
    ll res = 0;
    set<ll> val;
    val.insert(r0);
    while(1){
        r = ((a*r) + b) % m;
        // cout << r << "/n";
        if(val.count(r)){
            // encontre el inicio de mi secuencia
            set<ll> seq;
            seq.insert(r);
            while (1){
                res++;
                r = ((a*r) + b) % m;
                if(seq.count(r)) break;
                seq.insert(r);
            }
            break;
            
        }
        val.insert(r);
    }
    cout << res << "\n";
}