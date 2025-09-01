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
    ll n;
    cin >> n;
    ll minx = 1e10, miny = 1e10;
    ll maxx = -1, maxy = -1;

    fore(i,0,n){
        ll x,y; cin >> x >> y;
        minx = min(minx,x);
        maxx = max(maxx,x);
        miny = min(miny,y);
        maxy = max(maxy,y);
    }
    miny--;minx--;maxx++;maxy++;
    ll res = 2*(maxx - minx) + 2*(maxy - miny);
    cout << res << "\n"; 
    return 0;
}