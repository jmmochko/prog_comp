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
    int t;
    cin>>t;
    vector<vector<ll>> a(t),b(t);
    map<ll,int> as,bs;
    fore(i,0,t){
        int n;
        cin>>n;
        fore(_,0,n){
            ll e;
            cin>>e;
            a[i].pb(e);
            as[e]++;
        }
    }
    fore(i,0,t){
        int n;
        cin>>n;
        fore(_,0,n){
            ll e;
            cin>>e;
            b[i].pb(e);
            bs[e]++;
        }
    }
    for(auto e: as){
        bs[e.fst]++;
        bs[e.fst]--;
        if(bs[e.fst] != e.snd){
            cout<<"N\n";
            return 0;
        }
    }
    for(auto e: bs){
        as[e.fst]++;
        as[e.fst]--;
        if(as[e.fst] != e.snd){
            cout<<"N\n";
            return 0;
        }
    }
    if(t>=3){
        cout<<"S\n";
        return 0;
    }
    if(t==1){
        fore(i,0,SZ(a[0]))if(a[0][i] != b[0][i]){cout<<"N\n";return 0;}
        cout<<"S\n";
        return 0;
    }
    ll muevo;
    if(SZ(a[0])==0 && SZ(a[1]) == 0){
        cout<<"S\n";
        return 0;
    }
    else if(SZ(a[0]) == 0){
        muevo = a[1][SZ(a[1])-1];
    }
    else if(SZ(a[1]) == 0){
        muevo = a[0][SZ(a[0])-1];
    }
    else muevo = min(a[0][SZ(a[0])-1], a[1][SZ(a[1])-1]);
    int i = 0;
    while(i<min(SZ(b[0]),SZ(a[0]))){
        if(a[0][i] != b[0][i]){
            cout<<"N\n";return 0;
        }
        ++i;
    }
    i = 0;
    while(i<min(SZ(b[1]),SZ(a[1]))){
        if(a[1][i] != b[1][i]){
            cout<<"N\n";return 0;
        }
        ++i;
    }
    if(SZ(a[0]) > SZ(b[0]) && a[0][SZ(b[0])] != muevo){
        cout<<"N\n";return 0;
    }
    if(SZ(a[1]) > SZ(b[1]) && a[1][SZ(b[1])] != muevo){
        cout<<"N\n";return 0;
    }
    cout<<"S\n";
    return 0;
}