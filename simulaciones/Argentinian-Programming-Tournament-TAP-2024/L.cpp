#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(a,b,c) for(int a=b; a<c; ++a)
#define all(a) a.begin(),a.end()
#define SZ(a) (int)a.size()
#define show(a) cout<<a<<'\n'
#define showAll(a) for(auto b: a)cout<<b<<" ";cout<<'\n'
#define MAXN 1000001
typedef long long ll;
using namespace std;

bool espot(int x){
    // cout<<__builtin_ctz(x)<< " " << __builtin_clz(x)<<'\n';
    return __builtin_ctz(x) + __builtin_clz(x) == 31;
}

int main(){
    FIN;
    int aux,n,q; cin>>n>>q;
    vector<int> pot,imp,unos;
    unos.push_back(0);
    pot.push_back(0);
    imp.push_back(0);
    fore(i,1,n+1){
        cin>>aux;
        if(aux==1){
            unos.push_back(unos[i-1]+1);
            pot.push_back(pot[i-1]);
            imp.push_back(imp[i-1]);
        }else{
            unos.push_back(unos[i-1]);
            if(espot(aux)) pot.push_back(pot[i-1]+aux);
            else pot.push_back(pot[i-1]);
            if(aux%2 == 1) imp.push_back(imp[i-1]+aux);
            else imp.push_back(imp[i-1]);

        }
    }

    fore(i,0,q){
        int a,b; cin>>a>>b;
        int c = (unos[b]-unos[a-1])%2;
        if(pot[b]-pot[a-1]+c > imp[b]-imp[a-1]){
            show("A");
        }else if(pot[b]-pot[a-1]+c < imp[b]-imp[a-1]){
            show("B");
        }else show("E");
    }

    return 0;
}