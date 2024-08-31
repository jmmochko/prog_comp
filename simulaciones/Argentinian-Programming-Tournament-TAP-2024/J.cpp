#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(a,b,c) for(int a=b; a<c; ++a)
#define all(a) a.begin(),a.end()
#define SZ(a) (int)a.size()
#define show(a) cout<<a<<'\n'
#define showAll(a) for(auto b: a)cout<<b<<" ";cout<<'\n'
#define pb push_back
typedef long long ll;
using namespace std;

void solve(){
    int n;
    ll x;
    cin>>n>>x;
    vector<ll> res;
    multiset<ll> mas,men;
    fore(i,0,n){
        ll e;
        cin>>e;
        if(e<x)men.insert(e);
        else mas.insert(e);
    }
    if(!SZ(men)){
        showAll(mas);
        return;
    }
    
    int cnteq = men.count(x/2);

    if(cnteq-1>SZ(mas)+(SZ(men)-cnteq)+1 && !(x&1)){
        show('*');
        return;
    }

    if(cnteq==1 && !(x&1)){
        for(auto e: men)cout<<e<<" ";
        showAll(mas);
        return;
    }

    if(cnteq>1 && !(x&1)){
        //tengo que meter cnteqe -1 valores
        // voy a ir intercalando x/2 primero en la fila
        // y voy a dejar 1 para imprimir todo en orden

        vector<ll> res,menores,mayores;
        for(auto e: men){
            menores.push_back(e);
        }
        for(auto e: mas){
            mayores.push_back(e);
        }
        int i=0,j = 0;
        res.pb(x/2);
        fore(h,0,cnteq-2){
            if(!(i + cnteq > SZ(men))){
                //pongo los que van en orden
                res.pb(menores[i]);
                i++;
            } else if(j > SZ(mayores)){
                res.pb(mayores[j]);
                j++;
            } else{
                show('*');
                return;
            }
            res.pb(x/2);
        }

        fore(h,i,SZ(menores)){
            if(menores[h]==x/2){
                if(cnteq==0) res.push_back(menores[h]);
                else cnteq--;
            } else res.pb(menores[h]);
        }

        fore(h,j,SZ(mayores))res.push_back(mayores[h]);
        res.pb(x/2);
        showAll(res);
        return;
    }

    //veo si se rompe



}

int main(){
    solve();
    return 0;
}