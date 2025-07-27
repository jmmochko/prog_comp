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
    ll t; cin >> t;
    string dir = "NESW";//right from i me lleva a i + 1
    while(t--){
        ll n; cin >> n;
        vector<char> d(n);
        vector<int> ls(n);
        fore(i,0,n){
            cin>>d[i]>>ls[i];
        }
        int estoy = 0;
        fore(i,0,4)if(dir[i] == d[0])estoy = i;
        vector<pair<char,int>> res;
        res.pb({'Z',ls[0]});
        fore(i,1,n){
            if(dir[(estoy+1)%4] == d[i]){
                res.pb({'R',-1});
                estoy = (estoy + 1) % 4;
            }
            else {res.pb({'L',-1});estoy = estoy - 1; if(estoy==-1)estoy = 3;}
            res.pb({'Z',ls[i]});
        }
        cout<<SZ(res)<<" "<<d[0]<<'\n';
        fore(i,0,SZ(res)){
            cout<<res[i].fst<<" ";
            if(res[i].fst == 'Z')cout<<res[i].snd;
            cout<<'\n';
        }
    }
}