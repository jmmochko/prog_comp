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
    // FIN;
    ll t; cin >> t;
    while(t--){
        string s; cin >> s;
        if(s == "ROUND"){
            ll m,b; cin >> m >> b;
            if((3*b) >= m){
                cout << "SKIP\n";
                cout.flush();
            } else{
                cout << "PLAY\n";
                cout.flush();
            }
        } else{
            break;
        }
    }
    return 0;
}