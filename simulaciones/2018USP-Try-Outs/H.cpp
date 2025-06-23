#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define fore(a,b,c) for(int a=b; a<c; ++a)
#define dfore(a,b,c) for(int a=b; a>=c; --a)
#define SZ(a) ((int)a.size())
#define fst first
#define snd second
#define show(a) cout<<a<<"\n"
#define showAll(a) for(auto i:a) cout<<i<<" ";cout<<"\n"
#define input(a) for(auto& i:a) cin>>i
#define all(a) a.begin(),a.end()
#define DGB(a) cout<<#a<<" = "<<a<<"\n"
#define RAYA cout<<"=============="<<"\n"
#define pii pair<int,int>
#define pll pair<ll,ll>
#define MAXN 200005
#define ALPH 26
#define M 1000000007
#define MAXINT (1<<30)
#define MAXll (1ll<<60)
#define PI 3.141592653
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

//El Vasito is love, El Vasito is life

ll block;

bool comapre(pair<pll,ll> x, pair<pll,ll> y){
    // Different blocks, sort by block.
    if (x.fst.fst / block != y.fst.fst / block)
        return x.fst.fst / block < y.fst.fst / block;

    // Same block, sort by R value
    return x.fst.snd < y.fst.snd;
}

int main(){
    FIN;
    ll n, q; cin >> n >> q;
    vector<ll> a(n);
    fore(i,0,n) cin >> a[i];
    vector<pair<pll,ll>> querys(q);
    fore(i,0,q){ 
        cin >> querys[i].fst.fst >> querys[i].fst.snd;
        querys[i].fst.fst--;
        querys[i].fst.snd--;
        // querys[i].fst.snd--;
        querys[i].snd = i;
    }
    block = (ll)sqrt(n);
    sort(all(querys),comapre);
    
    set<int> comprimir;
    fore(i,0,n)comprimir.insert(a[i]);
    map<int,int> compresion;
    int cnt = 0;
    for(auto e: comprimir){
        compresion[e] = cnt;
        ++cnt;
    }

    fore(i,0,n)a[i] = compresion[a[i]];

    vector<int> res(q),suman(n+2,0),tengo(n+2,0);// suman = cuantos numeros hay que se repiten x veces, tengo = cuantos tengo de este numero
    int l=0,r=-1,rta=0;

    fore(_,0,q){
        //voy al rango de la query
        int nl = querys[_].fst.fst, nr = querys[_].fst.snd;
        while(r<nr){//aumento el rango hasta nr
            ++r;
            tengo[a[r]]++;
            int nueva_posible = rta + 1;
            suman[tengo[a[r]]]++;
            if(suman[nueva_posible]>=nueva_posible)rta = nueva_posible;
        }
        while(r>nr){//disminuyo el rango hasta nr
            tengo[a[r]]--;
            int nueva_posible = rta - 1;
            suman[tengo[a[r]] + 1]--;
            if(rta==nueva_posible+1 && suman[nueva_posible+1]<nueva_posible+1)rta = nueva_posible;
            --r;
        }
        while(l>nl){//disminuyo el rango hasta nl
            --l;
            tengo[a[l]]++;
            int nueva_posible = rta + 1;
            suman[tengo[a[l]]]++;
            if(suman[nueva_posible]>=nueva_posible)rta = nueva_posible;
        }
        while(l<nl){//aumento el rango hasta nl
            tengo[a[l]]--;
            int nueva_posible = rta - 1;
            suman[tengo[a[l]] + 1]--;
            if(rta==nueva_posible+1 && suman[nueva_posible+1]<nueva_posible+1)rta = nueva_posible;
            ++l;
        }
        res[querys[_].snd] = max(rta,0);
    }
    fore(i,0,q){
        show(res[i]);
    }
    return 0;
}