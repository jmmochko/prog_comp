#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ThxDem=b;i<ThxDem;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) ll(s.size())
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;


int main(){
    FIN;
    ifstream cin("holes.in");
    ofstream cout("holes.out");

    int h; cin >> h;
    if(h==0){
        cout << 1 << "\n";
    } else if(h==1){
        cout << 0 << "\n";
    } else{
        if(h%2!=0){
            cout << 4;
            h--;
        }
        int cant8 = h/2;
        while(cant8--){
            cout << 8;
        }
        cout << "\n";
    }

    cin.close();
    cout.close();

}